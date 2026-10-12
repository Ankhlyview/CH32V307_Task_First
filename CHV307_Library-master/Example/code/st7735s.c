#include "st7735s.h"
#include "zf_common_headfile.h"
#include "zf_common_font.h"     

// ==================== 内部写命令/数据 ====================
static void st7735s_write_cmd(uint8_t cmd)
{
    gpio_low(ST7735S_DC_PIN);
    gpio_low(ST7735S_CS_PIN);
    spi_write_8bit(SPI_2, cmd);
    gpio_high(ST7735S_CS_PIN);
}

static void st7735s_write_data(uint8_t data)
{
    gpio_high(ST7735S_DC_PIN);
    gpio_low(ST7735S_CS_PIN);
    spi_write_8bit(SPI_2, data);
    gpio_high(ST7735S_CS_PIN);
}

static void st7735s_write_data16(uint16_t data)
{
    gpio_high(ST7735S_DC_PIN);
    gpio_low(ST7735S_CS_PIN);
    spi_write_8bit(SPI_2, data >> 8);
    spi_write_8bit(SPI_2, data & 0xFF);
    gpio_high(ST7735S_CS_PIN);
}

// ==================== 初始化 ====================
void st7735s_init(void)
{
    gpio_init(ST7735S_RES_PIN, GPO, 1, GPO_PUSH_PULL);
    gpio_init(ST7735S_DC_PIN,  GPO, 0, GPO_PUSH_PULL);
    gpio_init(ST7735S_CS_PIN,  GPO, 1, GPO_PUSH_PULL);
    gpio_init(ST7735S_BL_PIN,  GPO, 0, GPO_PUSH_PULL);

    spi_init(SPI_2, SPI_MODE0, 30 * 1000 * 1000,
             SPI2_MAP0_SCK_B13, SPI2_MAP0_MOSI_B15, SPI_MISO_NULL, PIN_NULL);

    // 硬件复位
    gpio_low(ST7735S_RES_PIN);
    system_delay_ms(20);
    gpio_high(ST7735S_RES_PIN);
    system_delay_ms(120);

    // 软件复位
    st7735s_write_cmd(0x01);
    system_delay_ms(120);

    // 退出睡眠
    st7735s_write_cmd(0x11);
    system_delay_ms(120);

    // 帧率
    st7735s_write_cmd(0xB1); st7735s_write_data(0x01); st7735s_write_data(0x2C); st7735s_write_data(0x2D);
    st7735s_write_cmd(0xB2); st7735s_write_data(0x01); st7735s_write_data(0x2C); st7735s_write_data(0x2D);
    st7735s_write_cmd(0xB3); st7735s_write_data(0x01); st7735s_write_data(0x2C); st7735s_write_data(0x2D);
    st7735s_write_data(0x01); st7735s_write_data(0x2C); st7735s_write_data(0x2D);

    // 显示反转关
    st7735s_write_cmd(0x20);

    // 电源
    st7735s_write_cmd(0xC0); st7735s_write_data(0xA2); st7735s_write_data(0x02); st7735s_write_data(0x84);
    st7735s_write_cmd(0xC1); st7735s_write_data(0xC5);
    st7735s_write_cmd(0xC2); st7735s_write_data(0x0A); st7735s_write_data(0x00);
    st7735s_write_cmd(0xC3); st7735s_write_data(0x8A); st7735s_write_data(0x2A);
    st7735s_write_cmd(0xC4); st7735s_write_data(0x8A); st7735s_write_data(0xEE);

    // VCOM
    st7735s_write_cmd(0xC5); st7735s_write_data(0x0E);

    // 内存访问方向
    st7735s_write_cmd(0xA8); st7735s_write_data(0x68);

    // 16位 RGB565
    st7735s_write_cmd(0x3A); st7735s_write_data(0x05);

    // Gamma
    st7735s_write_cmd(0xE0);
    st7735s_write_data(0x02); st7735s_write_data(0x1C); st7735s_write_data(0x07); st7735s_write_data(0x12);
    st7735s_write_data(0x37); st7735s_write_data(0x32); st7735s_write_data(0x29); st7735s_write_data(0x2D);
    st7735s_write_data(0x29); st7735s_write_data(0x25); st7735s_write_data(0x2B); st7735s_write_data(0x39);
    st7735s_write_data(0x00); st7735s_write_data(0x01); st7735s_write_data(0x03); st7735s_write_data(0x10);

    st7735s_write_cmd(0xE1);
    st7735s_write_data(0x03); st7735s_write_data(0x1D); st7735s_write_data(0x07); st7735s_write_data(0x06);
    st7735s_write_data(0x2E); st7735s_write_data(0x2C); st7735s_write_data(0x29); st7735s_write_data(0x2D);
    st7735s_write_data(0x2E); st7735s_write_data(0x2E); st7735s_write_data(0x37); st7735s_write_data(0x3F);
    st7735s_write_data(0x00); st7735s_write_data(0x00); st7735s_write_data(0x02); st7735s_write_data(0x10);

    // 开显示
    st7735s_write_cmd(0x29);
    system_delay_ms(50);

    // 背光
    gpio_high(ST7735S_BL_PIN);

    st7735s_clear(ST7735S_BLACK);
}

