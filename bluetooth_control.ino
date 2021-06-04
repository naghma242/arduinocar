char t;
#define lr 8
#define lf 9
#define rr 10
#define rf 11
void setup() 
{
  pinMode(lf,OUTPUT);   //left motors forward
  pinMode(lr,OUTPUT);   //left motors reverse
  pinMode(rf,OUTPUT);   //right motors forward
  pinMode(rr,OUTPUT);   //right motors reverse
  pinMode(13,OUTPUT);   //Led
  Serial.begin(9600); 
}
 
void loop() 
{
  if(Serial.available())
  {
      t = Serial.read();
      Serial.println(t);
  }
 
  if(t == 'F')
  {            //move forward(all motors rotate in forward direction)
    digitalWrite(lf,HIGH);
    digitalWrite(rf,HIGH);
  }
 
  else if(t == 'B')
  {      //move reverse (all motors rotate in reverse direction)
    digitalWrite(lr,HIGH);
    digitalWrite(rr,HIGH);
  }
 
  else if(t == 'L')
  {      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
    digitalWrite(rf,HIGH);
  }
 
  else if(t == 'R')
  {      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
    digitalWrite(lf,HIGH);
  }

  else if(t == 'W')
  {    //turn led on or off)
    digitalWrite(13,HIGH);
  }
  else if(t == 'w')
  {
    digitalWrite(13,LOW);
  }
 
  else if(t == 'S')
  {      //STOP (all motors stop)
    digitalWrite(lf,LOW);
    digitalWrite(lr,LOW);
    digitalWrite(rf,LOW);
    digitalWrite(rr,LOW);
  }
  delay(100);
}
