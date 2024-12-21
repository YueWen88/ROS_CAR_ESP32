#include <McpwmMotor.h>

void MCpwmMotor::init_motor(int num, uint8_t pwm, uint8_t in1, uint8_t in2){
  // pinMode(STBY, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(pwm, OUTPUT);

//复用性太低了，有时间再改改
  if(num == 0){
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, pwm);

    mcpwm_config_t pwm_config;
    pwm_config.frequency = 1000;
    pwm_config.cmpr_a = 0;
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;

    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);
  }else if(num == 1){
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM1A, pwm);

    mcpwm_config_t pwm_config;
    pwm_config.frequency = 1000;
    pwm_config.cmpr_a = 0;
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;

    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_1, &pwm_config);
  }else if(num == 2){
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM2A, pwm);

    mcpwm_config_t pwm_config;
    pwm_config.frequency = 1000;
    pwm_config.cmpr_a = 0;
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;

    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_2, &pwm_config);
  }else if(num == 3){
    mcpwm_gpio_init(MCPWM_UNIT_1, MCPWM0A, pwm);

    mcpwm_config_t pwm_config;
    pwm_config.frequency = 1000;
    pwm_config.cmpr_a = 0;
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;

    mcpwm_init(MCPWM_UNIT_1, MCPWM_TIMER_0, &pwm_config);
  }

  // digitalWrite(STBY, 1);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
}

void MCpwmMotor::update_motor_speed(int num, uint8_t in1, uint8_t in2, int pwmValue){
  if(pwmValue < 0){
      if(digitalRead(in1) == 1 && digitalRead(in2) == 0){
        digitalWrite(in1, 0);
        digitalWrite(in2, 1);
      }else{
        digitalWrite(in1, 1);
        digitalWrite(in2, 0);
      }

      pwmValue = -pwmValue;
  }
  
  if(num == 0){
    mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, pwmValue);
    mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, MCPWM_DUTY_MODE_0);
  }else if(num == 1){
    mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_1, MCPWM_OPR_A, pwmValue);
    mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_1, MCPWM_OPR_A, MCPWM_DUTY_MODE_0);
  }else if(num == 2){
    mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_2, MCPWM_OPR_A, pwmValue);
    mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_2, MCPWM_OPR_A, MCPWM_DUTY_MODE_0);
  }else if(num == 3){
    mcpwm_set_duty(MCPWM_UNIT_1, MCPWM_TIMER_0, MCPWM_OPR_A, pwmValue);
    mcpwm_set_duty_type(MCPWM_UNIT_1, MCPWM_TIMER_0, MCPWM_OPR_A, MCPWM_DUTY_MODE_0);
  }
}