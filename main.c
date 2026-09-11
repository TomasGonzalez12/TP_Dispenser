#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware.h"
#include "picoOled.h"
#include "tof.h"


int main()
{
   
    init_config();

    //Esto es solamente una prueba a ver si anda todo!
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

        angulo_servo(0);
        sleep_ms(100);
        angulo_servo(90);
        sleep_ms(100);
        angulo_servo(180);
        sleep_ms(100);

    }

   
}
