
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPLOcjYUTCK"
#define BLYNK_DEVICE_NAME "Distance"
#define BLYNK_AUTH_TOKEN "o41HVzlgzt9nliYsKfWeqDD9BCRIasKC"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "o41HVzlgzt9nliYsKfWeqDD9BCRIasKC";

char ssid[] = "Sadat";
char pass[] = "#s@d@t##";

#define echoPin1 5        //D1
#define trigPin1 16       //D0
#define buzzer 14         //D5

#define echoPin2 4         //D2
#define trigPin2 0         //D3
#define led 12            //D6

long duration1;
int distance1; 
int safetyDistance1;

long duration2;
int distance2; 
int safetyDistance2;

void ultrasonic1()
{
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
    duration1 = pulseIn(echoPin1, HIGH);
    distance1 = duration1 * 0.034 / 2;

    safetyDistance1 = distance1;

if (safetyDistance1 <= 10){
  digitalWrite(buzzer, HIGH); 

}
else{
  digitalWrite(buzzer, LOW);

}

    Serial.print("Distance: ");
    Serial.println(distance1);
    Blynk.virtualWrite(V0, distance1);

    delay(100);
}

void ultrasonic2()
{
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    duration2 = pulseIn(echoPin2, HIGH);
    distance2 = duration2 * 0.034 / 2;

    safetyDistance2 = distance2;

if (safetyDistance2 <= 10){
  digitalWrite(led, HIGH); 

}
else{
  digitalWrite(led, LOW);

}

    Serial.print("Distance: ");
    Serial.println(distance2);
    Blynk.virtualWrite(V1, distance2);

    delay(100);
}

void setup()
{

  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  pinMode(34, OUTPUT);
  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT); 
  pinMode(buzzer, OUTPUT);

  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2, INPUT); 
  pinMode(led, OUTPUT);
   
  delay(100);
}

void loop()
{ 
  Blynk.run();
  ultrasonic1();
  ultrasonic2();
}
