#include <Servo.h> 
Servo servo1;   
const int flexPin = A0;
void setup() 
{ 
 Serial.begin(9600);
 servo1.attach(2); 
} 
void loop() 
{ 
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

