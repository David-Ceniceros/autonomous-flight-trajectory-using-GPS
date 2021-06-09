//Slave - eventually to be programmed to work with flight controller
#include <SparkFun_I2C_GPS_Arduino_Library.h> //Use Library Manager or download here: https://github.com/sparkfun/SparkFun_I2C_GPS_Arduino_Library
I2CGPS myI2CGPS; //Hook object to the library

#include <TinyGPS++.h> //From: https://github.com/mikalhart/TinyGPSPlus
TinyGPSPlus gps; //Declare gps object

void setup() {
  Serial.begin(9600);
  Serial.println("GTOP Read Example");

  if (myI2CGPS.begin() == false)
  {
    Serial.println("Module failed to respond. Please check wiring.");
    while (1); //Freeze!
  }
  Serial.println("GPS module found!");
}

void loop() {
  while (myI2CGPS.available()) //available() returns the number of new bytes available from the GPS module
  {
    gps.encode(myI2CGPS.read()); //Feed the GPS parser
  }

  if (gps.time.isUpdated()) //Check to see if new GPS info is available
  {
    displayInfo(); //This is the data that is to be displayed
  }
}

void displayInfo()
{
  //Read and print data to  microcontroller/Flight controller
  if (gps.time.isValid())
  {
    
  }
  else
  {
    Serial.println(F("Time not yet valid"));
  }

  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6); //Display latitude
    Serial.print(F(", "));
    Serial.print(gps.location.lng(), 6); //Display longitude
    Serial.println();
    delay(1000);
  }
  else
  {
    Serial.println(F("Location not yet valid"));
  }
}
