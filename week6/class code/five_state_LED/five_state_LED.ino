


//-----LED variables-----
int led1Pin = 9;
int led2Pin = 10;
int led1Brightness = 0;
int led2Brightness = 0;
bool ledState = false;  //this one's only used in state=2
int blinkWait = 0;
unsigned long lastBlinkTime = 0;

//-----Button variables-----
int debounceWait = 10;
int buttonPin = 5;

//-----Pot variables-----
int potVal = 0;
int potPin = A0;


//-----STATE variable-----
//0 = all OFF
//1 = all ON
//2 = strobe
//3 = fade
//4 = LED select
int state = 0;




void setup() {
  Serial.begin(9600);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);


}

void loop() {

  //---------------BUTTON DEBOUNCING---------------

  int oldButtonState = digitalRead(buttonPin);
  delay(debounceWait);
  int newButtonState = digitalRead(buttonPin);

  //if we've got a button pressed situation
  if (newButtonState == LOW) {

    //AND it's different from before the debounceWait
    if (newButtonState != oldButtonState) {

      state++;

      if (state > 4) {
        state = 0;
      }

    }

  }

  //---------------POT READING---------------
  potVal = analogRead(potPin);


  //---------------HANDLING STATES---------------
  if (state == 0) {

    //LED Off
    led1Brightness = 0;
    led2Brightness = 0;

  } else if (state == 1) {

    led1Brightness = 255;
    led2Brightness = 255;

  } else if (state == 2) {

    //blink the LED using a timer, but based the
    //timer interval on the state of the pot
    blinkWait = map(potVal, 0, 1023, 200, 2000);

    //Use a timer to blink the LED
    if (millis() - lastBlinkTime > blinkWait) {

      ledState = !ledState;

      lastBlinkTime = millis();
    }

    //the blink code flips a boolean
    //but our led writing code needs an analog value
    if (ledState == true) {
      led1Brightness = 255;
      led2Brightness = 255;
    } else {
      led1Brightness = 0;
      led2Brightness = 0;
    }


  } else if (state == 3) {

    //LED brightness depends on Pot Value
    led1Brightness = map(potVal, 0, 1023, 0, 255);
    led1Brightness = map(potVal, 0, 1023, 0, 255);  
    
  } else if (state == 4) {

    if(potVal < 512){
      led1Brightness = 255;
      led2Brightness = 0;
    } else {
      led1Brightness = 0;
      led2Brightness = 255;
    }

  
  }



  //Now we actually write the values to the LED
  analogWrite(led1Pin, led1Brightness);
  analogWrite(led2Pin, led2Brightness);

}







