#ifndef SENSOR_H
#define SENSOR_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize sensor module with GPIO
 */
void sensor_init(void);

/**
 * @brief Read temperature data
 */
float sensor_read_temperature(void);

/**
 * @brief Read humidity data
 */
float sensor_read_humidity(void);

/**
 * @brief Read all sensor data and display
 */
void sensor_read_all_data(void);

#ifdef __cplusplus
}
#endif

#endif // SENSOR_H