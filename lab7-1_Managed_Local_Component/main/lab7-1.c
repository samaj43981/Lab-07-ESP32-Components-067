#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "sensor.h"

static const char *TAG = "LAB7-1";

void app_main(void)
{
    ESP_LOGI(TAG, "🚀 Lab 7-1: Local Component Demo Started");
    
    // เรียกใช้ฟังก์ชันจาก local component
    sensor_init();
    
    while(1) {
        sensor_read_data();
        sensor_check_status();
        
        ESP_LOGI(TAG, "----------------------------");
        vTaskDelay(pdMS_TO_TICKS(3000));
    }
}