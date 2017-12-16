/* These are the sensors reading variables */
// For SENSORS ANALOG INPUT
 
  int smokesensor = 0;
  int lm35 = 1;
  int lightsensor = 2;
 
  #define LS 3
  #define RS 2

  #define LM1 4
  #define LM2 5
  #define RM1 6
  #define RM2 7

/* These are the output to the connected pins */
// For OUTPUT PINS

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(LS,INPUT);
  pinMode(RS,INPUT);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  pinMode(13, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  int smokesensorvalue=analogRead(smokesensor);
  
  
  int analogvalue;
  float temprature;
  analogvalue= analogRead(lm35);
  temprature= float(analogvalue)/1023;
  temprature= temprature*500;

  int lightsensorvalue = analogRead(lightsensor);
  
  Serial.println("Sensors Data ");
  Serial.print("Smoke Reading(PPM)   :");
  Serial.println(smokesensorvalue);
  Serial.print("Temprature Reading(f):");
  Serial.println(temprature);
  Serial.print("Light Intensity      :");
  Serial.println(lightsensorvalue);

 
  
  if(digitalRead(LS)&&digitalRead(RS)) //$wrd
  {
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
    analogWrite(11,180);
    analogWrite(10,220);
    
  }

  
  if(!(digitalRead(LS))&&digitalRead(RS)) //right
  {
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
    analogWrite(11,180);
    analogWrite(10,220);
    
  }
  
  if(digitalRead(LS)&&!(digitalRead(RS))) //left
  {
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,LOW);
    analogWrite(11,180);
    analogWrite(10,220);
  }
  
  if(!(digitalRead(LS))&&!(digitalRead(RS))) //stop
  {
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,LOW);
    analogWrite(11,180);
    analogWrite(10,220);
  }
   if(lightsensorvalue > 200 or  smokesensorvalue > 430 or temprature > 100 )
  {
  Serial.print("CRUCIAL");
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(100); 
  digitalWrite(LM1,HIGH);
  digitalWrite(LM2,LOW);
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,LOW);
  analogWrite(11,180);
  analogWrite(10,220);
    
  }

  delay(500);
  
}
