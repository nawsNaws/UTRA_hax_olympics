//ULTRASONIC SENSORS: 
// Ultrasonic Sensor with Arduino
// Measures distance in centimeters and inches

// Pin configuration
const int trigPin = 9;  // Trigger pin
const int echoPin = 10; // Echo pin
const int lightPin = 8; // LED pin

// Speed of sound in cm/µs
const float SOUND_SPEED = 0.0343; // cm per microsecond



//SERVOS: 
#include <Servo.h>

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

// Motor A (Left)
// const int enA = 5; 
// const int in1 = 6;
// const int in2 = 7;

// // Motor B (Right)
// const int enB = 10;
// const int in3 = 8;
// const int in4 = 9;



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



//MOTOR: 
// Motor A
int in1 = 0, in2 = 1;
// Motor B
int in3 = A0, in4 = A1;

int ENA = 2;
int ENB = 3;

void setup() {
//ULTRASONIC SENSOR:

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(lightPin, OUTPUT);

//SERVOS: 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);

  claw.attach(clawPin);
  claw.write(openAngle);

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
//ULTRASONIC SENSORS: 
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



//SERVOS: 
  long duration;
  int distance;

  // 1. Get Distance Reading
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convert time to cm

  Serial.print("Distance: ");
  Serial.println(distance);

  // 2. Logic: Drive until 15cm away
  if (distance > 15 || distance == 0) { // '0' often means out of range
    driveForward();
  } 
  else {
    stopMotors();
    delay(500);         // Let the robot settle
    pickUpBox();
    while(true);        // Stop everything after picking up
  }
  
  delay(50); // Small delay to prevent sensor "noise"



//IR SENSOR: 
  digitalWrite(leftIR,HIGH);
  digitalWrite(rightIR,HIGH);
  int leftState = digitalRead(leftIR);
  int rightState = digitalRead(rightIR);

  // Note: LOW usually means "Line Detected" on many IR modules
  // If yours is the opposite, just swap LOW for HIGH below.

  if (leftState == LOW && rightState == LOW) {
    // moveForward();
    Serial.println("forwards");
  } 
  else if (leftState == LOW && rightState == HIGH) {
    //turnLeft();
    Serial.println("right");
  } 
  else if (leftState == HIGH && rightState == LOW) {
    //turnRight();
    Serial.println("left");
  } 
  else {
    Serial.println("not gonna happen");
   // stopMotors();
  }



//COLOUR SENSOR:
getColours(); 
  
  if (red<= 15 && green <= 15 && blue <= 15){ 
    Serial.println("white"); 
  } 

  else if (red < blue && red <= green && red < 23){
    Serial.println("red"); 
  }

  else if (blue < green && blue < red && blue < 20){
    Serial.println("blue"); 
  } 
    
  else if (green < red  && green - blue <= 8){
    Serial.println("green"); 
    }
  
  else {
    Serial.println("other"); 
  }
  delay (2000);    

//MOTOR: 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
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


