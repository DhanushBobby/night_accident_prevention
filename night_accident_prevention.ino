#define Eyeblinkpin 4                         // defining eye blink sensor pin
#define echoPin 9                         |  // denifing distance
#define tringPin 10                       | //                    sensor pins
long duration;
int distance;
int ledPin = 2;                             // sets the LED   @pin 2
int buzzerledPin = 5;                      // sets the buzzer @pin 5
int enginePin = 12;                       // sets the fan     @pin 12
int engine2Pin = 13;                     // sets the fan      @pin 13
void setup() {
  pinMode(Eyeblinkpin, INPUT);            //sets the eye bink sensor as input
  pinMode(ledPin, OUTPUT);               //sets the led as              output
  pinMode(tringPin, OUTPUT);            // Sets the trigPin as          output
  pinMode(echoPin, INPUT);             // Sets the echoPin as           input
  pinMode(buzzerledPin,OUTPUT);       //Sets the buzzer led as          output
  pinMode(enginePin, OUTPUT);        // Sets the engine as              output
  pinMode(engine2Pin, OUTPUT);      // Sets the engine as               output
}
void loop() {
  int EyeblinkValue = digitalRead(Eyeblinkpin); //reads the eye  bink sensor signal
  if (EyeblinkValue == LOW){                   //if eye opens
    digitalWrite(enginePin, LOW);             //engine won't stop
    digitalWrite(engine2Pin,LOW);            //engine won't stop
    int duration, distance;
digitalWrite(tringPin, HIGH);
delay(1);
digitalWrite(tringPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance <= 70 && distance >= 0) {
digitalWrite(ledPin, LOW);
digitalWrite(enginePin, LOW);              //engine won't stop
digitalWrite(engine2Pin,LOW);             //engine won't stop
} else {
digitalWrite(ledPin, LOW);
digitalWrite(enginePin, LOW);           //engine won't stop
digitalWrite(engine2Pin,LOW);          //engine won't stop
}
delay(150);
    digitalWrite(buzzerledPin,LOW);
  }
 else{                                   //otherwise (if eye closes)
    int duration, distance;
digitalWrite(tringPin, HIGH);
delay(1);
digitalWrite(tringPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance <= 70 && distance >= 0) {
digitalWrite(ledPin, HIGH);
digitalWrite(enginePin, HIGH);          // engine stops
digitalWrite(engine2Pin,HIGH);         // engine stops
} else {
digitalWrite(ledPin, LOW);
digitalWrite(enginePin, LOW);           //engine won't stop
digitalWrite(engine2Pin,LOW);          //engine won't stop
digitalWrite(buzzerledPin,LOW);
}
delay(150);
    digitalWrite(buzzerledPin,HIGH);   // buzzer starts working
  } 
  delay(150);                         //delay of 300milliseconds
}
