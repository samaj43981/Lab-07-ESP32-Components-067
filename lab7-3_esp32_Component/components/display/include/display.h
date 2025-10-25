#ifndef DISPLAY_H
#define DISPLAY_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize display module
 */
void display_init(void);

/**
 * @brief Show sensor data on display
 */
void display_show_sensor_data(float temperature, float humidity, float heat_index);

/**
 * @brief Show system status
 */
void display_show_status(const char* status);

/**
 * @brief Clear display
 */
void display_clear(void);

#ifdef __cplusplus
}
#endif

#endif // DISPLAY_H