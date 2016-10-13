int ledPin = 9;
int ledVal = 0;
int incrementAmt = 1;

int waitTime = 4;
unsigned long lastTimeCheck = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  if(millis() - lastTimeCheck > waitTime){
    ledVal += incrementAmt;

    if(ledVal > 254){
      incrementAmt = -1;
    }

    if(ledVal < 1){
      incrementAmt = 1;
    }
    
    lastTimeCheck = millis();
  }

  analogWrite(ledPin, ledVal);

}
