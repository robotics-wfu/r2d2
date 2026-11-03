#include <NewPing.h> //ultrasonic reading library 
#include "motorMethods.h"

#define BAUD_RATE 115200


//TODO all of these numbers are made up
#define PIN_MOTOR_0_CONTROL_1 32
#define PIN_MOTOR_0_CONTROL_2 33
#define PIN_MOTOR_0_PWM 25
#define PIN_MOTOR_1_CONTROL_1 26
#define PIN_MOTOR_1_CONTROL_2 27
#define PIN_MOTOR_1_PWM 14

struct Motor motors[2];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUD_RATE); //sets up our serial printing for debugging

  //setting pins in motor structs
  motors[0] = {PIN_MOTOR_0_CONTROL_1, PIN_MOTOR_0_CONTROL_2, PIN_MOTOR_0_PWM};
  motors[1] = {PIN_MOTOR_1_CONTROL_1, PIN_MOTOR_1_CONTROL_2, PIN_MOTOR_1_PWM};

  Serial.println("Setup complete");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    //will only run this block if there is a new serial command

    // **** everything below is just sample stuff ****
    // one format for a serial control while we test the motors could be:
    // <motor index> <speed>
    // where motor index is 0 or 1
    // and speed is between (-255) and 255 
      // where negative is backwards and positive is forwards
      // we can turn a negative or positive integer into the three 
      // required control signals in the motor control method(s?) or right here
      // its just faster to type one thing while testing
    
    //read number input
    uint8_t motorIndex = Serial.parseInt();
    int16_t speed = Serial.parseInt();
    if (motorIndex != 0 && motorIndex != 1) {
      //motor index is not valid
      Serial.printf("Invalid motor index: %d\n", motorIndex);
      return; //this will just start the loop function again
    }
    if (speed > 255 || speed < -255) {
      //speed is not valid
      Serial.printf("Invalid speed: %d\n", speed);
      return;
    }

    Serial.printf("Input received: motor %d at speed %d\n", motorIndex, speed);
    setMotor(&(motors[motorIndex]), speed);
  }

 
  /*
  //print methods
  Serial.println("testing - print one line");
  Serial.print("testing");
  Serial.print(3);
  Serial.print(0.5);
  Serial.printf("printing a number inline: %d\n", 3);
  */

  /*
  //time methods
  unsigned long currTime = millis() //current time in ms
  delay(10); //pause for 10 ms - not seconds
  */

}
