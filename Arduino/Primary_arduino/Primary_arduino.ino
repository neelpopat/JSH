
#include <SoftwareSerial.h>
SoftwareSerial mySerial(6, 7); // RX, TX
long inp = -1,out;
const long start = 0;
const long app = 8;
const long enda = start + app - 1;
void setup() {
  // Open serial communications and wait for port to open:
  mySerial.begin(9600);
  /*while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }*/

  // set the data rate for the SoftwareSerial port
   Serial.begin(9600);
   //pinMode(2,OUTPUT);
   pinMode(3,OUTPUT);
   pinMode(4,OUTPUT);
   pinMode(5,OUTPUT);
   pinMode(9,OUTPUT);
   pinMode(10,OUTPUT);
   pinMode(11,OUTPUT);
   pinMode(12,OUTPUT);   
}

void loop() { // run over and over
  while(mySerial.available() > 0) {
    inp = mySerial.parseInt();
    if(inp <= enda && inp >= start)
    {
      out = inp - start + 2;
      if(out > 5)
      {
         out = out + 3;
         relSwitch(out);
         out = -1;
         break;
      }
      else
      {
        relSwitch(out);
        out = -1;
        break;
      }
    }
    else //if(inp > enda)
    {
      Serial.println(inp);
      break;
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
                  //Serial.println(pin);
                   break;
      }
}
