#include <stdio.h>
#include "pico/stdlib.h"
#include "picoOled.h"
#include "tof.h"

#define I2C_SDA_PIN         14
#define I2C_SCL_PIN         15
#define SIG_SERVO_PIN       16

#define OLED_ADDR           0x3C
#define VL53L0X_ADDR        0x29

t_OledParams oled;

int main()
{
    stdio_init_all();

    // Configuración OLED

    oled.i2c = i2c1;
    oled.SDA_PIN = I2C_SDA_PIN;
    oled.SCL_PIN = I2C_SCL_PIN;

    oled.ctlrType = CTRL_SH1106;
    oled.i2c_address = OLED_ADDR;
    oled.height = H_64;
    oled.width = W_128;

    oledI2cConfig(&oled);

    // Configuración VL53L0X

    if (!tofInit(1, VL53L0X_ADDR, 0))
    {
        printf("Error inicializando VL53L0X\n");

        while (true)
        {
            sleep_ms(1000);
        }
    }

    printf("VL53L0X inicializado correctamente\n");


    // Programa principal

    while (true)
    {
        int distancia = tofReadDistance();

        oledClear(&oled, BLACK);

        oledPrintfXy(&oled, 0, 0, "Distancia:");

        if (distancia >= 0)
        {
            oledPrintfXy(&oled, 0, 20, "%d mm", distancia);
        }
        else
        {
            oledPrintfXy(&oled, 0, 20, "ERROR");
        }

        oledDisplay(&oled);

        sleep_ms(100);
    }

   
}
