#include <Servo.h> 
Servo servoPodiem; 

int Mplatform1=22; int Mplatform2=23; int MplatformSpeed=2;
int Mmanipulator1=28; int Mmanipulator2=29; int MmanipulatorSpeed=5; int up=1; int down=1; 
int Mzahvat1=24; int Mzahvat2=25; int MzahvatSpeed=3; 
int Mconveer1=26; int Mconveer2=27; int MconveerSpeed=4; 

int Bplatformright=32; int VBplatformright=0; 
int Bplatformleft=40; int VBplatformleft=0; 
int Bzahvatopen=34; int VBzahvatopen=0; 
int Bzahvatclose=36; int VBzahvatclose=0; 
int Bzahvattouch=30; int VBzahvattouch=0;

int Lplatforma=31; int Fplatform=0; int VFplatform=0; 
int Pmanipulator=1; int VPmanipulator=0;
int opta_connect=52;
//=============================================================================================
void setup() {
Serial.begin (9600);
servoPodiem.attach(9); 
pinMode(Mplatform1, OUTPUT); pinMode(Mplatform2, OUTPUT); pinMode(MplatformSpeed, OUTPUT);
pinMode(Mmanipulator1, OUTPUT); pinMode(Mmanipulator2, OUTPUT); pinMode(MmanipulatorSpeed, OUTPUT);
pinMode(Mzahvat1, OUTPUT); pinMode(Mzahvat2, OUTPUT); pinMode(MzahvatSpeed, OUTPUT);
pinMode(Mconveer1, OUTPUT); pinMode(Mconveer2, OUTPUT); pinMode(MconveerSpeed, OUTPUT);
pinMode(Bplatformright, INPUT); digitalWrite(Bplatformright, HIGH);
pinMode(Bplatformleft, INPUT); digitalWrite(Bplatformleft, HIGH);
pinMode(Bzahvatopen, INPUT); digitalWrite(Bzahvatopen, HIGH);
pinMode(Bzahvatclose, INPUT); digitalWrite(Bzahvatclose, HIGH);
pinMode(Bzahvattouch, INPUT); digitalWrite(Bzahvattouch, HIGH);
pinMode(Lplatforma, OUTPUT);
pinMode(opta_connect, OUTPUT);

}
//*********************************************************************************************
void loop() 
{
 zahvat_open(); 
     servoPodiem.write(50); delay(1500); 
     manipulator_goes_down(); 
     manipulator_movement_to_right(); 
     manipulator_movement_to_right(); 
     servoPodiem.write(145); delay(1500); 
     zahvat_close(); 
     servoPodiem.write(50); delay(1500); 
     manipulator_goes_reset();
     manipulator_movement_to_right(); 
     servoPodiem.write(145); delay(1500); 
     zahvat_open();
     conveer(); 
     servoPodiem.write(50); delay(1500);
     parcing();
     manipulator_rises_up(); 
/*
     zahvat_open(); 
     servoPodiem.write(50); delay(1500); 
     manipulator_goes_down(); 
     manipulator_movement_to_right(); 
     manipulator_movement_to_right(); 
     servoPodiem.write(145); delay(1500); 
     zahvat_close(); 
     servoPodiem.write(50); delay(1500); 
     manipulator_goes_reset();
     manipulator_movement_to_right(); 
     servoPodiem.write(145); delay(1500); 
     zahvat_open();
     conveer(); 
     servoPodiem.write(50); delay(1500);
     parcing();
     manipulator_rises_up(); 
  /*
     servoPodiem.write(50); delay(1500); 
     manipulator_goes_down(); 
     manipulator_movement_to_right();
     servoPodiem.write(145); delay(1500); 
     zahvat_close();
     servoPodiem.write(50); delay(1500); 
     manipulator_goes_reset(); 
     manipulator_movement_to_right(); 
     manipulator_movement_to_right();
     servoPodiem.write(145); delay(1500); 
     zahvat_open(); 
     conveer(); 
     servoPodiem.write(50); delay(1500);
     parcing(); 
     manipulator_rises_up(); */

  /*
     zahvat_open(); 
     servoPodiem.write(50); delay(1500); 
     manipulator_goes_down(); 
     manipulator_movement_to_right(); 
     manipulator_movement_to_right(); 
     servoPodiem.write(145); delay(1500); 
     */
     /*
     zahvat_close(); 
     servoPodiem.write(50); delay(1500); 
     manipulator_goes_reset();
     manipulator_movement_to_right(); 
     servoPodiem.write(145); delay(1500); 
     zahvat_open();
     conveer(); 
     servoPodiem.write(50); delay(1500);
     parcing();
     manipulator_rises_up(); */
     
 /*parcing(); 
 manipulator_rises_up(); 
 servoPodiem.write(50); delay(1500);
 */
 
 if (Serial.available() > 0) {

   
    char incomingByte = Serial.read();
    
    if (incomingByte == '1') 
    {
     zahvat_open(); 
     servoPodiem.write(50); delay(1500); 
     manipulator_goes_down(); 
     manipulator_movement_to_right();
     servoPodiem.write(145); delay(1500); 
     zahvat_close();
     servoPodiem.write(50); delay(1500); 
     manipulator_goes_reset(); 
     manipulator_movement_to_right(); 
     manipulator_movement_to_right();
     servoPodiem.write(145); delay(1500); 
     zahvat_open(); 
     conveer(); 
     servoPodiem.write(50); delay(1500);
     manipulator_rises_up(); 
     parcing(); 
     
    } 
    else if (incomingByte == '2') 
    {
     zahvat_open(); 
     servoPodiem.write(50); delay(1500); 
     manipulator_goes_down(); 
     manipulator_movement_to_right(); 
     manipulator_movement_to_right(); 
     servoPodiem.write(145); delay(1500); 
     zahvat_close(); 
     servoPodiem.write(50); delay(1500); 
     manipulator_goes_reset();
     manipulator_movement_to_right(); 
     servoPodiem.write(145); delay(1500); 
     zahvat_open();
     conveer(); 
     servoPodiem.write(50); delay(1500);
     manipulator_rises_up(); 
     parcing();
    } 
    else if (incomingByte == '3') 
    {
     zahvat_open(); 
     servoPodiem.write(50); delay(1500); 
     manipulator_goes_down(); 
     manipulator_movement_to_right(); 
     manipulator_movement_to_right(); 
     manipulator_movement_to_right(); 
     servoPodiem.write(145); delay(1500); 
     zahvat_close(); 
     servoPodiem.write(50); delay(1500);
     manipulator_movement_to_left();
     manipulator_goes_reset();
     manipulator_movement_to_right(); 
     servoPodiem.write(145); delay(1500); 
     zahvat_open(); 
     conveer(); 
     servoPodiem.write(50); delay(1500); 
     manipulator_rises_up(); 
     parcing(); 
     manipulator_movement_to_left();
    }
    else if (incomingByte == '4') 
    {
     zahvat_open(); 
     servoPodiem.write(50); delay(1500);
     manipulator_goes_down(); 
     manipulator_movement_to_right(); 
     manipulator_movement_to_right(); 
     manipulator_movement_to_right();
     manipulator_movement_to_right(); 
     servoPodiem.write(145); delay(1500); 
     zahvat_close(); 
     servoPodiem.write(50); delay(1500); 
     manipulator_movement_to_left(); 
     manipulator_movement_to_left(); 
     manipulator_goes_reset(); 
     manipulator_movement_to_right();
     servoPodiem.write(145); delay(1500); 
     zahvat_open(); 
     conveer(); 
     servoPodiem.write(50); delay(1500); 
     manipulator_rises_up();
     parcing(); 
    }
  }
  
}
/*
servoPodiem.write(50); delay(1500); 
servoPodiem.write(145); delay(1500); 
manipulator_goes_reset(); 
manipulator_goes_down();
manipulator_rises_up(); 
zahvat_close(); 
zahvat_open(); 
conveer();
parcing();
manipulator_movement_to_right(); 
manipulator_movement_to_left();
Optapara_connect(); 
*/
//----------------------------------------------------------------------------------------------
void Optapara_connect() 
{digitalWrite(opta_connect, 1); delay(300); digitalWrite(opta_connect, 0);}
//----------------------------------------------------------------------------------------------
void manipulator_goes_reset() 
{
VPmanipulator=analogRead(Pmanipulator); Serial.println(VPmanipulator);  
while(VPmanipulator>295)
{VPmanipulator=analogRead(Pmanipulator); digitalWrite(Mmanipulator1, 1); digitalWrite(Mmanipulator2, 0);  analogWrite(MmanipulatorSpeed, 255);}
digitalWrite(Mmanipulator1, 0); digitalWrite(Mmanipulator2, 0);  analogWrite(MmanipulatorSpeed, 0);}
//----------------------------------------------------------------------------------------------
void manipulator_goes_down() 
{
VPmanipulator=analogRead(Pmanipulator); //Serial.println(VPmanipulator);  
while(VPmanipulator<838)
{VPmanipulator=analogRead(Pmanipulator); digitalWrite(Mmanipulator1, 0); digitalWrite(Mmanipulator2, 1);  analogWrite(MmanipulatorSpeed, 255);}
digitalWrite(Mmanipulator1, 0); digitalWrite(Mmanipulator2, 0);  analogWrite(MmanipulatorSpeed, 0);}
//----------------------------------------------------------------------------------------------
void manipulator_rises_up() 
{
VPmanipulator=analogRead(Pmanipulator); //Serial.println(VPmanipulator);  
while(VPmanipulator>130)
{VPmanipulator=analogRead(Pmanipulator); digitalWrite(Mmanipulator1, 1); digitalWrite(Mmanipulator2, 0);  analogWrite(MmanipulatorSpeed, 255);}
digitalWrite(Mmanipulator1, 0); digitalWrite(Mmanipulator2, 0);  analogWrite(MmanipulatorSpeed, 0);}
//----------------------------------------------------------------------------------------------
void zahvat_close()
{
digitalWrite(Mzahvat1, 0); digitalWrite(Mzahvat2, 1);  analogWrite(MzahvatSpeed, 150);
delay(5000);
digitalWrite(Mzahvat1, 0); digitalWrite(Mzahvat2, 0);  analogWrite(MzahvatSpeed, 0);}
//----------------------------------------------------------------------------------------------
void zahvat_open() 
{
VBzahvatopen=digitalRead(Bzahvatopen); //Serial.println(VBzahvatopen);  
while(VBzahvatopen==0)
{VBzahvatopen=digitalRead(Bzahvatopen); digitalWrite(Mzahvat1, 1); digitalWrite(Mzahvat2, 0);  analogWrite(MzahvatSpeed, 255);}
digitalWrite(Mzahvat1, 0); digitalWrite(Mzahvat2, 0);  analogWrite(MzahvatSpeed, 0);}
//----------------------------------------------------------------------------------------------
void conveer()//конвеер
{digitalWrite(Mconveer1, 1); digitalWrite(Mconveer2, 0);  analogWrite(MconveerSpeed, 255); delay(5000);
digitalWrite(Mconveer1, 0); digitalWrite(Mconveer2, 0);  analogWrite(MconveerSpeed, 0); }
//----------------------------------------------------------------------------------------------
void parcing() 
{
VBplatformleft=digitalRead(Bplatformleft); //Serial.println(VBplatformleft);  
while(VBplatformleft==0)
{VBplatformleft=digitalRead(Bplatformleft); digitalWrite(Mplatform1, 1); digitalWrite(Mplatform2, 0);  analogWrite(MplatformSpeed, 255);}
digitalWrite(Mplatform1, 0); digitalWrite(Mplatform2, 0);  analogWrite(MplatformSpeed, 0);}
//----------------------------------------------------------------------------------------------
void manipulator_movement_to_right() 
{
digitalWrite(Mplatform1, 0); digitalWrite(Mplatform2, 1);  analogWrite(MplatformSpeed, 250); delay(500);
digitalWrite(Lplatforma, 1);
VFplatform=analogRead(Fplatform); //Serial.println(VFplatform);  
while(VFplatform<850)
{VFplatform=analogRead(Fplatform); digitalWrite(Mplatform1, 0); digitalWrite(Mplatform2, 1);  analogWrite(MplatformSpeed, 255);}
digitalWrite(Mplatform1, 0); digitalWrite(Mplatform2, 0);  analogWrite(MplatformSpeed, 0); digitalWrite(Lplatforma, 0);digitalWrite(Lplatforma, 0);}
//----------------------------------------------------------------------------------------------
void manipulator_movement_to_left() 
{
digitalWrite(Mplatform1, 1); digitalWrite(Mplatform2, 0);  analogWrite(MplatformSpeed, 250); delay(500);
digitalWrite(Lplatforma, 1);
VFplatform=analogRead(Fplatform); //Serial.println(VFplatform);  
while(VFplatform<850)
{VFplatform=analogRead(Fplatform); digitalWrite(Mplatform1, 1); digitalWrite(Mplatform2, 0);  analogWrite(MplatformSpeed, 255);}
digitalWrite(Mplatform1, 0); digitalWrite(Mplatform2, 0);  analogWrite(MplatformSpeed, 0); digitalWrite(Lplatforma, 0);digitalWrite(Lplatforma, 0);}
