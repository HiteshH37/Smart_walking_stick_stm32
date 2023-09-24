#define trigPin1 PA0
#define echoPin1 PA1
#define trigPin2 PA2
#define echoPin2 PA3
#define watersig PA4
#define ldr PA5
#define rgb1 PA6
#define rgb2 PA7
#define k -2.143
long duration, distance,m,n,o,voltage;
void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(watersig,INPUT);
pinMode(PB0,OUTPUT);
pinMode(PB1,OUTPUT);
pinMode(ldr,INPUT);
pinMode(rgb1,OUTPUT);
pinMode(rgb2,OUTPUT);
}
void loop() {
//Code for stick operation
o=digitalRead(watersig);
SonarSensor(trigPin1, echoPin1);
m = distance;
SonarSensor(trigPin2, echoPin2);
n = distance;
//voltage=(m-50)*k;
LDR();
if((m<27)||(n>40)||(o==HIGH))
 digitalWrite(PB0,HIGH);
else
 digitalWrite(PB0,LOW);
if(m>20)
{
 if(m<50)
 analogWrite(PB1,voltage);
 else
 digitalWrite(PB1,LOW);
}
//For calibration of ultra sound
Serial.print("ULtra1 = ");
Serial.print(m);
Serial.print("m ");
Serial.print("ULtra2 = ");
Serial.print(n);
Serial.print("m ");
Serial.println();
}
//User defined functions
void SonarSensor(int trigPin,int echoPin)
{
  digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
}
void LDR()
{
 if(analogRead(ldr)<3)
 {
 digitalWrite(rgb1,HIGH);
 delay(50);
 digitalWrite(rgb1,LOW);
 delay(50);
 digitalWrite(rgb2,HIGH);
 delay(50);
 digitalWrite(rgb2,LOW);
 delay(50);
 }
else
{
 digitalWrite(rgb1,LOW);
 digitalWrite(rgb2,LOW);
}
}
