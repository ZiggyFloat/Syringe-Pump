#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield ADMS = Adafruit_MotorShield();

//Connect a stepper motorhield with 200 steps per revolution (1.8 degree)
//to motor port #2 (m3 and M4)
Adafruit_StepperMotor *myMotor = ADMS.getStepper(200,2);

#define MICROSTEP 8

void setup() {

  //set up serial library at 9600 bps
  Serial.begin(9600);
  Serial.println("Stepper test");

  //start with default frequecy 1.6KHz
  ADMS.begin();
  //OR with predefined frequency 1KHz
  //ADMS.begin(1000); 

  //set the speed of the motor
  myMotor -> setSpeed(1);
}

//change number of steps, direction and steptype
void loop() {
  Serial.println("Run!");
  myMotor -> step(0, FORWARD, DOUBLE); //enter number of steps, 500 steps is approximately equivalent to 1mL using a 20mL syringe
  myMotor -> step(0, BACKWARD, DOUBLE);
  
  //use // to comment out exit(0) to have a continuos loop of instructions
  exit(0);
}
