char string[10]; //variable to store data

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.readBytes(mystr,5); //Read and store data
  Serial.println(mystr); 
  delay(1000);
}
