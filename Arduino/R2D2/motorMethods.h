#ifndef MOTOR_METHODS
#define MOTOR_METHODS
//^ keeps the definitions file from running twice

#include <stdint.h>
#include <Arduino.h>

//struct definitions are available to anyone who includes this file
struct Motor {
  uint8_t command1;
  uint8_t command2;
  uint8_t pwm;
};

//static methods are only available in this file (like private methods)
//others are available to anyone who includes this file
void setMotor(struct Motor *motor, int16_t speed);
void setLeftMotor(int8_t speed);
void setRightMotor(int8_t speed);

// this line needs to be last on the file
#endif 