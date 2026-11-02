#ifndef MOTOR_METHODS
#define MOTOR_METHODS
//^ keeps the definitions file from running twice
// shouldnt be needed but better safe than sorry

//struct definitions are available to anyone who includes this file
struct Motor {
  uint8_t command1;
  uint8_t command2;
  uint8_t pwm;
};

//static methods are only available in this file (like private methods)
//others are available to anyone who includes this file
static void setMotor(int motorIndex, int8_t speed);
void setLeftMotor(int8_t speed);
void setRightMotor(int8_t speed);

// this line needs to be last on the file
#endif 