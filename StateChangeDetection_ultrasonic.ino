const int buttonPin = 7;
const int trigPin = 9;
const int echoPin = 10;
const int LED = 6;
const int BUZZER = 11;

int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;

float duration, distance;


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
    } else {
    }
    delay(50);
  }
  
  lastButtonState = buttonState;
  
  if (buttonPushCounter % 4 == 0) {
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2);  
    digitalWrite(trigPin, HIGH);  
    delayMicroseconds(10);  
    digitalWrite(trigPin, LOW); 

    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(100);

      if (distance < 20) {
          digitalWrite(LED, HIGH);
          tone(BUZZER, 255);
        }
      else {
          digitalWrite(LED, LOW);
          noTone(BUZZER);
        }
    
  } else {
    
  }
}
