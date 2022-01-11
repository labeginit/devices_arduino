#include <StaticThreadController.h>
#include <Thread.h>
#include <ThreadController.h>

ThreadController tc = ThreadController();
Thread pLoop = Thread();
Thread vLoop = Thread();



int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 8;

int burg1 = 13;
int burg2 = 12;
int burg3 = 11;
int burg4 = 8;

int sensorPin = A2;

int inbrott = 3;


void setup() {
   pinMode(LED1,OUTPUT);
   pinMode(LED2,OUTPUT);
   pinMode(LED3,OUTPUT);
   pinMode(LED4,OUTPUT);
   Serial.begin(9600); // start serial
   pLoop.onRun(temp);
   pLoop.setInterval(300);
   
     vLoop.onRun(inbrottOn);
   vLoop.setInterval(300);
   
  
      tc.add(&penisLoop);
  tc.add(&vaginaLoop);
   

   
while (!Serial) {
    ; // wait for serial port to connect.
  }
delay(500);
}
void loop(){
  
 // indoorOff();
  //lampOn();
  //lampOff();
  //heatingWind();
 //heating();
//heatingWindOff();
//heatingOff();
//fan();
//fanOff();

   String readString;
  while (Serial.available()) {
    char c = Serial.read();  // reads input from serial 
    readString += c; // adds to string 
    delay(2);  //slow looping to allow buffer to fill with next character
  }// depends on the command turn the led on, or off
  if (readString.length() >0) {
    Serial.print(readString);
    if(readString == "on"){
      lampOn();
    }else if(readString == "off"){
     lampOff();
  }else if(readString=="insideOn"){
      indoorOn();
    }else if (readString =="insideOff"){
      indoorOff();
  }else if(readString=="alarmOn"){
   
        alarmOn();
  }else if (readString=="alarmOff"){
    alarmoff();
  }else if(readString=="High"){
    fan();
  }else if (readString=="Medium"){
    fanMedium();
  }else if(readString=="Low"){
    fanLow();
  }else if (readString=="Off")
  fanOff();
  }else if (readString=="heaterOn"){
    heating();
    heatingWind();     
  }else if (readString=="heaterOff"){
    heatingOff();
    heatingWindOff();
  }
 


}




   void temp(){
//    int val = 0;
double val = 0;
    val = analogRead(sensorPin);
  float mv = ( val/1024.0)*5000;
  float cel = mv/10;
  //Serial.print("TEMPRATURE = ");
  int Sator = trunc(cel);
  Serial.print(Sator);
//  Serial.print("C");
  Serial.println();
//   delay(30000);
  }
 void lampOn(){
  digitalWrite(LED1,1);//13
    digitalWrite(LED2,0);//12
    digitalWrite(LED3,1);//11
    digitalWrite(LED4,1);//8
  }

  void lampOff(){
     digitalWrite(LED1,1);
    digitalWrite(LED2, 1);
    digitalWrite(LED3,1);
    digitalWrite(LED4,1);
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

  void fanMedium(){
    analogWrite(10,127);
  }

  void fanOff(){
    analogWrite(10,0);
  }

  void fanLow(){
    analogWrite(10,90);
  }

  void inbrottOn(){
    int val ;
  val = digitalRead(inbrott);

    if(val == 0){
      digitalWrite(LED1,0);//13
    digitalWrite(LED2,1);//12
    digitalWrite(LED3,0);//11
    digitalWrite(LED4,0);//8
    }else if (val == 1){
digitalWrite(LED1,0);//13
    digitalWrite(LED2,0);//12
    digitalWrite(LED3,0);//11
    digitalWrite(LED4,0);//8    
    }
  }
    void heatingWind(){
      digitalWrite(LED1,1);//13
    digitalWrite(LED2,0);//12
    digitalWrite(LED3,1);//11
    digitalWrite(LED4,0);//8
    }

    void heatingWindOff(){
      digitalWrite(LED1,1);//13
    digitalWrite(LED2,1);//12
    digitalWrite(LED3,1);//11
    digitalWrite(LED4,0);//8
    }
     void heating(){
      digitalWrite(LED1,1);//13
    digitalWrite(LED2,0);//12
    digitalWrite(LED3,0);//11
    digitalWrite(LED4,1);//8
    }

    void heatingOff(){
      digitalWrite(LED1,1);//13
    digitalWrite(LED2,1);//12
    digitalWrite(LED3,0);//11
    digitalWrite(LED4,1);//8
    }
    
