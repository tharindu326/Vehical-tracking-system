
 #include <SoftwareSerial.h>
 #include <TinyGPS++.h> 
 SoftwareSerial sim(11, 10);  
 String Arsp, Grsp;
 String string1  ;
 
void setup() {
  Serial.begin(9600);
  sim.begin(9600);
  Serial.println("Testing GSM SIM800L");
  sim.begin(9600);
  sim.println("AT"); //checking
  delay(1000);
  sim.println("AT+CMGF=1");  //Set to Text mode
  delay(1000);
  sim.println("AT+CNMI=1, 2, 0, 0, 0"); //Set to notification for new message, New message indication
  digitalWrite(5,HIGH);

}

void loop() {
  if(sim.available()) {
    //Check if GSM Send any data
    Grsp = sim.readString(); //Read data received from SIM800L GSM Module
    Serial.print(Grsp); //Print string which received from GSM (sms, sender, sms index, receive time, etc)
    delay(500);
          if(Grsp.indexOf("O") > 0) {
         Serial.println("on");
          digitalWrite(5,HIGH);
       //digitalWrite(LED_PIN, HIGH); // enable it
       }else if(Grsp.indexOf("F") > 0) {
         // digitalWrite(LED_PIN, LOW);// turn off
         Serial.println("off");
          digitalWrite(5,LOW);
      }else if(Grsp.indexOf("R") > 0) {
       
  }
}
