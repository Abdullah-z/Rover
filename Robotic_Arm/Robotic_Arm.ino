#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial xbee(2,3);
Servo base;
Servo updo1;
Servo updo2;
Servo flex;                 
const int xmotor = 8;
const int ymotor1 = 9;
const int ymotor2 = 10;
const int fmotor = 11;
int x,y,z;
void setup() 
{
  base.attach(xmotor);
  updo1.attach(ymotor1);
  updo2.attach(ymotor2);
  flex.attach(fmotor);
  Serial.begin(9600);
  xbee.begin(9600);
}
  void xmot(int pos)
{
  Serial.println(pos);
  motor1.write(pos);
  return;
}
  void ymot(int pos)
{
  Serial.println(pos);
  motor2.write(pos);
  return;
}
void pos(int x,int y)
{
  Serial.println("NA");
  if ((x <= 345 && x >= 305) && (y <=286 && y >= 246))
  {
    Serial.println("RIGHT");
   int pos1 = motor1.read();
   pos1=pos1-3;
     xmot(pos1); 
     return;
    }
    else if ((x <= 348 && x >= 308) &&( y <=422 && y >= 388))
    {
    Serial.println("LEFT");
    int pos2 = motor1.read();
    pos2=pos2+3;
    xmot(pos2);
    return;
  }
  else if ((x <= 285 && x >= 245 )&& (y <=353 && y >= 313))
  {
    Serial.println("UP");
    int pos3 = motor2.read();
    pos3=pos3+3;
     ymot(pos3);
     return;
  }
  else if ((x <= 415 && x >= 375) &&( y <= 352 && y >= 312))
  {
    Serial.println("DOWN");
     int pos4 = motor2.read();
     pos4=pos4-3;
     ymot(pos4);
     return;
  }
  else if ((x <= 345 && x >= 305) && (y <=286 && y >= 246))
  {
    Serial.println("default");
     xmot(90);
     ymot(90);
     return;
  }
}
void loop() 
{
  while (xbee.available()>0){
   char income = xbee.read();
   pos(income);
   
}
