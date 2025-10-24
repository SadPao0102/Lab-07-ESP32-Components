#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "sensor.h"
#include "display.h"

static const char *TAG = "LAB7-1";

void app_main(void)
{
    ESP_LOGI(TAG, "🚀 Lab 7-1: Local Component Demo Started");
    
    // --- Sensor ---
    sensor_init();
    
    // --- Display ---
    display_init();
    display_show_message("Hello Lab 7!");
    
    while(1) {
        
        sensor_read_data();
        sensor_check_status();
        
        display_show_data(34.6f, 73.9f); 
        display_clear_screen();
        
        ESP_LOGI(TAG, "----------------------------");
        vTaskDelay(pdMS_TO_TICKS(3000)); 
    }
}