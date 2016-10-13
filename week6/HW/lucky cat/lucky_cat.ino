#include <Servo.h>

int ledPin1 = 5;
int ledPin2 = 6;

int photoPin = A0;
int photoVal = 0;

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  

}

void loop() {

  photoVal = analogRead(A0);
//  Serial.println(photoVal);
//  delay(15);

  if (photoVal < 30) {
    
    cat(); 
    
  } else {

    noCat();
    
  }

}

void cat () {

  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);

  myServo.write(0);
  delay(1000);
  myServo.write(40);
  delay(1000);
  
}

void noCat() {
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
}



