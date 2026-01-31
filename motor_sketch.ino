// Motor A
int in1 = 0, in2 = 1;
// Motor B
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



digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);

digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

analogWrite(ENA, 200);
analogWrite(ENB, 200);



}






