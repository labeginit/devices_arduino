
int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 8;

int burg1 = 13;
int burg2 = 12;
int burg3 = 11;
int burg4 = 8;

int sensorPin = 0;


void setup() {
   pinMode(LED1,OUTPUT);
   pinMode(LED2,OUTPUT);
   pinMode(LED3,OUTPUT);
   pinMode(LED4,OUTPUT);
   Serial.begin(9600); // start serial
   //lampOn();
   
 
   
while (!Serial) {
    ; // wait for serial port to connect.
  }

}
void loop(){
 String readString;
// lampOn();
   //alarmoff();
    //    alarmOn();
  while (Serial.available()) {
    char c = Serial.read();  // reads input from serial 
    readString += c; // adds to string 
    delay(2);  //slow looping to allow buffer to fill with next character
  }// depends on the command turn the led on, or off
  if (readString.length() >0) {
    if(readString == "on"){
      lampOn();
    }else if(readString == "off"){
      digitalWrite(LED1,1);
    digitalWrite(LED2, 1);
    digitalWrite(LED3,1);
    digitalWrite(LED4,1);
    
  }else if(readString=="insideOn"){
      indoorOn();
    }else if (readString =="insideOff"){
      indoorOff();
  }else if(readString=="temperature"){
    temp();
  }else if(readString="alarmOn"){
    alarmOn();
  }else if (readString="alarmOff"){
    alarmoff();
  }else if(readString="fan"){
    fan();
  }
  }
}




   float temp(){
    int reading = analogRead(sensorPin);
 // measure the 5v with a meter for an accurate value
 //In particular if your Arduino is USB powered
 float voltage = reading * 4.68;
 voltage /= 1024.0;
 
 // now print out the temperature
 float temperatureC = (voltage - 0.5) * 100;
 Serial.print(temperatureC);
 Serial.println(" degrees C");
 
 delay(1000);
 return temperatureC;
  }
 void lampOn(){
  digitalWrite(LED1,1);//13
    digitalWrite(LED2,0);//12
    digitalWrite(LED3,1);//11
    digitalWrite(LED4,1);//8
  }
  void alarmOn(){
    //below is alarm sound
    digitalWrite(LED1,0);//13
    digitalWrite(LED2,1);//12
    digitalWrite(LED3,0);//11
    digitalWrite(LED4,0);//8
  }

 
  void alarmoff(){
    //below is alarm sound
    digitalWrite(LED1,0);//13
    digitalWrite(LED2,0);//12
    digitalWrite(LED3,0);//11
    digitalWrite(LED4,0);//8
  }

  

  void indoorOn(){
      digitalWrite(LED1,0);//13 
      digitalWrite(LED2,0);//12
      digitalWrite(LED3,1);//11
      digitalWrite(LED4,0);//8
  }

  void indoorOff(){
      digitalWrite(LED1,0);
      digitalWrite(LED2,1);
      digitalWrite(LED3,1);
      digitalWrite(LED4,0);
  }

  void fan(){
     analogWrite(10,255);

  }
