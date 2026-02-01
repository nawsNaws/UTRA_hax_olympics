int in1 = 0, in2 = 1;

int in3 = A0, in4 = A1; 

int ENA = 2;
int ENB = 3;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  

  Serial.begin(9600);

}

void loop() {
  void moveForward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

}

void turnRight(){ //test how long it takes to turn 45 degrees and 90 degrees . same with for left. plus any other course specifics you wanna do 
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

void moveBackwards(){ //test if this code acc makes it go backwards; edit accordingly if it doesnt work 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

}
