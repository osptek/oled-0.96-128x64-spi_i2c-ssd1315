#pragma once

#include <stdint.h>

#include "esp_err.h"
#include "ssd1315.h"

typedef struct {
    uint32_t frame;
    uint16_t next_blink;
    uint16_t idle_timer;
    int8_t look_x;
    int8_t look_y;
    int8_t target_x;
    int8_t target_y;
    uint8_t blink_phase;
} robot_face_state_t;

void robot_face_state_init(robot_face_state_t *state);
esp_err_t robot_face_update(ssd1315_t *oled, robot_face_state_t *state);
