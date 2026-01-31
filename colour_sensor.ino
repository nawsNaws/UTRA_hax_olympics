#define s0 8
#define s1 9
#define s2 10
#define s3 11
#define out 12  

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

/*  getColours(); 
  
  
  //accounts for reflection/other lighting stuff affecting what colour is sensed 
  
  if (red<= 15 && green <= 15 && blue <= 15) //i think the values for these numbers are based on the frequencies sensed so test out normal ver. first 
    Serial.println("white"); 

  else if (red < blue && red <= green && red < 23)
    Serial.println("red"); 

  else if (blue < green && blue < red && blue < 20)
    Serial.println("blue"); 

  else if (red<= 15 && green <= 15 && blue <= 15)
    Serial.println("green"); 

  else (green < red  && green - blue <= 8)
    Serial.println("other"); 

  delay (2000); 

  void getColours() {

  //s2 low and s3 low signifies red 
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  red = pulseIn(out, digitalRead(out))
  GetData(); //reads info from the sensor 

  //s2 high and s3 high is green 
  digitalWrite(s2, HIGH;
  digitalWrite(s3, HIGH);
  Serial.print("Green value = "); 
  GetData(); 

  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  Serial.print("Blue value = "); 
  GetData(); 

  int red = 0;
int blue = 0;
int green = 0;


}

*/

//must avoid BLACK coloured obstacles 
//needs to differentiate between red and green coloured paths 
