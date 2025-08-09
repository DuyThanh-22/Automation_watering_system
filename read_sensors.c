#include<stdio.h>
#include"config.h"



void read_sensors(SENSOR* sensor)
{
    scanf("%f %d",&sensor->temperature,&sensor->humidity);
    
    printf("Temperature: %f\u00B0C\n",sensor->temperature);
    printf("Humidity: %d%%\n",sensor->humidity);
}