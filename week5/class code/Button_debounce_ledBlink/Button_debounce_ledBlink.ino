int buttonPin = 5;
int ledPin = 9;
int ledVal = 0;

int debounceWait = 10;

//state 0: off,  1: on, 3:Blink
int state = 0;

int blinkWaitTime = 100;
unsigned long lastBlinkTime = 0;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

}

void loop() {

  int oldButtonVal = digitalRead(buttonPin);
  delay(debounceWait);
  int newButtonVal = digitalRead(buttonPin);

  if(oldButtonVal != newButtonVal ) {

    if(newButtonVal == LOW) {
      state ++;
      
        if (state > 2){
            state = 0;
          }
      
      }  
    
    }

  if(state == 0){
    
      ledVal = LOW;
    } else if (state == 1){
      ledVal = HIGH;
    } else {
      
      if (millis() - lastBlinkTime > blinkWaitTime){
        if(ledVal == HIGH) {
             ledVal = LOW;
          } else {
             ledVal = HIGH;    
          }
        
        lastBlinkTime = millis();
        }
    }

    digitalWrite(ledPin, ledVal);

}
