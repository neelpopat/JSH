long inp,out;
const long start = 8;
const long app = 8;
const long enda = start + app - 1;
void setup() {
  Serial.begin(9600);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  if(Serial.available()>0)
  {
    inp = Serial.parseInt();
    if(inp <= enda && inp >= start)
    {
      out = inp - start + 2;
      relSwitch(out);
    }
    else
    {
      
    }
  }
}
void relSwitch(long pin)
{
  switch(digitalRead(pin))
      {
        case(HIGH):digitalWrite(pin, LOW);
                   digitalWrite(13, LOW);
                  // Serial.println(pin);
                   break;
        case(LOW):digitalWrite(pin, HIGH);
                  digitalWrite(13, HIGH);
                 // Serial.println(pin);
                   break;
      }
}

