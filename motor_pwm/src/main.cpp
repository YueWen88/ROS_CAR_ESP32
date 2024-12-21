#include <Arduino.h>

#include <McpwmMotor.h>

typedef unsigned char u8;

#define STBY 4
#define KEY2_PRESS  2
#define KEY3_PRESS  3
#define KEY_UNPRESS 4

MCpwmMotor motor;

u8 key_scan(u8 mode)
{
  static u8 key=1;

  if(mode)key=1;//连续扫描按键
  if(key==1&&(digitalRead(38)==0||digitalRead(39)==0))//任意按键按下
  {
    delay(10);//消抖
    key=0;
    if(digitalRead(38)==0)
      return KEY2_PRESS;
    else if(digitalRead(39)==0)
      return KEY3_PRESS;
  }
  else if(digitalRead(38)==1&&digitalRead(39)==1) //无按键按下
  {
    key=1;      
  }
  return KEY_UNPRESS;   
}

void setup() {
  motor.init_motor(0, 15, 7, 6);
  motor.init_motor(1, 8, 18, 17);
  motor.init_motor(2, 46, 3, 20);
  motor.init_motor(3, 12, 11, 10);
  
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, 1);

  pinMode(38, INPUT_PULLUP);
  pinMode(39, INPUT_PULLUP);

  Serial.begin(115200);
}


int pwm = 20;
int i = 0;
void loop() {
  Serial.println(i);
  Serial.println("\n");
  Serial.println(pwm);
  Serial.println("\n");
  u8 key_type = key_scan(0);
  if(key_type == KEY2_PRESS){
    Serial.println("Press");
    if(i == 0){
      motor.update_motor_speed(i, 7, 6, pwm);
    }else if (i == 1)
    {
      motor.update_motor_speed(i, 18, 17, pwm);
    }else if (i == 2)
    {
      motor.update_motor_speed(i, 3, 20, pwm);
    }else if (i == 3)
    {
      motor.update_motor_speed(i, 11, 10, pwm);
      i = -1;
    }
    
    i++;
  }

  if(key_type == KEY3_PRESS){
    pwm = - pwm;
  }
}
