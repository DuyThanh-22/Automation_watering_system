#include<stdio.h>
#include"config.h"



void led_system_control(LED_SYSTEM* led)
{
    if(*led == GREEN) 
    {
        printf("LED GREEN: ON\n");
    }else if (*led == RED) 
    {
        printf("LED RED: ON\n");
    }else{
        printf("LED error\n");
        *led = RED;
    }
}


void led_warning_humidity(SENSOR sensor, PUMP_STATE pump, LED_WATERING* led)
{
    if(sensor.humidity<45 && pump == PUMP_OFF)
    {
        *led = YELLOW;
        printf("LED YELLOW: ON");
    }else if(pump == PUMP_ON)
    {
        *led = BLUE;
        printf("LED BLUE: ON\n");
    }else
    {
        *led = OFF;
        printf("LED YELLOW AND LED BLUE OFF\n");
    }
}