int LED = A0;
void setup() {
   pinMode(LED,OUTPUT);
   Serial.begin(9600); // start serial
while (!Serial) {
    ; // wait for serial port to connect.
  }
}

void loop() {
 String readString;
  while (Serial.available()) {
    char c = Serial.read();  // reads input from serial 
    readString += c; // adds to string 
    delay(2);  //slow looping to allow buffer to fill with next character
  }// depends on the command turn the led on, or off
  if (readString.length() >0) {
    if(readString == "turnOn"){
    digitalWrite(LED, 1);
    }
    else if(readString == "turnOff"){
      digitalWrite(LED, 0);
    }
  }
}
