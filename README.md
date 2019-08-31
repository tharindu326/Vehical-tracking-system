# Vehical-tracking-system

System will detect vehicle’s movements using the vibrations of vehicle and then notify the owner in any case of unidentified movements.

Here I used Peizo to identify vibrations using amplified voltage variations, GPS module (Ublox neo-6m) to identify the coordinates of the location and then GSM (SIM800) module to transmit the data to the mobile device.

And used a mobile application (Android) to request the real time location of the vehicle at any time. And initiation of the phone number and activation can be done using the app as well as it also allows the owner to turn on and off the system at any time.

Arduino UNO was used as the microcontroller and Android studio was used to program the application. Buck converter is used to power up the GPS and GSM modules since its slightly power hungry. Vehicle GPS antenna was used to achieve  more reliable signal strength.
