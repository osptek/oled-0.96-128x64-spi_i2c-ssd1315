/*
 * SPDX-FileCopyrightText: Copyright 2026 OSPTEK
 * SPDX-License-Identifier: CC-BY-4.0
 *
 * https://github.com/osptek
 */

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "robot_face.h"
#include "ssd1315.h"

static const char *TAG = "main";

void app_main(void)
{
    ssd1315_t oled = {0};
    robot_face_state_t face = {0};

    ESP_LOGI(TAG, "electronic eyes start");
    ESP_ERROR_CHECK(ssd1315_init(&oled));
    robot_face_state_init(&face);

    while (true) {
        ESP_ERROR_CHECK(robot_face_update(&oled, &face));
        vTaskDelay(pdMS_TO_TICKS(40));
    }
}
