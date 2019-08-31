#include <SoftwareSerial.h> 
#include <TinyGPS++.h> 

//int _timeout;

String _buffer; 
String number = "+94703647019"; //0727610798//0719552699//775458743
String latitude;
String longitude;
static const int RXPin = 10, TXPin = 11;
static const uint32_t GPSBaud = 9600;
int piezo =  A0;//analog pin

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
//SoftwareSerial ss(RXPin, TXPin);
// The serial connection to the SIM device

SoftwareSerial sim(11, 10);
void setup(){ 
   Serial.begin(9600);
   Serial1.begin(GPSBaud);
   sim.begin(9600);
   delay(1000);
   pinMode(piezo,INPUT);
   
   
   Serial.begin(9600); // connect serial 
   Serial.println("The GPS Received Signal:"); 
   //_buffer.reserve(50); //allocate a buffer in memory
   Serial.println("GSM System Started...");
   //Serial.begin(9600);
}


void loop(){
  //delay (100);
 checkPiezo();
 ReceiveGPS();
}


void ReceiveGPS()
{
 
  
  // This sketch displays information every time a new sentence is correctly encoded.
   while (Serial1.available() > 0){
    gps.encode(Serial1.read());
    if (gps.location.isUpdated()){
      latitude = String(gps.location.lat(), 6); 
      longitude = String(gps.location.lng(), 6); 
      //SendMessage();
     // delay(1000); //after each 10 sec send the GPS coords  
      //Serial.println("GSM System Started..");                                                                                                                                                                                                                                            
    //  Serial.print("Latitude= "); 
    //  Serial.print(latitude);
    // Serial.print(" Longitude= "); 
    //  Serial.println(longitude);
      
    }
}
}

void SendMessage()
{
  Serial.println ("Sending Message");
  sim.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
 // delay(100);
  //Serial.println ("Set SMS Number");
  sim.println("AT+CMGS=\"" + number + "\"\r"); //Mobile phone number to send message
 delay(100);
  //String SMS = String latitude,String longitude
  sim.println("VEHICLE IS ON MOVE...............                                    http://www.google.com/maps/place/"+latitude+","+longitude);//send the sms
 delay(100);
  sim.println((char)26);// ASCII code of CTRL+Z=substitut
  delay(100);
//  _buffer = _readSerial();//function for read SMS
}

void checkPiezo()
{
  int pzin=analogRead(A0);
  Serial.println(pzin);
   if(pzin>900) 
     tutu();
  }
void tutu()
 {Serial.print("Latitude= "); 
   Serial.print(latitude);
   Serial.print(" Longitude= "); 
   Serial.println(longitude);
   SendMessage();
   delay(20000);
   
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