// ==================== 设置窗口 ====================
void st7735s_set_window(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
    st7735s_write_cmd(0x2A);
    st7735s_write_data16(x0 + ST7735S_X_OFFSET);
    st7735s_write_data16(x1 + ST7735S_X_OFFSET);

    st7735s_write_cmd(0x2B);
    st7735s_write_data16(y0 + ST7735S_Y_OFFSET);
    st7735s_write_data16(y1 + ST7735S_Y_OFFSET);

    st7735s_write_cmd(0x2C);
}

// ==================== 画点 ====================
void st7735s_draw_point(uint16_t x, uint16_t y, uint16_t color)
{
    if (x >= ST7735S_WIDTH || y >= ST7735S_HEIGHT) return;
    st7735s_set_window(x, y, x, y);
    st7735s_write_data16(color);
}

// ==================== 全屏填充 ====================
void st7735s_fill(uint16_t color)
{
    st7735s_set_window(0, 0, ST7735S_WIDTH - 1, ST7735S_HEIGHT - 1);
    gpio_high(ST7735S_DC_PIN);
    gpio_low(ST7735S_CS_PIN);
    uint32_t total = ST7735S_WIDTH * ST7735S_HEIGHT;
    while (total--) {
        spi_write_8bit(SPI_2, color >> 8);
        spi_write_8bit(SPI_2, color & 0xFF);
    }
    gpio_high(ST7735S_CS_PIN);
}

void st7735s_clear(uint16_t color)
{
    st7735s_fill(color);
}

// ==================== 填充矩形 ====================
void st7735s_fill_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
    if (x + w > ST7735S_WIDTH)  w = ST7735S_WIDTH  - x;
    if (y + h > ST7735S_HEIGHT) h = ST7735S_HEIGHT - y;

    st7735s_set_window(x, y, x + w - 1, y + h - 1);
    gpio_high(ST7735S_DC_PIN);
    gpio_low(ST7735S_CS_PIN);
    uint32_t total = (uint32_t)w * h;
    while (total--) {
        spi_write_8bit(SPI_2, color >> 8);
        spi_write_8bit(SPI_2, color & 0xFF);
    }
    gpio_high(ST7735S_CS_PIN);
}

// ==================== 画水平线 ====================
void st7735s_draw_hline(uint16_t x, uint16_t y, uint16_t w, uint16_t color)
{
    st7735s_fill_rect(x, y, w, 1, color);
}

// ==================== 画垂直线 ====================
void st7735s_draw_vline(uint16_t x, uint16_t y, uint16_t h, uint16_t color)
{
    st7735s_fill_rect(x, y, 1, h, color);
}

// ==================== 画矩形边框 ====================
void st7735s_draw_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
    st7735s_draw_hline(x, y, w, color);
    st7735s_draw_hline(x, y + h - 1, w, color);
    st7735s_draw_vline(x, y, h, color);
    st7735s_draw_vline(x + w - 1, y, h, color);
}

// ==================== 画线（Bresenham） ====================
void st7735s_draw_line(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color)
{
    int16_t dx = (x1 > x0) ? (x1 - x0) : (x0 - x1);
    int16_t dy = (y1 > y0) ? (y1 - y0) : (y0 - y1);
    int16_t sx = (x0 < x1) ? 1 : -1;
    int16_t sy = (y0 < y1) ? 1 : -1;
    int16_t err = dx - dy;

    while (1) {
        st7735s_draw_point(x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int16_t e2 = err * 2;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 <  dx) { err += dx; y0 += sy; }
    }
}

