#include<stdio.h>
#include"config.h"


void switch_mode(CURRENT_MODE* mode, PUMP_STATE pump)
{
    if(*mode == MODE_AUTO)
    {
        if(pump == PUMP_OFF)
        {
           *mode = MODE_MANUAL;
            printf("Current mode: MANUAL\n");
        }  
    }else
    {
        *mode = MODE_AUTO;
        printf("Current mode : AUTO\n");
    }
}


void pump_manual (PUMP_STATE* pump)
{
    if(*pump == PUMP_OFF)    
    {
        turn_pump_on(pump);
    }else if (*pump == PUMP_ON)
    {
        turn_pump_off(pump);
    }else
    {
         turn_pump_off(pump);
    }
}