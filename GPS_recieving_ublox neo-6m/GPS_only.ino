#include <SoftwareSerial.h> 
#include <TinyGPS++.h> 

//int _timeout;

String _buffer; 
String number = "+94775458743"; //0727610798//0719552699//
String latitude;
String longitude;
static const int RXPin = 10, TXPin = 11;
static const uint32_t GPSBaud = 9600;
int piezo =  A0;//analog pin
int MFET = 8 ; //digital
// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);
// The serial connection to the SIM device
//SoftwareSerial sim(3, 4);
void setup(){ 
  Serial.begin(9600);
   ss.begin(GPSBaud);
  // sim.begin(9600);
   delay(1000);
   pinMode(piezo,INPUT);
   pinMode(MFET,OUTPUT);
   digitalWrite(MFET,LOW);
   // Serial.begin(9600); // connect serial 
   Serial.println("The GPS Received Signal:"); 
   //_buffer.reserve(50); //allocate a buffer in memory
   Serial.println("GSM System Started...");
   //Serial.begin(9600);
}

void loop(){
  ReceiveGPS();
}

void ReceiveGPS()
{
 
  
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      latitude = String(gps.location.lat(), 6); 
      longitude = String(gps.location.lng(), 6); 
      //SendMessage();
      delay(1000); //after each 10 sec send the GPS coords  
      Serial.println("GSM System Started..");                                                                                                                                                                                                                                            
      Serial.print("Latitude= "); 
      Serial.print(latitude);
     Serial.print(" Longitude= "); 
      Serial.println(longitude);
      
    }
}
}
