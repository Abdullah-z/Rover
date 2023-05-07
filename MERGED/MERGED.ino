#include <Servo.h>
Servo motor1;
Servo motor2;
Servo servo1;  
const int xpin = A3;                  
const int ypin = A2;                  
const int zpin = A1;                  
const int xmotor = 8;
const int ymotor = 9;
const int flexPin = A0;

int x,y,z;
void setup() 
{
  motor1.attach(xmotor);
  motor2.attach(ymotor);
  servo1.attach(2); 
  Serial.begin(9600);
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
  x=analogRead(xpin);
  y=analogRead(ypin);
  z=analogRead(zpin);
  Serial.print(x);
  Serial.print(' ');
  Serial.print(y);
  Serial.print(' ');
  Serial.print(z);
  Serial.println();
  pos(x,y);
  delay(50);
  int flexPosition;   
  int servoPosition;
  flexPosition = analogRead(flexPin);
  servoPosition = map(flexPosition, 900, 950, 90, 0);
  servoPosition = constrain(servoPosition, 0, 180);
  servo1.write(servoPosition);
  Serial.print("sensor: ");
  Serial.print(flexPosition);
  Serial.print("  servo: ");
  Serial.println(servoPosition);
  delay(20);
}
