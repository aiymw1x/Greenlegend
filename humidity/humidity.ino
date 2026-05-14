#include <SoftwareSerial.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
int sensor = A1; // Аналоговый пин для датчика влажности
int photo = A0;
int x=0;
SoftwareSerial bluetooth(10, 11); // TX, RX

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(photo, INPUT);
  // Инициализация последовательной связи для вывода данных
  if (tcs.begin()) {
    Serial.println("Датчик найден!"); // Если модуль найден, вывод сообщения
  } else {
    Serial.println("Датчик TCS34725 не найден ... проверьте соединение"); // Если модуль не найден, вывод сообщения и остановка работы
    while (1);
  }
}

void loop() {

  int vphoto=analogRead(photo); //Serial.println(vphoto);
  if (vphoto>900)
  {
  uint16_t r, g, b, c, colorTemp, lux;
  // Получение данных о цвете с модуля
  tcs.getRawData(&r, &g, &b, &c);
  // Расчет температуры цвета и уровня освещенности
  colorTemp = tcs.calculateColorTemperature(r, g, b);
  lux = tcs.calculateLux(r, g, b);
  int vsensor = analogRead(sensor);
  //Serial.println(colorTemp);
  if (vsensor < 70 && colorTemp < 4000) {
   x=1;
  }
  else if (vsensor > 70 && vsensor < 100 && colorTemp < 4000) {
  x=2;
  }
  else if (vsensor > 100 && colorTemp < 4000) {
x=3;
  }
  else if (vsensor < 70 && colorTemp > 4500) {
   x=4;
  }
  else if (vsensor > 70 && vsensor < 100 && colorTemp > 4500) {
   x=5;
  }
  else if (vsensor > 100 && colorTemp > 4500) {
x=6;
  }
  
  //bluetooth.println(vsensor);
  //Serial.println(vsensor);
  bluetooth.println(x);
  Serial.println(x);
  delay(2000); // Задержка в 2 секунды перед следующим чтением
}
}

