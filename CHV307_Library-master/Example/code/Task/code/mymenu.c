#include "mymenu.h"
#include "key.h"
#include "st7735s.h"

params_mymenu flash_params;
static uint32 flash_buffer[256];

const uint16 color_list[COLOR_LIST_Count] = {
    ST7735S_WHITE,
    ST7735S_RED,
    ST7735S_GREEN,
    ST7735S_BLUE,
    ST7735S_YELLOW,
    ST7735S_CYAN,
    ST7735S_MAGENTA,
};

static void params_init(void)
{
    flash_params
}