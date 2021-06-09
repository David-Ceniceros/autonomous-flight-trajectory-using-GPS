//Master - This program will become irrelevant as this Arduino Uno will be replace with the flight controller
char string[44]; //variable to store data

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.readBytes(mystr,24); //Read and store data
  Serial.println(mystr); 
  delay(1000);
}
