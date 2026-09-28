#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "driver/i2c_master.h"
#include "esp_err.h"

#define SSD1315_I2C_SCL_GPIO    9
#define SSD1315_I2C_SDA_GPIO    10
#define SSD1315_I2C_PORT        I2C_NUM_0
#define SSD1315_I2C_FREQ_HZ     400000

#define SSD1315_WIDTH           128
#define SSD1315_HEIGHT          64
#define SSD1315_FRAMEBUFFER_SIZE  (SSD1315_WIDTH * SSD1315_HEIGHT / 8)

/** 7-bit I2C 地址，SA0 接 GND 时为 0x3C，接 VCC 时为 0x3D */
#define SSD1315_I2C_ADDR        0x3C

typedef struct {
    i2c_master_bus_handle_t bus;
    i2c_master_dev_handle_t dev;
} ssd1315_t;

esp_err_t ssd1315_init(ssd1315_t *oled);
esp_err_t ssd1315_deinit(ssd1315_t *oled);

esp_err_t ssd1315_display_on(ssd1315_t *oled, bool on);
esp_err_t ssd1315_clear(ssd1315_t *oled);
esp_err_t ssd1315_fill(ssd1315_t *oled, uint8_t pattern);
esp_err_t ssd1315_flush(ssd1315_t *oled, const uint8_t *framebuffer);

void ssd1315_fb_clear(uint8_t *fb);
void ssd1315_fb_pixel(uint8_t *fb, int x, int y, bool on);
void ssd1315_fb_fill_rect(uint8_t *fb, int x, int y, int w, int h, bool on);
void ssd1315_fb_frame_rect(uint8_t *fb, int x, int y, int w, int h, int t);
void ssd1315_fb_fill_circle(uint8_t *fb, int cx, int cy, int r, bool on);
void ssd1315_fb_line(uint8_t *fb, int x0, int y0, int x1, int y1);
