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
        angulo_servo(0);
        sleep_ms(100);
        angulo_servo(180);
        sleep_ms(100);
    }

   
}
