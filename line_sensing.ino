// Pin Definitions
const int leftIR = 2;
const int rightIR = 3;

// Motor A (Left)
const int enA = 5; 
const int in1 = 6;
const int in2 = 7;

// Motor B (Right)
const int enB = 10;
const int in3 = 8;
const int in4 = 9;

void setup() {
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  int leftState = digitalRead(leftIR);
  int rightState = digitalRead(rightIR);

  // Note: LOW usually means "Line Detected" on many IR modules
  // If yours is the opposite, just swap LOW for HIGH below.

  if (leftState == HIGH && rightState == HIGH) {
    moveForward();
  } 
  else if (leftState == LOW && rightState == HIGH) {
    turnLeft();
  } 
  else if (leftState == HIGH && rightState == LOW) {
    turnRight();
  } 
  else {
    stopMotors();
  }
}

void moveForward() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  analogWrite(enA, 150); analogWrite(enB, 150); // Speed 0-255
}

void turnLeft() {
  digitalWrite(in1, LOW);  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  analogWrite(enA, 120); analogWrite(enB, 120);
}

void turnRight() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);  digitalWrite(in4, HIGH);
  analogWrite(enA, 120); analogWrite(enB, 120);
}

void stopMotors() {
  analogWrite(enA, 0); analogWrite(enB, 0);
}
