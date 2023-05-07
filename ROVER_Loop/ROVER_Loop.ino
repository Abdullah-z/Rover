#define m11 22
#define m12 23
#define m21 24
#define m22 25
#define m31 26
#define m32 27
#define m41 28
#define m42 29


char str[2],i;

void forward()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
   digitalWrite(m31, HIGH);
   digitalWrite(m32, LOW);
   digitalWrite(m41, HIGH);
   digitalWrite(m42, LOW);
}

void backward()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH);
   digitalWrite(m31, LOW);
   digitalWrite(m32, HIGH);
   digitalWrite(m41, LOW);
   digitalWrite(m42, HIGH);
 }

void left()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m41, HIGH);
   digitalWrite(m42, LOW);
   delay(100);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
   digitalWrite(m31, LOW);
   digitalWrite(m32, LOW);
} 

void right()
{
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
   digitalWrite(m31, HIGH);
   digitalWrite(m32, LOW);
   delay(100);
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m41, LOW);
   digitalWrite(m42, LOW);
}

void Stop()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
   digitalWrite(m31, LOW);
   digitalWrite(m32, LOW);
   digitalWrite(m41, LOW);
   digitalWrite(m42, LOW);
}

void setup() 
{
  /* int m = 22;
   * for (i=m ; i<=29 ; i++) {
   * pinMode(i , OUTPUT)
   * } 
   */
  Serial.begin(9600);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(m31, OUTPUT);
  pinMode(m32, OUTPUT);
  pinMode(m41, OUTPUT);
  pinMode(m42, OUTPUT);
}

void loop() 
{
  while(Serial.available())
  {
    char ch=Serial.read();
    str[i++]=ch;
    
    if(str[i-1]=='1')
    {
     Serial.println("Forward");
     forward();
     i=0;
    }

    else if(str[i-1]=='2')
    {
     Serial.println("Left");
     right();
     i=0;
    }

    else if(str[i-1]=='3')
    {
      Serial.println("Right");
      left();
      i=0;
    }
    
    else if(str[i-1]=='4')
    {
      Serial.println("Backward");
      backward();
      i=0;
    }

    else if(str[i-1]=='5')
    {
      Serial.println("Stop");
      Stop();
      i=0;
    }
    delay(100);
  }
}
