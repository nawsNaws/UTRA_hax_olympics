#define s0 8
#define s1 9
#define s2 10
#define s3 11
#define out 12  

int data = 0; 
int red = 0;
int blue = 0;
int green = 0;

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
  getColours(); 
  
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


//must avoid BLACK coloured obstacles 
//needs to differentiate between red and green coloured paths 
