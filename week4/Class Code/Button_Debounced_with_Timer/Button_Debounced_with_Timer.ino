int ledPin = 9;

//for controlling the button with the timer
bool ledState = true;

//For controlling the state based on the button
int buttonPin = 5;
int debounceTime = 10;
unsigned long lastDebounceTime = 0;


void setup() {

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  //These can be made global or local, doesn't matter much in this case
  int oldButtonState = 0;
  int newButtonState = 0;

  //read the button once, then check if it has been long enough (debounceDelay)
  //since we last checked to check again
  oldButtonState = digitalRead(buttonPin);
  
  if(millis() - lastDebounceTime > debounceDelay){

    newButtonState = digitalRead(buttonPin);
    
    //If the old state and new state are different then we've had a change
    if (oldButtonState != newButtonState) {
    
      //But the change could be the rising edge OR the falling edge. 
      //So we also want to check to make sure the new state is LOW
      //i.e. the button is pressed (LOW = pressed since we're using 
      //the INPUT_PULLUP method of connecting our button)
      if (newButtonState == LOW) {
        //If both those are true then we've succesfully detected the falling edge
        //i.e. the first instance the button is pressed.
        ledState = !ledState;
      }
    }

    //note the time so we know how long it has been the next time we check
    lastDebounceTime = millis();
  }






  //control the led based on the ledState boolean
  if (ledState) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

}
