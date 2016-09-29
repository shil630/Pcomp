int ledPin = 9;

int waitTime;
unsigned long lastBlinkTime = 0;

bool ledState = true;

int buttonPin = 5;
int debounceDelay = 10;

int checker = 0;


void setup() {

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
}

void loop() {

  int oldButtonState = 0;
  int newButtonState = 0;

  unsigned long currentTime = millis();

  oldButtonState = digitalRead(buttonPin);
  delay(debounceDelay);
  newButtonState = digitalRead(buttonPin);

  if (oldButtonState != newButtonState) {

    if (newButtonState == LOW) {
       checker ++ ;
    }
  }

  //check the button state
  if(checker % 2 == 0) {
    waitTime=1000;
  }else{ 
    waitTime = 100;
     }
     
  //make the led blink
  if (currentTime - lastBlinkTime > waitTime) {
    
    ledState = !ledState;
    lastBlinkTime = millis();

  }

  //control the led based on the ledState boolean
  if (ledState) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

}
