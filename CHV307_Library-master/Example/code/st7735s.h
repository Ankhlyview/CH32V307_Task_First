#ifndef __ST7735S_H_
#define __ST7735S_H_

#include "zf_common_typedef.h"
#include "zf_driver_spi.h"
#include "zf_driver_gpio.h"
#include "menu.h"

// ==================== 引脚定义 ====================
// #define ST7735S_SCL_PIN     ST7735S_SCL_PIN
// #define ST7735S_SDA_PIN     ST7735S_SDA_PIN
// #define ST7735S_RES_PIN     ST7735S_RES_PIN
// #define ST7735S_DC_PIN      ST7735S_DC_PIN
// #define ST7735S_CS_PIN      ST7735S_CS_PIN
// #define ST7735S_BL_PIN      ST7735S_BL_PIN

// ==================== 屏幕参数 ====================
#define ST7735S_WIDTH       128
#define ST7735S_HEIGHT      160
#define ST7735S_X_OFFSET    2
#define ST7735S_Y_OFFSET    1

// ==================== 常用颜色 ====================
#define ST7735S_BLACK       0x0000
#define ST7735S_WHITE       0xFFFF
#define ST7735S_RED         0xF800
#define ST7735S_GREEN       0x07E0
#define ST7735S_BLUE        0x001F
#define ST7735S_YELLOW      0xFFE0
#define ST7735S_CYAN        0x07FF
#define ST7735S_MAGENTA     0xF81F
#define ST7735S_GRAY        0x8410
#define ST7735S_ORANGE      0xFD20

#define ST7735S_RGB565(r, g, b)  (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3))

// ==================== 函数声明 ====================
void    st7735s_init(void);
void    st7735s_set_window(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
void    st7735s_draw_point(uint16_t x, uint16_t y, uint16_t color);
void    st7735s_fill(uint16_t color);
void    st7735s_clear(uint16_t color);
void    st7735s_fill_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void    st7735s_draw_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void    st7735s_draw_line(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color);
void    st7735s_draw_hline(uint16_t x, uint16_t y, uint16_t w, uint16_t color);
void    st7735s_draw_vline(uint16_t x, uint16_t y, uint16_t h, uint16_t color);
void    st7735s_show_char(uint16_t x, uint16_t y, char ch, uint16_t color, uint16_t bgcolor);
void    st7735s_show_string(uint16_t x, uint16_t y, const char *str, uint16_t color, uint16_t bgcolor);
void    st7735s_show_int(uint16_t x, uint16_t y, int32_t num, uint8_t len, uint16_t color, uint16_t bgcolor);
void    st7735s_show_uint(uint16_t x, uint16_t y, uint32_t num, uint8_t len, uint16_t color, uint16_t bgcolor);
void    st7735s_show_float(uint16_t x, uint16_t y, float num, uint8_t int_len, uint8_t dec_len, uint16_t color, uint16_t bgcolor);

#endif