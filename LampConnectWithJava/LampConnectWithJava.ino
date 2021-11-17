
int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 8;

int INDORELED1 = 13;
int INDORELED2 = 12;
int INDORELED3 = 11;
int INDORELED4 = 8;

void setup() {
   pinMode(LED1,OUTPUT);
  // pinMode(LED2,OUTPUT);
  // pinMode(LED3,OUTPUT);
  // pinMode(LED4,OUTPUT);
   Serial.begin(9600); // start serial

  pinMode(INDORELED1,OUTPUT);
  //pinMode(INDORELED2,OUTPUT);
  //pinMode(INDORELED3,OUTPUT);
  //pinMode(INDORELED4,OUTPUT);
  Serial.begin(9600);

 
   
while (!Serial) {
    ; // wait for serial port to connect.
 while (!Serial){
    ;
  }

}
void loop(){
 String readString;
  while (Serial.available()) {
    char c = Serial.read();  // reads input from serial 
    readString += c; // adds to string 
    delay(2);  //slow looping to allow buffer to fill with next character
  }// depends on the command turn the led on, or off
  if (readString.length() >0) {
    if(readString == "turnOn"){
    digitalWrite(LED1,1);
    //digitalWrite(LED2,0);
    //digitalWrite(LED3,1);
    //digitalWrite(LED4,1);
    }
    else if(readString == "turnOff"){
      digitalWrite(LED1,0);
    //digitalWrite(LED2, 1);
    //digitalWrite(LED3,1);
    //digitalWrite(LED4,1);
    }
 String readString;
  while(Serial.available ()){
    char c = Serial.read();
    readString +=c;
    delay(2);
  }
  if (readString.length()>0){
    if(readString=="On"){
      digitalWrite(INDORELED1,0);
      //digitalWrite(INDORELED2,0);
      //digitalWrite(INDORELED3,1);
      //digitalWrite(INDORELED4,0);
    }
    else if (readString =="off"){
      digitalWrite(INDORELED1,0);
      //digitalWrite(INDORELED2,1);
      //digitalWrite(INDORELED3,1);
      //digitalWrite(INDORELED4,0);
  }
}
