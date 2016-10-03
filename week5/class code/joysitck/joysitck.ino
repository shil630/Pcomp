int joyPinX = A0;
int joyXVal = 0;

int joyPinY = A1;
int joyYVal = 0;

int ledPin = 9;
int ledVal = 0;

int waitTime = 0;
unsigned long lastBlinkTime = 0;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
   joyXVal = analogRead(joyPinX);
   joyYVal = analogRead(joyPinY);

   Serial.println(joyXVal);
   Serial.println(joyYVal);
   delay(100);

   ledVal = map(joyXVal, 0, 1023, 0, 255);
   waitTime = map(joyYVal, 0, 1023, 100, 1000);

   if (millis() - lastBlinkTime > waitTime) {
     if( ledVal > 0){
         ledVal = LOW;
      } 

      lastBlinkTime = millis();
    }

    analogWrite(ledPin, ledVal);

}
