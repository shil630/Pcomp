int buttonPin = 5;
int potPin = A0;
int ledPin1 = 9;
int ledPin2 = 10;
int ledPin3 = 11;

int potVal = 0;
int ledVal1 = 0;
int ledVal2 = 0;
int ledVal3 = 0;

int debounceWait = 5;

int state = 0;

int blinkWaitTime = 0;

unsigned long lastBlinkTime = 0;

void setup() {

  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  
}

void loop() {
  
  //set pot value
  potVal = analogRead(potPin);

  //check button state 
  //debounce
  int oldButtonVal = digitalRead(buttonPin);
  delay(debounceWait);
  int newButtonVal = digitalRead(buttonPin);

  //make 5 states
  if (oldButtonVal != newButtonVal) {

    if (newButtonVal == LOW) {

      state++;

      if (state > 4) {
        state = 0;
      }

    } 

  }

  //state 0: all low, 1: all high, 2: pot-controled blink
  //3: pot_controled which led, 4: pot-controled brightness
  if (state == 0) {

    ledVal1 = LOW;
    ledVal2 = LOW;
    ledVal3 = LOW;
    
  } else if (state == 1) {

    ledVal1 = HIGH;
    ledVal2 = HIGH;
    ledVal3 = HIGH;
    
  } else if (state == 2) {
    
    blinkWaitTime = map(potVal, 0, 1023, 50, 1500);

    if (millis() - lastBlinkTime > blinkWaitTime) {
      
      if (ledVal1 == HIGH) {
        ledVal1 = LOW;
        ledVal2 = LOW;
        ledVal3 = LOW;
      } else {
        ledVal1 = HIGH;
        ledVal2 = HIGH;
        ledVal3 = HIGH;
        
      }

      lastBlinkTime = millis();
    }
    
  } else if (state == 3) {

    if (potVal < 341) {

      ledVal1 = HIGH;
      ledVal2 = LOW;
      ledVal3 = LOW;
    
    } else if (potVal > 341 && potVal < 682) {

      ledVal1 = LOW;
      ledVal2 = HIGH;
      ledVal3 = LOW;
      
    } else if(potVal > 682 && potVal < 1024) {
    
      ledVal1 = LOW;
      ledVal2 = LOW;
      ledVal3 = HIGH;      
      
    }
  
  }
  
  else {

    ledVal1 = map(potVal, 0, 1023, 0, 255);
    ledVal2 = map(potVal, 0, 1023, 0, 255);
    ledVal3 = map(potVal, 0, 1023, 0, 255);

  }

  //make 2 write methods
  if (state <= 3) {
    
    digitalWrite(ledPin1, ledVal1);
    digitalWrite(ledPin2, ledVal2);
    digitalWrite(ledPin3, ledVal3);
    
  } else {
    
    analogWrite(ledPin1, ledVal1);
    analogWrite(ledPin2, ledVal2);
    analogWrite(ledPin3, ledVal3);
    
  }
  
}




