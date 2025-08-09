#define Max_humidity 70
#define Min_humidity 45
#define Suitable_temperature 35
#define Max_watering_time 1000





typedef struct
    {
        float temperature;
        int humidity;
    }SENSOR;


typedef enum
{
    MODE_AUTO,
    MODE_MANUAL
}CURRENT_MODE;


typedef enum 
{
    PUMP_OFF,
    PUMP_ON
}PUMP_STATE;

typedef enum
{
    RED,                       //LED_ERROR              (System is error)
    GREEN                      //LED_NORMAL             (System is normal) 
    
}LED_SYSTEM;

typedef enum
{
    YELLOW,                    //LED_LOW_MOISTURE_ALERT (Humidity is very low)
    BLUE,                      //LED_WATERING           (The system is watering)
    OFF                        //OFF_LED                (Humidity is suitable)
}LED_WATERING;



void read_sensors(SENSOR* sensor);

void turn_pump_on (PUMP_STATE* pump);
void turn_pump_off (PUMP_STATE* pump);
void pump_auto(SENSOR sensor, PUMP_STATE* pump, int* time);

void led_system_control(LED_SYSTEM* led);
void led_warning_humidity(SENSOR sensor, PUMP_STATE pump, LED_WATERING* led);

void switch_mode (CURRENT_MODE* mode, PUMP_STATE pump);
void pump_manual (PUMP_STATE* pump);