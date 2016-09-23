int ledPin = 9;

//for controlling the button with the timer
int waitTime = 100;
bool ledState = true;
unsigned long lastBlinkTime = 0;    //holds the time of the last time we flipped the LED


void setup() {

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {

  
  //what is the current time...
  unsigned long currentTime = millis();

  //has enough time passed since the last time we blinked?
  if (currentTime - lastBlinkTime > waitTime) {

    //if so, switch the LED
    ledState = !ledState;

    //and note the time so we can know how long has passed
    //the next time we try to blink
    lastBlinkTime = millis();

  }



  //control the led based on the ledState boolean
  if (ledState) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

}
