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

void setup() {
  Serial.begin(9600);
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
  
  // pinMode(enA, OUTPUT);
  // pinMode(in1, OUTPUT);
  // pinMode(in2, OUTPUT);
  // pinMode(enB, OUTPUT);
  // pinMode(in3, OUTPUT);
  // pinMode(in4, OUTPUT);
}

void loop() {
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
}
