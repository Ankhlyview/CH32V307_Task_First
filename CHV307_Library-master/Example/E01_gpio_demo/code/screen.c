#include "zf_common_headfile.h"

void screen_init_(void)
{
    spi_init(SPI_1, 0, 1*1000*1000, SPI1_MAP0_SCK_A5, SPI1_MAP0_MOSI_A7, SPI1_MAP0_MISO_A6, A4);

    ips200_init(IPS200_TYPE_SPI);
    ips200_show_string(0, 0, "Hello SPI Screen!");
    ips200_show_int(0, 20, 114514, 6);
}

// 在屏幕上显示就直接用ips的函数就行