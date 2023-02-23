#include "HCMotor.h" //Include HCMotor Code Library
#define MOTOR_PIN 6 // Assign to PWM/Digital Pin 6   

HCMotor HCMotor; // Create an instance of our code library

const int LED=3;

void setup()
{
 
  HCMotor.Init(); //Initialise our library
  HCMotor.attach(0, DCMOTOR, MOTOR_PIN); // Attach our motor to 0 to digital pin 6 
  HCMotor.DutyCycle(0, 100); //Set duty cycle of the PWM Pulse with Modulation signal in 100uS increment to 100uS = 1mS cycle
  pinMode(11, OUTPUT);
  pinMode(12, INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}
  
void loop()
{
 
  long dur;
  long dis;
  long toCm;

  digitalWrite(11, LOW);
  delayMicroseconds(2);
  digitalWrite(11, HIGH);
  delayMicroseconds(10);
  digitalWrite(11, LOW);
  dur = pulseIn(11, HIGH);
  toCm = microSecondsToCentimeters(dur);
  
  if(toCm < 10){
    HCMotor.OnTime(0, 0);
    digitalWrite(LED,HIGH);
  }

  else{
    HCMotor.OnTime(0, 100);
  }
}

long microSecondsToCentimeters(long microseconds)
{
  return(microseconds / 29) / 2;
}