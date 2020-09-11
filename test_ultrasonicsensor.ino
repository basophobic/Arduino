/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial

*/
// defines pins numbers
const int trigPin = 12;
const int echoPin = 13;
const int LED_GREEN = 5 ; 
const int LED_RED = 4 ; 


// defines variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(LED_GREEN, OUTPUT) ; 
  pinMode(LED_RED, OUTPUT) ; 
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
    digitalWrite(LED_GREEN, LOW) ; 
    digitalWrite(LED_RED, LOW) ;

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  //distance= duration*0.034/2;
  distance = (duration/2) / 29.1; 
  if (distance >= 30) {
   digitalWrite(LED_GREEN, HIGH) ; 
   digitalWrite(LED_RED, LOW) ;
  }
  if (distance < 30) {
   digitalWrite(LED_GREEN, LOW) ; 
   digitalWrite(LED_RED, HIGH) ;
  }
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

 

}
