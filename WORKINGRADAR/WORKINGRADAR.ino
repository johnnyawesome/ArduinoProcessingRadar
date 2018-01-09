
#include <Servo.h> 

Servo sweeper;

const int pingPin = 7;
int pos = 0;
long duration, cm;


void setup() {

  sweeper.attach(6);  
  Serial.begin(9600);
}

void loop(){
  
  // #### Turn to left and measure #### 
  for(pos = 0; pos <= 180; pos += 3){                                 
    ping();
    delay(100);
    sweeper.write(pos);            
    delay(300);                     
  } 
  
  // #### Turn to right and measure #### 
  for(pos = 180; pos>=0; pos-=3){                                
    ping();
    delay(100);
    sweeper.write(pos);            
    delay(300);            
  } 

}  
  

  
void ping(){

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  
  //Limit Max Distance to 1 Meter
  //cm = constrain(cm, 0, 150);  
  

  Serial.print(cm);
  Serial.print(",");
  Serial.print(pos);
  Serial.println(); 
 // delay(100);
  
}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