// ==================== 显示字符（使用逐飞库 ascii_8x16） ====================
void st7735s_show_char(uint16_t x, uint16_t y, char ch, uint16_t color, uint16_t bgcolor)
{
    if (ch < ' ' || ch > '~') return;
    if (x + 8 > ST7735S_WIDTH || y + 16 > ST7735S_HEIGHT) return;

    uint8_t idx = ch - ' ';
    const uint8_t *p = ascii_font_8x16[idx];

    st7735s_set_window(x, y, x + 7, y + 15);
    gpio_high(ST7735S_DC_PIN);
    gpio_low(ST7735S_CS_PIN);

    // 逐行扫描：共 16 行，每行 8 个像素
    for (uint8_t row = 0; row < 16; row++) {
        for (uint8_t col = 0; col < 8; col++) {
            uint8_t data;
            uint8_t bit_mask;

            if (row < 8) {
                // 上半部分：字节 p[0] ~ p[7]
                data = p[col];
                bit_mask = (0x01 << row);       // 逆向：bit0 在最上行
            } else {
                // 下半部分：字节 p[8] ~ p[15]
                data = p[col + 8];
                bit_mask = (0x01 << (row - 8));
            }

            uint16_t c = (data & bit_mask) ? color : bgcolor;
            spi_write_8bit(SPI_2, c >> 8);
            spi_write_8bit(SPI_2, c & 0xFF);
        }
    }

    gpio_high(ST7735S_CS_PIN);
}

// ==================== 显示字符串 ====================
void st7735s_show_string(uint16_t x, uint16_t y, const char *str, uint16_t color, uint16_t bgcolor)
{
    while (*str) {
        if (x + 8 > ST7735S_WIDTH) {
            x = 0;
            y += 16;
        }
        if (y + 16 > ST7735S_HEIGHT) break;
        st7735s_show_char(x, y, *str, color, bgcolor);
        x += 8;
        str++;
    }
}

// ==================== 显示整数 ====================
void st7735s_show_int(uint16_t x, uint16_t y, int32_t num, uint8_t len, uint16_t color, uint16_t bgcolor)
{
    char buf[16];
    uint8_t i = 0;
    uint8_t is_neg = 0;

    if (num < 0) { is_neg = 1; num = -num; }
    if (num == 0) { buf[i++] = '0'; }
    while (num > 0) { buf[i++] = '0' + num % 10; num /= 10; }
    if (is_neg) buf[i++] = '-';
    while (i < len) buf[i++] = ' ';

    // 倒序输出
    for (uint8_t k = 0; k < len; k++) {
        st7735s_show_char(x + k * 8, y, buf[i - 1 - k], color, bgcolor);
    }
}

// ==================== 显示无符号整数 ====================
void st7735s_show_uint(uint16_t x, uint16_t y, uint32_t num, uint8_t len, uint16_t color, uint16_t bgcolor)
{
    char buf[16];
    uint8_t i = 0;

    if (num == 0) { buf[i++] = '0'; }
    while (num > 0) { buf[i++] = '0' + num % 10; num /= 10; }
    while (i < len) buf[i++] = ' ';

    for (uint8_t k = 0; k < len; k++) {
        st7735s_show_char(x + k * 8, y, buf[i - 1 - k], color, bgcolor);
    }
}

// ==================== 显示浮点数 ====================
void st7735s_show_float(uint16_t x, uint16_t y, float num, uint8_t int_len, uint8_t dec_len, uint16_t color, uint16_t bgcolor)
{
    char buf[20];
    uint8_t is_neg = 0;
    if (num < 0) { is_neg = 1; num = -num; }

    int32_t int_part = (int32_t)num;
    float   dec_part = num - int_part;
    for (uint8_t i = 0; i < dec_len; i++) dec_part *= 10;
    int32_t dec_int = (int32_t)(dec_part + 0.5f);

    int len = 0;
    if (is_neg) buf[len++] = '-';

    // 整数部分
    char tmp[12]; uint8_t ti = 0;
    if (int_part == 0) tmp[ti++] = '0';
    while (int_part > 0) { tmp[ti++] = '0' + int_part % 10; int_part /= 10; }
    while (ti < int_len) tmp[ti++] = ' ';
    while (ti > 0) buf[len++] = tmp[--ti];

    // 小数点
    buf[len++] = '.';

    // 小数部分（补零）
    char tmp2[12]; uint8_t ti2 = 0;
    while (dec_int > 0) { tmp2[ti2++] = '0' + dec_int % 10; dec_int /= 10; }
    while (ti2 < dec_len) tmp2[ti2++] = '0';
    while (ti2 > 0) buf[len++] = tmp2[--ti2];

    // 输出
    for (int i = 0; i < len; i++) {
        st7735s_show_char(x + i * 8, y, buf[i], color, bgcolor);
    }
}