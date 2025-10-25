#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"

static const char *TAG = "LAB6_1";

void app_main(void)
{
    ESP_LOGI(TAG, "Lab 6.1: Basic ESP32 Project Structure");
    ESP_LOGI(TAG, "ESP-IDF Version: %s", esp_get_idf_version());
    ESP_LOGI(TAG, "Free heap size: %d bytes", esp_get_free_heap_size());
    
    int counter = 0;
    
    while (1) {
        ESP_LOGI(TAG, "Build system test - Counter: %d", counter++);
        vTaskDelay(pdMS_TO_TICKS(2000)); // 2 seconds delay
    }
}