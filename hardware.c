#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware.h"
#include "tof.h"

//Variable globales
t_OledParams oled;
static uint slice;  //del PWM
static uint channel; //PWM

void init_config(){
     stdio_init_all();

    // Config OLED

    oled.i2c = i2c1;
    oled.SDA_PIN = I2C_SDA_PIN;
    oled.SCL_PIN = I2C_SCL_PIN;

    oled.ctlrType = CTRL_SH1106;
    oled.i2c_address = OLED_ADDR;
    oled.height = H_64;
    oled.width = W_128;

    oledI2cConfig(&oled);

    // Config VL53L0X

    if (!tofInit(1, VL53L0X_ADDR, 0))
    {
        printf("Error inicializando VL53L0X\n");

        while (true)
        {
            sleep_ms(1000);
        }
    }

    printf("VL53L0X inicializado correctamente\n");

    //Config PWM
    gpio_set_function(SIG_SERVO_PIN, GPIO_FUNC_PWM);
    slice = pwm_gpio_to_slice_num(SIG_SERVO_PIN);
    channel = pwm_gpio_to_channel(SIG_SERVO_PIN);
    pwm_set_clkdiv(slice, SERVO_DIV);
    pwm_set_wrap(slice, SERVO_TOP);
    angulo_servo(0);
    pwm_set_enabled(slice, true);
}

void angulo_servo(uint angulo)
{
    if (angulo > 180) angulo = 180;

    uint pulse_us = 1000 + (angulo * 1000 / 180);

    uint16_t level = (pulse_us * SERVO_TOP) / SERVO_PERIODO_US;

    pwm_set_chan_level(slice, channel, level);
}

