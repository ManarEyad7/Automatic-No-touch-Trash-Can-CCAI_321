#include <Servo.h>
const int trigPin = 5;
const int echoPin = 6;
Servo servo; 

void setup() { 
  
  Serial.begin(9600);
   pinMode(trigPin, OUTPUT); 
   pinMode(echoPin, INPUT); 
   servo.attach(7);
}
void loop() { 
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration= pulseIn(echoPin, HIGH);
  distance= (duration/2) / 29.1; 
  if (distance < 40) {
    servo.write(0);
    delay(1500);
    } else {
      servo.write(180);
    }
      delay(500);
}