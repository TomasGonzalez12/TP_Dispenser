#ifndef HARDWARE_H
#define HARDWARE_H

#include "picoOled.h"

//Variables
extern t_OledParams oled;

//I2C
#define I2C_SDA_PIN         (14)
#define I2C_SCL_PIN         (15)
#define OLED_ADDR           (0x3C)
#define VL53L0X_ADDR        (0x29)

//PWM
#define SIG_SERVO_PIN       (16)
#define SERVO_FREQ          (50)
#define SERVO_PERIODO_US    (1000000 / SERVO_FREQ)
#define SERVO_TOP           (59999)
#define SERVO_DIV           (50.0f)

//Funciones
void init_config();
void angulo_servo(uint angulo);

#endif