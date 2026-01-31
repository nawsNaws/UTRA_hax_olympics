#define s0 9
#define s1 10
#define s2 11
#define s3 12
#define out 13 

int data = 0; 

void setup() {
  // put your setup code here, to run once:
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);

  Serial.begin(9600); 
  
  /*
  * makes output frequency scaling 100% 
  */
  digitalWrite(s0, HIGH); 
  digitalWrite(s1, HIGH);


}

void loop() {
  // put your main code here, to run repeatedly:

  //s2 low and s3 low signifies red 
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  getData(); //reads info from the sensor 

  //s2 high and s3 high is green 
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  Serial.print("Green value = "); 
  getData(); 

  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  Serial.print("Blue value = "); 
  getData(); 

  //the colour that it senses will have the lowest value 
  //ex. put a green thing in front of sensor and green value will be the lowest number 
  Serial.println(); 

  delay(2000); 
  
}

void getData() {
  data = pulseIn(out, LOW); //measures how high the frequency is (the higher the frequency the lower the duration) is and based on that assigns it to red or green 
  Serial.print(data); 
  Serial.print("\t");
  delay(20); 
}

