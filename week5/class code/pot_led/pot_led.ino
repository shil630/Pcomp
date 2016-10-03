int potVal = 0;
int potPin = A0;

int ledPin = 9;
int ledVal = 0;


void setup() {

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  potVal = analogRead(potPin);
   ledVal = map(potVal, 1,1023, 0, 255);

  analogWrite(ledPin, ledVal);

}
