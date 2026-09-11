#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware.h"
#include "picoOled.h"
#include "tof.h"


int main()
{
   
    init_config();

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
