/**
 * 
 * @copyright Copyright 2021 Espressif Systems (Shanghai) Co. Ltd.
 *
 *      Licensed under the Apache License, Version 2.0 (the "License");
 *      you may not use this file except in compliance with the License.
 *      You may obtain a copy of the License at
 *
 *               http://www.apache.org/licenses/LICENSE-2.0
 *
 *      Unless required by applicable law or agreed to in writing, software
 *      distributed under the License is distributed on an "AS IS" BASIS,
 *      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *      See the License for the specific language governing permissions and
 *      limitations under the License.
 */

#pragma once

#include <stdbool.h>
#include "esp_err.h"
#include "audio_hal.h"
#include "i2c_bus.h"

/**
 * @brief Add dev board pin defination and check target.
 * 
 */

#if CONFIG_ESP32_S3_BOX_BOARD
    #include "esp32_s3_box_board.h"
#elif CONFIG_ESP32_S3_KORVO_1_V4_0_BOARD
    #include "esp32_s3_korvo_1_v4_board.h"
#elif CONFIG_ESP32_KORVO_V1_1_BOARD
    #include "esp32_korvo_v1_1_board.h"
#elif CONFIG_ESP32_S3_KORVO_2_V3_0_BOARD
    #include "esp32_s3_korvo_2_v3_board.h"
#elif CONFIG_ESP32_S3_EYE_BOARD
    #include "esp32_s3_eye_board.h"
#elif CONFIG_ESP_CUSTOM_BOARD
    #include "esp_custom_board.h"
#elif CONFIG_ESP32_S3_CUSTOM_HW
    #include "esp32_s3_custom_hw.h"
#elif CONFIG_ESP32_S3_CUSTOM_HW_02
    #include "esp32_s3_custom_hw_02.h"
#else 
    #error "Please select type of dev board"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Power module of dev board. This can be expanded in the future.
 * 
 */
typedef enum {
    POWER_MODULE_LCD = 1,       /*!< LCD power control */
    POWER_MODULE_AUDIO,         /*!< Audio PA power control */
    POWER_MODULE_ALL = 0xff,    /*!< All module power control */
} power_module_t;

/**
 * @brief Add device to I2C bus
 * 
 * @param i2c_device_handle Handle of I2C device
 * @param dev_addr 7 bit address of device
 * @return
 *    - ESP_OK Success
 *    - Others: Refer to error code `esp_err.h`.
 */
esp_err_t bsp_i2c_add_device(i2c_bus_device_handle_t *i2c_device_handle, uint8_t dev_addr);

/**
 * @brief Deinit SD card
 * 
 * @param mount_point Path where partition was registered (e.g. "/sdcard")
 * @return 
 *    - ESP_OK: Success
 *    - Others: Fail
 */
esp_err_t bsp_sdcard_deinit(char *mount_point);

/**
 * @brief Init SD crad
 * 
 * @param mount_point Path where partition should be registered (e.g. "/sdcard")
 * @param max_files Maximum number of files which can be open at the same time
 * @return
 *    - ESP_OK                  Success
 *    - ESP_ERR_INVALID_STATE   If esp_vfs_fat_register was already called
 *    - ESP_ERR_NOT_SUPPORTED   If dev board not has SDMMC/SDSPI
 *    - ESP_ERR_NO_MEM          If not enough memory or too many VFSes already registered
 *    - Others                  Fail
 */
esp_err_t bsp_sdcard_init(char *mount_point, size_t max_files);

/**
 * @brief Special config for dev board
 * 
 * @return
 *    - ESP_OK: Success
 *    - Others: Fail
 */
esp_err_t bsp_board_init(audio_hal_iface_samples_t sample_rate, int channel_format, int bits_per_chan);


esp_err_t bsp_audio_play(const int16_t* data, int length, TickType_t ticks_to_wait);

esp_err_t bsp_get_feed_data(int16_t *buffer, int buffer_len);

int bsp_get_feed_channel(void);



#ifdef __cplusplus
}
#endif
