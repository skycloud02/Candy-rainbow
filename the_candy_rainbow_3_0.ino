#include <Servo.h>

#define S0 3
#define S1 5
#define S2 6
#define S3 9
#define sensorOut 10

Servo topServo;
Servo bottomServo;

int frequency = 0;
int color=0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  topServo.attach(12);
  bottomServo.attach(13);

  Serial.begin(9600);
}

void loop() {

  topServo.write(115);
  delay(500);
  
  for(int i = 115; i > 55; i--) {
    topServo.write(i);
    delay(4);
  }
  delay(500);
  
  color = readColor();
  delay(9);  

  switch (color) {
    case 1: //red
    bottomServo.write(2);
    break;
    
    case 2: //orange
    bottomServo.write(10);
    break;

    case 3: //green
    bottomServo.write(35);
    break;

    case 4: //yellow
    bottomServo.write(60);
    break;

    case 5: //brown
    bottomServo.write(90);
    break;

    case 6: //blue
    bottomServo.write(115);
    break;
    
    case 0:
    break;
  }
  delay(300);
  
  for(int i = 65; i > 35; i--) {
    topServo.write(i);
    delay(4);
  } 
  delay(500);
  
  for(int i = 35; i < 115; i++) {
    topServo.write(i);
    delay(3);
  }
  color=0;
}

int readColor() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  Serial.print("R= ");
  Serial.print(frequency);
  Serial.print(" ");
  delay(50);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(50);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency; 
  Serial.print("B= ");
  Serial.print(frequency);
  Serial.println("  ");
  delay(50);

  if(R>145 && R<164 && G>180 && G<200){
    color = 1; // Red
  }
  if(G>155 && G<175 && B>130 && B<150){
    color = 2; // Orange
  }
  if(R>160 && R<176 && G>140 && G<160){
    color = 3; // Green
  }
  if(R>100 && R<120 && G>115 && G<140){
    color = 4; // Yellow
  }
  if(R>175 && R<195 && G>175 && G<195){
    color = 5; // Browon
  }
  if(G>150 && G<175 && B>100 && B<120){
    color = 6; // Blue
  }
  return color;
    
}
