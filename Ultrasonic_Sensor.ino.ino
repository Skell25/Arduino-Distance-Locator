#include <Servo.h>
//pins for the Ultrasonic sound sensor
const int trigPin = 8;
const int echoPin = 9;

//pin for he buzzer, buzzer will go high once the echopin turns high (pulse wave has been recieved)
const int buzzer = 5;
const int servoPin = 4;

//setting up the pin number for the servo motor
Servo myservo;
int pos = 0;

//partially setting up parameters for the measuring the distance of objects
float duration, distance;


void setup() {

// the trigger (what sends the sound signal is connected to pin 8 and is an output, while echo (connected to the 9 pin is an input and recieves the sound signal)
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

//setting the buzzer as an output
pinMode(buzzer, OUTPUT);

//setting the servo motor as an output;
myservo.attach(servoPin);
myservo.write(0);

Serial.begin(9600); 
}

void loop() {

//setting the trigger pin for the ultra sound to low for 2 microseconds, then after that we set it to high for 10 microseconds to send a sound pulse, then set it back to low
digitalWrite(trigPin, LOW);  
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);  
delayMicroseconds(10);  
digitalWrite(trigPin, LOW); 


long duration = pulseIn(echoPin, HIGH);//once a pulse has been recieved the echo pin will be set on (set to high)
int distance = (duration / 2) / 29.1;//Calculating the distance (speed of sound is 340m/s or 0.034 cm/us)

//setting up the conditions for the buzzer to turn high, it will be in a if loop and the conditions for the buzzer starting are: if the object deteced by the ultrasonic radar is within 0cm and 30cm, and the echoPin turns on, aka if the sound pulse has been receieved after it has been transsmitted
if (distance > 0 && distance <= 30) {
  digitalWrite(buzzer, HIGH); 
  myservo.write(90);
}
else {
  digitalWrite(buzzer, LOW);
  myservo.write(0);
}
delay(200);
}
  
   
  
