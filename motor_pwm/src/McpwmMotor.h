#ifndef __MCPWMMOTOT_H__
#define __MCPWMMOTOT_H__

#include <Arduino.h>
#include "driver/mcpwm.h"

class MCpwmMotor
{
public:
    void init_motor(int num, uint8_t pwm, uint8_t in1, uint8_t in2);
    void update_motor_speed(int num, uint8_t in1, uint8_t in2, int pwmValue);
};

#endif