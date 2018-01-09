  



import processing.serial.*;

Serial myPort;    // The serial port

String inString;  // Input string from serial port
float pingread;
float servoread;
int readings[];


float angle;
float radius;

void setup() {
  
  size(900,900);
  background(0);

  // List all the available serial ports:
  println(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[0], 9600);
  myPort.bufferUntil('\n');
  
}

void draw() {

  int middleX = width/2;
  int middleY = height/2;
  
  // background(0);
  if(servoread > 177){
    background(0);
  }
  if(servoread < 5){
    background(0);
  }

 
  //text(pingread + "," + servoread, 10,50);
   

  radius = map(pingread, 0, 150, 0, height * 0.5);


  float x = middleX + cos(angle) * height/2;
  float y = middleY + sin(angle) * height/2;
  stroke(20);
  x = middleX + cos(angle) * radius * 2;
  y = middleY + sin(angle) * radius * 2;
  stroke(0,255,0);
  fill(0,255,0);
  line(middleX, middleY, x, y);
  noStroke();
  ellipse(x, y, 7, 7);


  
}



void serialEvent(Serial p) {
  
   inString =  p.readStringUntil('\n');
  
   inString = trim(inString);
   readings = int(split(inString, ','));
   println("Converted " + readings[0] + "," + readings[1]);
   println("instring " + inString);
   pingread = (readings[0]);
   angle = (readings[1] * 0.018);
   servoread = readings[1];
   

   
}


