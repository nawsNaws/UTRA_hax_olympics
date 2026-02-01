// Motor A (Left)
// const int enA = 5; 
// const int in1 = 6;
// const int in2 = 7;

// // Motor B (Right)
// const int enB = 10;
// const int in3 = 8;
// const int in4 = 9;


//SERVOS: 
#include <Servo.h>

Servo myServo; //make servo obj

int pos = 0;

char incomingByte; // for incoming serial data, should be if the car has detected a item/obsticle

//COLOUR SENSOR:
#define s0 8
#define s1 9
#define s2 10
#define s3 11
#define out 12

int data = 0; 
int red = 0;
int blue = 0;
int green = 0;
int colour = 0; //--> different colours rep different numbers
int blueCounter = 0; 


int in1 = 0, in2 = 1;

int in3 = A0, in4 = A1; 

int ENA = 2;
int ENB = 3;
int wheelDirection = 0; 

//ULTRASONIC SENSORS: 
// Ultrasonic Sensor with Arduino
// Measures distance in centimeters and inches

// Pin configuration
const int trigPin = 9;  // Trigger pin
const int echoPin = 10; // Echo pin
const int lightPin = 8; // LED pin

// Speed of sound in cm/µs
const float SOUND_SPEED = 0.0343; // cm per microsecond


// Ultrasonic Pins
const int trigPin = 11;
const int echoPin = 12;

// Motor Driver Pins
const int motorL1 = 5; 
const int motorL2 = 6; 
const int motorR1 = 9; 
const int motorR2 = 10; 

// Servo Setup
Servo claw;
const int clawPin = 3;
int openAngle = 70;
int closedAngle = 145; // Adjust based on your grip test



//IR SENSORS: 
// Pin Definitions
const int leftIR = 2;
const int rightIR = 3;


void setup() {
  
//CLAW:
  myServo.attach(A2); // servo motor is pin 9
  myServo.write(0); // set the start at angle 0

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

  
//ULTRASONIC SENSOR:

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(lightPin, OUTPUT);



//IR SENSORS: 
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
  
  // pinMode(enA, OUTPUT);
  // pinMode(in1, OUTPUT);
  // pinMode(in2, OUTPUT);
  // pinMode(enB, OUTPUT);
  // pinMode(in3, OUTPUT);
  // pinMode(in4, OUTPUT);



//COLOUR SENSOR:
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  
  digitalWrite(s0, HIGH); 
  digitalWrite(s1, HIGH);


//MOTOR: 
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  

  Serial.begin(9600);

}

void loop() {
  //IR SENSORS: 
  digitalWrite(leftIR,HIGH);
  digitalWrite(rightIR,HIGH);
  int leftState = digitalRead(leftIR);
  int rightState = digitalRead(rightIR);

  if (leftState == LOW && rightState == LOW) {
    // moveForward();
    Serial.println("forwards");
    moveForward(); 
  } 
  else if (leftState == LOW && rightState == HIGH) {
    //turnLeft();
    Serial.println("right");
    turnRight(); 
  } 
  else if (leftState == HIGH && rightState == LOW) {
    //turnRight();
    Serial.println("left");
    turnLeft(); 
  } 

  getColours(); 
  
  if (red<= 15 && green <= 15 && blue <= 15){ 
    Serial.println("white"); 
    colour = 1; 
  } 

  else if (red < blue && red <= green && red < 23){
    Serial.println("red"); 
    colour = 2; 
  }

  else if (blue < green && blue < red && blue < 20){
    Serial.println("blue"); 
    colour = 3; 
  } 
    
  else if (green < red  && green - blue <= 8){
    Serial.println("green"); 
    colour = 4; 
    }
  
  else {
    Serial.println("other"); 
    colour = 5; 
  }
  delay (2000); 

  blueTape1(); 
  blueTape2();    

//ULTRASONIC SENSOR: 
  long duration;
  float distanceCm, distanceInch;

  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10µs HIGH pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin (timeout after 25ms = ~4 meters)
  duration = pulseIn(echoPin, HIGH, 25000UL);

  // If no echo is received (timeout), skip calculation
  if (duration == 0) {
    Serial.println("Out of range or no object detected");
  } else {
    // Calculate distance in cm
    distanceCm = (duration * SOUND_SPEED) / 2.0;

    // Display results rounded to 2 decimal points
    Serial.println(distanceCm, 2);
  }

  // Turn on LED if object is less than 20cm away
  if (distanceCm<20){
    //turn around the obstacle
  delay(500); // Wait before next measurement

  //CLAW:

   if (Serial.available()) { // if a signal is sent to lower or raise the claw
    incomingByte = Serial.read(); // get the data

    if (incomingByte == '1' && pos == 0) { // if the claw is up
      lower_claw(); //lower the claw
      pos = 1; // claw is now in a lowered position
    }


    else if (incomingByte == '0' && pos == 1) {
      raise_claw(); //raise the claw
      pos = 0; // claw is now in a raised position
    }
  }
}

void getColours() {

  //s2 low and s3 low signifies red 
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
  delay(20);  
  digitalWrite(s3, HIGH); // changes just s3 to high since s2 low and s3 high is blue 
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
  delay(20); 
  digitalWrite(s2, HIGH);
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
  delay(20); 
}

void driveForward() {
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);

}

void moveForward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW;

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

}

void turnRight(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);// backwards is low high 

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void turnLeft(){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    analogWrite(ENA, 200);
    analogWrite(ENB, 200);
}

void moveBackwards(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH;

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  
}



void stopMotors() {
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, LOW);
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, LOW);
}

void pickUpBox() {
  claw.write(closedAngle);
  delay(1000);
}

void blueTape1(){ //set int counter to 0 at beginning --> once this code works increase by 1 then blue tape 2 works if tape is blue and counter = 1 
  if (colour = 3 && blueCounter = 0){
    turnRight(); 
    moveBackwards(); 
    delay(100); 
    moveForward(); 



  }
}

void blueTape2(){

}

//turn right 
//potentially move back a bit 
//collect box 

//lowers the claw
void lower_claw() {
  for (int angle = 0; angle <= 90; angle++) {
    myServo.write(angle);
    delay(15);
  }
}

//raises the claw
void raise_claw() {
  for (int angle = 90; angle >= 0; angle--) {
    myServo.write(angle);
    delay(15);
  }
}







