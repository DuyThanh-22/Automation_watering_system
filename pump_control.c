#include<stdio.h>
#include"config.h"



void turn_pump_on (PUMP_STATE* pump)
{
    printf("Pump state: ON\n");
    *pump = PUMP_ON;
}



void turn_pump_off (PUMP_STATE* pump)
{
    printf("Pump state: OFF\n");
    *pump = PUMP_OFF;
}




void pump_auto(SENSOR sensor, PUMP_STATE* pump, int* time)
{
    if(sensor.temperature> Suitable_temperature )
    {
        printf("Temperature is not suitable for watering");
    }else
    {
        if(*pump == PUMP_OFF)
        {
            if(sensor.humidity < 45 ) 
            {
                turn_pump_on(pump);
                *time = 0;
            }
        }else if (*pump == PUMP_ON)
        {
            if(sensor.humidity > 70 && *time > 1000 ) turn_pump_off(pump);
        }else
        {
            turn_pump_off(pump);
        }
    }
}


