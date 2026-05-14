int MdriveL1=11; int MdriveL2=12; int MdriveR1=3; int MdriveR2=4; 
int Mplatform1=33; int Mplatform2=35; int MplatformSpeed=45;
int Mbur1=8; int Mbur2=7; 
int Mlift1=9; int Mlift2=10; 
int Mpipe1=44; int Mpipe2=46; 
int MBobbin1=5; int MBobbin2=6; 
int Mdavilka1=29; int Mdavilka2=31; int MdavilkaSpeed=2;
int Msensor1=37; int Msensor2=39; 

int Bleftposition=22; int VBleftposition=0;
int Brightposition=23; int VBrightposition=0; 
int BliftNiz=26; int VBliftNiz=0; 
int BliftVerh=24; int VBliftVerh=0; 
int BpipeNiz=32;  int VBpipeNiz=0;
int BpipeVerh=34;   int VBpipeVerh=0; 
int Bsensor=40; int VBsensor=0; 

int Ltree=28; int Ftree=0; int VFtree=0; 
int Lposition=30; int Fposition=1; int VFposition=0; 
int Ldavilka=36; int Fdavilka=2; int VFdavilka=0; 
int Opta_connect=38; 
int Fopta_connect=3; int VFopta_connect=0; 
int x=1;
//=============================================================================================
void setup() {
Serial.begin (9600);
pinMode(MdriveL1, OUTPUT); pinMode(MdriveL2, OUTPUT); pinMode(MdriveR1, OUTPUT); pinMode(MdriveR2, OUTPUT); 
pinMode(Mbur1, OUTPUT); pinMode(Mbur2, OUTPUT);
pinMode(MBobbin1, OUTPUT); pinMode(MBobbin2, OUTPUT);
pinMode(Mpipe1, OUTPUT); pinMode(Mpipe2, OUTPUT);
pinMode(Mplatform1, OUTPUT); pinMode(Mplatform2, OUTPUT); pinMode(MplatformSpeed, OUTPUT);
pinMode(Mdavilka1, OUTPUT); pinMode(Mdavilka2, OUTPUT); pinMode(MdavilkaSpeed, OUTPUT);
pinMode(Mlift1, OUTPUT); pinMode(Mlift2, OUTPUT);
pinMode(Msensor1, OUTPUT); pinMode(Msensor2, OUTPUT);
pinMode(BliftNiz, INPUT); digitalWrite(BliftNiz, HIGH); pinMode(BliftVerh, INPUT); digitalWrite(BliftVerh, HIGH);
pinMode(Bleftposition, INPUT); digitalWrite(Bleftposition, HIGH); pinMode(Brightposition, INPUT); digitalWrite(Brightposition, HIGH);
pinMode(BpipeNiz, INPUT); digitalWrite(BpipeNiz, HIGH); pinMode(BpipeVerh, INPUT); digitalWrite(BpipeVerh, HIGH);
pinMode(Bsensor, INPUT); digitalWrite(Bsensor, HIGH);
pinMode(Ltree, OUTPUT); pinMode(Lposition, OUTPUT); pinMode(Ldavilka, OUTPUT);
pinMode(Opta_connect, OUTPUT);
}
//*********************************************************************************************
void loop() 
{
//platform_movement_to_right();
 //raising_drill(); 
 //optapara_connect();
 //opyskanie_sensora(); 
 //moving_pipe_down();
 //moving_pipe_up();
 //forvard_robot();
 //VBpipeNiz=digitalRead(BpipeNiz);
 //Serial.println(VBpipeVerh);
 
 digitalWrite(Opta_connect, 1);
 drilling(); 
 raising_drill(); 
 platform_movement_to_left();
  digitalWrite(Ltree, 1); 
 moving_pipe_down(); 
 namotka_lenty(); 
 moving_pipe_up(); 
 pozisiy_zasupca_zemliy(); 
 platform_movement_to_right(); 
 //delay(50000);
 stop_robot();
 delay(500000);
}
/*
while (x==1)
{
  if (Fopta_connect>500)
  {
    stop_robot();
  }
  else
  {

if (Serial.available() >= 0) 
{
    char incomingByte = Serial.read();
    
    if (incomingByte == '1') 
    {
     right_robot();
    } 
    else if (incomingByte == '2') 
    {
     right_robot();
    } 
    else if (incomingByte == '3') 
    {
    left_robot();
    }
    else if (incomingByte == '4') 
    {
    left_robot();
    }
    else if (incomingByte == '0') 
    {
    stop_robot();
    }
  }
  }
}

}

/*
stop_robot(); //drilling();
forvard_robot(); 
raising_drill(); 
drilling(); 
platform_movement_to_left(); 
platform_movement_to_right();
pozisiy_zasupca_zemliy();
moving_pipe_down();
moving_pipe_up();
namotka_lenty(); 
opyskanie_sensora();
podnytie_sensora(); 
optapara_connect();
opyskanie_davilki();  
podnimanie_davilki();  
*/
//----------------------------------------------------------------------------------------------?????????
void opyskanie_davilki()  
{digitalWrite(Ldavilka, 1);
digitalWrite(Mdavilka1, 1); digitalWrite(Mdavilka2, 0);  analogWrite(MdavilkaSpeed, 255); delay(1000);
VFdavilka=analogRead(Fdavilka); //Serial.println(VFdavilka);
while(VFdavilka<500)
{VFdavilka=analogRead(Fdavilka);
digitalWrite(Mdavilka1, 1); digitalWrite(Mdavilka2, 0);  analogWrite(MdavilkaSpeed, 255);}
digitalWrite(Mdavilka1, 0); digitalWrite(Mdavilka2, 0); analogWrite(MdavilkaSpeed, 0); digitalWrite(Ldavilka, 0);}
//----------------------------------------------------------------------------------------------?????????
void podnimanie_davilki()  
{digitalWrite(Ldavilka, 1);
digitalWrite(Mdavilka1, 0); digitalWrite(Mdavilka2, 1);  analogWrite(MdavilkaSpeed, 255); delay(1000);
VFdavilka=analogRead(Fdavilka); //Serial.println(VFdavilka);
while(VFdavilka<500)
{VFdavilka=analogRead(Fdavilka); digitalWrite(Mdavilka1, 0); digitalWrite(Mdavilka2, 1);  analogWrite(MdavilkaSpeed, 255);}
digitalWrite(Mdavilka1, 0); digitalWrite(Mdavilka2, 0);  analogWrite(MdavilkaSpeed, 0); digitalWrite(Ldavilka, 0); }
//----------------------------------------------------------------------------------------------
void optapara_connect() 
{digitalWrite(Opta_connect, 1); delay(200); digitalWrite(Opta_connect, 0);}
//----------------------------------------------------------------------------------------------
void opyskanie_sensora() 
{digitalWrite(Msensor1, 0);  digitalWrite(Msensor2, 1); delay(40000);
digitalWrite(Msensor1, 0);  digitalWrite(Msensor2, 0);}
//----------------------------------------------------------------------------------------------
void podnytie_sensora() 
{VBsensor=digitalRead(Bsensor); //Serial.println(VBsensor);
while(VBsensor==0)
{VBsensor=digitalRead(Bsensor);
digitalWrite(Msensor1, 1);  digitalWrite(Msensor2, 0);}
digitalWrite(Msensor1, 0);  digitalWrite(Msensor2, 0);}
//----------------------------------------------------------------------------------------------
void namotka_lenty() 
{digitalWrite(Ltree, 1); VFtree=analogRead(Ftree); //Serial.println(VFtree);
while(VFtree>900)
{VFtree=analogRead(Ftree); //Serial.println(VFtree); 
analogWrite(MBobbin1, 0); analogWrite(MBobbin2, 50);}
analogWrite(MBobbin1, 0); analogWrite(MBobbin2, 0); digitalWrite(Ltree, 0);}
//----------------------------------------------------------------------------------------------
void pozisiy_zasupca_zemliy() 
{digitalWrite(Lposition, 1);
 digitalWrite(Mplatform1, 0); digitalWrite(Mplatform2, 1);  analogWrite(MplatformSpeed, 254); delay(200);
 VFposition=analogRead(Fposition); //Serial.println(VFposition);
while(VFposition<800)
{VFposition=analogRead(Fposition); digitalWrite(Mplatform1, 0); digitalWrite(Mplatform2, 1);  analogWrite(MplatformSpeed, 254);}
digitalWrite(Mplatform1, 0); digitalWrite(Mplatform2, 0);  analogWrite(MplatformSpeed, 0); }
//----------------------------------------------------------------------------------------------
void moving_pipe_up()  
{VBpipeVerh=digitalRead(BpipeVerh); //Serial.println(VBpipeVerh);  
while(VBpipeVerh==0)
{VBpipeVerh=digitalRead(BpipeVerh); analogWrite(Mpipe1, 0); analogWrite(Mpipe2, 100);}
analogWrite(Mpipe1, 0); analogWrite(Mpipe2, 0);}
//----------------------------------------------------------------------------------------------
void moving_pipe_down() 
{VBpipeNiz=digitalRead(BpipeNiz); //Serial.println(VBpipeNiz);  
while(VBpipeNiz==0)
{VBpipeNiz=digitalRead(BpipeNiz); analogWrite(Mpipe1, 150); analogWrite(Mpipe2, 0);}
analogWrite(Mpipe1, 0); analogWrite(Mpipe2, 0);}
//----------------------------------------------------------------------------------------------
void platform_movement_to_right() 
{VBrightposition=digitalRead(Brightposition); //Serial.println(VBrightposition);  
while(VBrightposition==0)
{VBrightposition=digitalRead(Brightposition); digitalWrite(Mplatform1, 0); digitalWrite(Mplatform2, 1);  analogWrite(MplatformSpeed, 254);}
digitalWrite(Mplatform1, 0); digitalWrite(Mplatform2, 0);  analogWrite(MplatformSpeed, 0);}
//----------------------------------------------------------------------------------------------
void platform_movement_to_left() 
{VBleftposition=digitalRead(Bleftposition); //Serial.println(VBleftposition);  
while(VBleftposition==0)
{VBleftposition=digitalRead(Bleftposition); digitalWrite(Mplatform1, 1); digitalWrite(Mplatform2, 0);  analogWrite(MplatformSpeed, 254);}
digitalWrite(Mplatform1, 0); digitalWrite(Mplatform2, 0);  analogWrite(MplatformSpeed, 0);}
//----------------------------------------------------------------------------------------------
void drilling() 
{VBliftNiz=digitalRead(BliftNiz); //Serial.println(VBliftNiz);
while(VBliftNiz==0)
{VBliftNiz=digitalRead(BliftNiz); analogWrite(Mbur1, 0); analogWrite(Mbur2, 255); analogWrite(Mlift1, 100); analogWrite(Mlift2, 0);}
analogWrite(Mbur1, 0); analogWrite(Mbur2, 0); analogWrite(Mlift1, 0); analogWrite(Mlift2, 0);}
//----------------------------------------------------------------------------------------------
void raising_drill() 
{VBliftVerh=digitalRead(BliftVerh); //Serial.println(VBliftVerh);
while(VBliftVerh==0)
{VBliftVerh=digitalRead(BliftVerh); analogWrite(Mlift1, 0); analogWrite(Mlift2, 255);}
analogWrite(Mlift1, 0); analogWrite(Mlift2, 0);}
//----------------------------------------------------------------------------------------------
void forvard_robot() 
{analogWrite(MdriveL1, 254); analogWrite(MdriveL2, 0);
analogWrite(MdriveR1, 254); analogWrite(MdriveR2, 0); 
delay(10000); 
analogWrite(MdriveL1, 0); analogWrite(MdriveL2, 0);
analogWrite(MdriveR1, 0); analogWrite(MdriveR2, 0);}
//----------------------------------------------------------------------------------------------
void stop_robot() 
{analogWrite(MdriveL1, 0); analogWrite(MdriveL2, 0);
analogWrite(MdriveR1, 0); analogWrite(MdriveR2, 0);}
//----------------------------------------------------------------------------------------------
void right_robot() 
{analogWrite(MdriveL1, 254); analogWrite(MdriveL2, 0);
analogWrite(MdriveR1, 0); analogWrite(MdriveR2, 254);}
//----------------------------------------------------------------------------------------------
void left_robot() 
{analogWrite(MdriveL1, 0); analogWrite(MdriveL2, 254);
analogWrite(MdriveR1, 254); analogWrite(MdriveR2, 0);}
//----------------------------------------------------------------------------------------------