#include <stdio.h>
#include<unistd.h>
#include<conio.h>
#include"config.h"

int main() {
    
    volatile CURRENT_MODE current_mode = MODE_AUTO;
    PUMP_STATE pump_state = PUMP_OFF;
    SENSOR sensor;
    LED_SYSTEM led_system = GREEN;
    LED_WATERING led_watering = OFF;   
    int watering_time = 0;
    char check_button;

    printf("Set GPIO pin for sensors, pump, LED, buttons");

    while(1)
    {
        read_sensors(&sensor);
        led_system_control(&led_system);
        led_warning_humidity(sensor,pump_state, &led_watering);
        
        
        if (kbhit()) 
        {                                            // kiểm tra có phím bấm chưa
            check_button = getch();                                            // đọc phím
            if (check_button == ' ') {                                           // bấm SPACE để đổi mode
             switch_mode(&current_mode, pump_state);
            }                          
        }

        if(current_mode == MODE_AUTO)
        {
            pump_auto(sensor, &pump_state, &watering_time);
        }else if(current_mode == MODE_MANUAL)
        {
            if (kbhit()) 
            {                                            // kiểm tra có phím bấm chưa
               check_button = getch();                                            // đọc phím
               if (check_button == '+') 
               {                                           
                   pump_manual(&pump_state);
               }                          
        }                     
            
        }else   
        {
        printf("Current mode: unknown\n");
        turn_pump_off(&pump_state);
        current_mode = MODE_MANUAL;
        }

        sleep(10);
        watering_time += 10;
    }
    return 0;
}