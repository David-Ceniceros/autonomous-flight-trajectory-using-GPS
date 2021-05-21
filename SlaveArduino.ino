char string[5] = "Hello"; //String data

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(string,5); //Write the serial data
  delay(1000);
}
