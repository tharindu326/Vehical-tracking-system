#include <SoftwareSerial.h>
SoftwareSerial sim(11,10);
int _timeout;
String _buffer;
String number1 = "+94775458743";

void setup() {
  //digitalWrite(5,HIGH);
  
  delay(7000); //delay for 7 seconds to make sure the modules get the signal
  Serial.begin(9600);//set board rate
 // _buffer.reserve(50); //allocate a buffer in memory
  Serial.println("Sistem Started...");
  sim.begin(9600);
sim.println("AT");
  delay(1000);
}
void loop() {
  SendMessage();
  delay(10000);
}
void SendMessage()
{
  Serial.println ("Sending Message");
  sim.println("AT");
  sim.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);
  Serial.println ("Set SMS Number");
  sim.println("AT+CMGS=\"" + number1 + "\"\r"); //Mobile phone number to send message
  delay(1000);
  String SMS = "SIM800L";
  sim.println(SMS);//send the sms
  delay(100);
  sim.println((char)26);// ASCII code of CTRL+Z=substitut
  delay(1000);
//  _buffer = _readSerial();//function for read SMS
}
 /*String _readSerial() {
  _timeout = 0;
  while  (!sim.available() && _timeout < 12000  );//Checks to see if there is a SMS messages on the SIM card to be read, and reports back the number of characters in the message.
  {
    delay(13);
    _timeout++;
  }
  if (sim.available()) {
    return sim.readString();//read th strings in available sms and equal it to _buffr
  }
}*/
