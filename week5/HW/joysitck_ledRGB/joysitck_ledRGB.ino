int joyPinX = A0;
int joyXVal = 0;

int joyPinY = A1;
int joyYVal = 0;

int ledPinB = 9;
int ledValB = 0;

int ledPinR = 11;
int ledValR = 0;

int ledPinG = 10;
int ledValG = 0;


void setup() {
  Serial.begin(9600);
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinB, OUTPUT);

}

void loop() {
   joyXVal = analogRead(joyPinX);
   joyYVal = analogRead(joyPinY);

   Serial.println(joyXVal);
   Serial.println(joyYVal);
//   delay(100);

   ledValR = map(joyXVal, 0, 1023, 1, 225);
   ledValG = map(joyYVal, 0, 1023, 1, 225);
   ledValB = map(joyYVal, 0, 1023, 255, 1);
   
    analogWrite(ledPinR, ledValR);
    analogWrite(ledPinG, ledValG);
    analogWrite(ledPinB, ledValB);

}
