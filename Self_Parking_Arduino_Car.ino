//Libraria folosita pentru Shield-ul Motor
#include<AFMotor.h>

//Declaram cele doua motoare (Folosim 2 si 3)
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);



const int TRIGGER_PIN = A0;
const int ECHO_PIN = A1;

const int TRIGGER_PIN2 = A2;
const int ECHO_PIN2 = A3;

const int TRIGGER_PIN3 = A4;
const int ECHO_PIN3 = A5;

int led = 2; 


void setup() {
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  
  Serial.begin(9600);
  pinMode (TRIGGER_PIN, OUTPUT);
  pinMode (ECHO_PIN, INPUT);
  pinMode (TRIGGER_PIN2, OUTPUT);
  pinMode (ECHO_PIN2, INPUT);
  pinMode (TRIGGER_PIN3, OUTPUT);
  pinMode (ECHO_PIN3, INPUT);

  pinMode(led, OUTPUT); // Declare the LED as an output

}

void loop() {
  unsigned long duration,duration2,duration3;
  float distance,distance2,distance3;
//
//  //Ultrasonic 1 ( In fata)
//  digitalWrite(TRIGGER_PIN, HIGH);
//  delayMicroseconds(1000);
//  digitalWrite(TRIGGER_PIN, LOW);
//  duration = pulseIn (ECHO_PIN, HIGH);
//  distance = (duration / 2.0) / 29.0;
//  Serial.print("Distanta senzor 1 = ");
//  Serial.print(distance);
//  Serial.println(" cm");
//  delay(1000);

  //Ultrasonic 2 (In lateral)
  digitalWrite(TRIGGER_PIN2, HIGH);
  delayMicroseconds(1000);
  digitalWrite(TRIGGER_PIN2, LOW);
  duration2 = pulseIn (ECHO_PIN2, HIGH);
  distance2 = (duration2 / 2.0) / 29.0;
  Serial.print("Distanta senzor 2 = ");
  Serial.print(distance2);
  Serial.println(" cm");
  delay(1000);

//  //Ultrasonic 3 (In spate)
//  digitalWrite(TRIGGER_PIN3, HIGH);
//  delayMicroseconds(1000);
//  digitalWrite(TRIGGER_PIN3, LOW);
//  duration3 = pulseIn (ECHO_PIN3, HIGH);
//  distance3 = (duration3 / 2.0) / 29.0;
//  Serial.print("Distanta senzor 3 = ");
//  Serial.print(distance3);
//  Serial.println(" cm");
//  delay(1000);

  if(distance2 < 12 && distance2 > 8){
      digitalWrite(led, HIGH); // Turn the LED on

      delay(4000);

         //MERGI INAINTE
        motor2.run(BACKWARD);
        motor3.run(FORWARD);
        delay(2000);
        motor2.run(RELEASE);
        motor3.run(RELEASE);
        delay(1000);

        //parcheaza
   //manevra1 
  motor2.run(FORWARD);
  delay(680);
  motor2.run(RELEASE);
  delay(1000);

   //manevra2 -> mergi inapoi
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  delay(1000);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  delay(1000);

  // manevra3
  motor3.run(BACKWARD);
  delay(820);
  motor3.run(RELEASE);
  motor2.run(RELEASE);
  delay(1000);
//
//  // manevra 4 -> mergi inainte 12cm 
//  motor2.run(BACKWARD);
//  motor3.run(FORWARD);
//  delay(400);
//  motor3.run(RELEASE);
//  motor2.run(RELEASE);
//  delay(1000);

  //Citeste distantele de la cei doi senzori

  //Ultrasonic 1 ( In fata)
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(1000);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn (ECHO_PIN, HIGH);
  distance = (duration / 2.0) / 29.0;
//  Serial.print("Distanta senzor 1 = ");
//  Serial.print(distance);
//  Serial.println(" cm");
  //delay(1000);

    //Ultrasonic 3 (In spate)
  digitalWrite(TRIGGER_PIN3, HIGH);
  delayMicroseconds(1000);
  digitalWrite(TRIGGER_PIN3, LOW);
  duration3 = pulseIn (ECHO_PIN3, HIGH);
  distance3 = (duration3 / 2.0) / 29.0;
//  Serial.print("Distanta senzor 3 = ");
//  Serial.print(distance3);
//  Serial.println(" cm");
  //delay(1000);

  if(distance > distance3){
    //MERGI INAINTE

    float distantaDeParcurs = (distance - distance3)/2;
    float timpulDeParcurgere = distantaDeParcurs * 33.3;
        motor2.run(BACKWARD);
        motor3.run(FORWARD);
        delay(timpulDeParcurgere);
        motor2.run(RELEASE);
        motor3.run(RELEASE);
        delay(1000);
  }else if(distance < distance3){
    
   float distantaDeParcurs = (distance3 - distance)/2;
   float timpulDeParcurgere = distantaDeParcurs * 33.3;
        motor2.run(BACKWARD);
        motor3.run(FORWARD);
        delay(timpulDeParcurgere);
        motor2.run(RELEASE);
        motor3.run(RELEASE);
        delay(1000);  
  }
       
      
  }else{
    digitalWrite(led, LOW); // Turn the LED on
  }
}
