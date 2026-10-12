#include "menu.h"
#include "key.h"
#include "st7735s.h"

params_menu_ params;

static uint32 flash_buffer[256];

const uint16 color_list[COLOR_LIST_COUNT] = {
    ST7735S_WHITE,
    ST7735S_RED,
    ST7735S_GREEN,
    ST7735S_BLUE,
    ST7735S_YELLOW,
    ST7735S_CYAN,
    ST7735S_MAGENTA,
};

// ==================== 默认参数 ====================
static void params_set_default(void)
{
    params.magic_          = PARAMS_MAGIC;
    params.led_level_      = 0;
    params.led_period_     = 500;
    params.pit_is_able_    = 0;
    params.pwm_is_able_    = 0;
    params.pwm_freq_       = 1000;
    params.pwm_duty_       = 5000;
    params.screen_color_   = ST7735S_BLACK;
    params.charater_color_ = ST7735S_WHITE;
}

// ==================== Flash 操作 ====================
void params_save(void)
{
    params.magic_ = PARAMS_MAGIC;
    memset(flash_buffer, 0xFF, sizeof(flash_buffer));
    memcpy(flash_buffer, &params, sizeof(params_menu_));
    flash_write_page(FLASH_SECTOR, FLASH_PAGE, flash_buffer, 256);
}

void params_load(void)
{
    flash_read_page(FLASH_SECTOR, FLASH_PAGE, flash_buffer, 256);
    memcpy(&params, flash_buffer, sizeof(params_menu_));
    if (params.magic_ != PARAMS_MAGIC)
    {
        params_set_default();
        params_save();
    }
}

void params_reset(void)
{
    params_set_default();
    params_save();
}






// ==================== 参数应用 ====================
void params_apply_all(void)
{
    gpio_set_level(LED_PIN, params.led_level_ ? 1 : 0);

    if (params.pwm_is_able_)
        pwm_set_freq(PWM_PIN, params.pwm_freq_, params.pwm_duty_);
    else
        pwm_set_duty(PWM_PIN, 0);
}





// ==================== 菜单结构 ====================
typedef enum {
    M_DIR = 0,    // 目录
    M_U8,         // uint8 参数
    M_U32,        // uint32 参数
    M_COLOR,      // 颜色参数
    M_ACTION      // 动作
} menu_type_t;

typedef struct menu_item {
    const char *name;
    menu_type_t type;
    struct menu_item *parent;
    struct menu_item *children[8];
    void *param;
    int32_t min, max, step;
    void (*action)(void);
} menu_item_t;

// ==================== 菜单节点 ====================
static menu_item_t menu_main, menu_led, menu_buzzer, menu_screen, menu_params, menu_about;

static menu_item_t item_led_switch, item_led_blink_en, item_led_period;
static menu_item_t item_buzzer_switch, item_buzzer_freq, item_buzzer_duty;
static menu_item_t item_screen_bg, item_screen_fg;
static menu_item_t item_save, item_load, item_reset;
static menu_item_t item_about;

// ==================== 当前状态 ====================
static menu_item_t *current_menu;
static uint8 current_index;
static uint8 edit_mode;
static menu_item_t *edit_item;

// ==================== 参数读写 ====================
static int32_t menu_get_param(menu_item_t *item)
{
    if (item->type == M_U8)
        return *(uint8 *)item->param;
    else if (item->type == M_U32 || item->type == M_COLOR)
        return *(uint32 *)item->param;
    return 0;
}

static void menu_set_param(menu_item_t *item, int32_t val)
{
    if (item->type == M_U8)
        *(uint8 *)item->param = (uint8)val;
    else if (item->type == M_U32 || item->type == M_COLOR)
        *(uint32 *)item->param = (uint32)val;
}

// ==================== 动作函数 ====================
static void action_save(void)   { params_save(); }
static void action_load(void)   { params_load(); params_apply_all(); }
static void action_reset(void)  { params_reset(); params_apply_all(); }
static void action_led(void)    { gpio_set_level(LED_PIN, params.led_level_ ? 1 : 0); }
static void action_pwm(void)
{
    if (params.pwm_is_able_)
        pwm_set_freq(PWM_PIN, params.pwm_freq_, params.pwm_duty_);
    else
        pwm_set_duty(PWM_PIN, 0);
}
static void action_none(void) {}

static void action_about(void)
{
    st7735s_clear(params.screen_color_);
    st7735s_show_string(0,  0, "CH32V307",       ST7735S_CYAN,  params.screen_color_);
    st7735s_show_string(0, 20, "ST7735S Menu",   ST7735S_WHITE, params.screen_color_);
    st7735s_show_string(0, 40, "Task 3~11",      ST7735S_WHITE, params.screen_color_);
    st7735s_show_string(0, 60, "Multi-Menu Demo",ST7735S_WHITE, params.screen_color_);
    system_delay_ms(2000);
}

// ==================== 菜单初始化 ====================
static void menu_item_set(menu_item_t *item, const char *name, menu_type_t type,
                          menu_item_t *parent, void *param,
                          int32_t min, int32_t max, int32_t step,
                          void (*action)(void))
{
    item->name = name;
    item->type = type;
    item->parent = parent;
    item->param = param;
    item->min = min;
    item->max = max;
    item->step = step;
    item->action = action;
    for (uint8 i = 0; i < 8; i++) item->children[i] = NULL;
}

void menu_init(void)
{
    // ---------- LED 子菜单 ----------
    menu_item_set(&menu_led, "LED", M_DIR, &menu_main, NULL, 0, 0, 0, NULL);
    menu_item_set(&item_led_switch,   "On/Off",  M_U8,  &menu_led, &params.led_level_,    0, 1,    1,   action_led);
    menu_item_set(&item_led_blink_en, "BlinkEn", M_U32, &menu_led, &params.pit_is_able_,  0, 1,    1,   action_none);
    menu_item_set(&item_led_period,   "Period",  M_U32, &menu_led, &params.led_period_, 100, 5000, 100, action_none);
    menu_led.children[0] = &item_led_switch;
    menu_led.children[1] = &item_led_blink_en;
    menu_led.children[2] = &item_led_period;

    // ---------- 蜂鸣器子菜单 ----------
    menu_item_set(&menu_buzzer, "Buzzer", M_DIR, &menu_main, NULL, 0, 0, 0, NULL);
    menu_item_set(&item_buzzer_switch, "On/Off", M_U8,  &menu_buzzer, &params.pwm_is_able_, 0, 1,     1,   action_pwm);
    menu_item_set(&item_buzzer_freq,   "Freq",   M_U32, &menu_buzzer, &params.pwm_freq_,   100, 5000,  100, action_pwm);
    menu_item_set(&item_buzzer_duty,   "Duty",   M_U32, &menu_buzzer, &params.pwm_duty_,   0, 10000, 500, action_pwm);
    menu_buzzer.children[0] = &item_buzzer_switch;
    menu_buzzer.children[1] = &item_buzzer_freq;
    menu_buzzer.children[2] = &item_buzzer_duty;

    // ---------- 屏幕子菜单 ----------
    menu_item_set(&menu_screen, "Screen", M_DIR, &menu_main, NULL, 0, 0, 0, NULL);
    menu_item_set(&item_screen_bg, "BG Color", M_COLOR, &menu_screen, &params.screen_color_,   0, COLOR_LIST_COUNT - 1, 1, action_none);
    menu_item_set(&item_screen_fg, "FG Color", M_COLOR, &menu_screen, &params.charater_color_, 0, COLOR_LIST_COUNT - 1, 1, action_none);
    menu_screen.children[0] = &item_screen_bg;
    menu_screen.children[1] = &item_screen_fg;

    // ---------- 参数子菜单 ----------
    menu_item_set(&menu_params, "Params", M_DIR, &menu_main, NULL, 0, 0, 0, NULL);
    menu_item_set(&item_save,  "Save",  M_ACTION, &menu_params, NULL, 0, 0, 0, action_save);
    menu_item_set(&item_load,  "Load",  M_ACTION, &menu_params, NULL, 0, 0, 0, action_load);
    menu_item_set(&item_reset, "Reset", M_ACTION, &menu_params, NULL, 0, 0, 0, action_reset);
    menu_params.children[0] = &item_save;
    menu_params.children[1] = &item_load;
    menu_params.children[2] = &item_reset;

    // ---------- 关于 ----------
    menu_item_set(&menu_about, "About", M_ACTION, &menu_main, NULL, 0, 0, 0, action_about);
    menu_item_set(&item_about, "About", M_ACTION, NULL, NULL, 0, 0, 0, action_about);

    // ---------- 主菜单 ----------
    menu_item_set(&menu_main, "Main", M_DIR, NULL, NULL, 0, 0, 0, NULL);
    menu_main.children[0] = &menu_led;
    menu_main.children[1] = &menu_buzzer;
    menu_main.children[2] = &menu_screen;
    menu_main.children[3] = &menu_params;
    menu_main.children[4] = &menu_about;

    // ---------- 初始状态 ----------
    current_menu = &menu_main;
    current_index = 0;
    edit_mode = 0;
    edit_item = NULL;
}

// ==================== 绘制菜单 ====================
void menu_draw(void)
{
    st7735s_clear(params.screen_color_);

    // 标题栏
    st7735s_show_string(0, 0, current_menu->name, ST7735S_CYAN, params.screen_color_);
    st7735s_draw_hline(0, 16, 128, ST7735S_GRAY);

    // 菜单项列表（最多 7 项）
    uint8 i = 0;
    while (current_menu->children[i] != NULL && i < 7)
    {
        menu_item_t *item = current_menu->children[i];
        uint16 y = 20 + i * 18;
        uint16 color = (i == current_index) ? ST7735S_YELLOW : params.charater_color_;

        if (i == current_index)
            st7735s_show_string(0, y, ">", ST7735S_YELLOW, params.screen_color_);

        st7735s_show_string(8, y, item->name, color, params.screen_color_);

        if (item->type == M_U8 || item->type == M_U32 || item->type == M_COLOR)
        {
            int32_t val = menu_get_param(item);
            st7735s_show_int(80, y, val, 5, color, params.screen_color_);
        }
        i++;
    }

    // 编辑模式提示
    if (edit_mode)
    {
        st7735s_show_string(0, 145, "EDIT U/D+-  M OK", ST7735S_GREEN, params.screen_color_);
    }
}

// ==================== 按键处理 ====================
void menu_handle_key(uint8 key)
{
    // ---------- 编辑模式 ----------
    if (edit_mode && edit_item != NULL)
    {
        int32_t val = menu_get_param(edit_item);

        if (edit_item->type == M_COLOR)
        {
            uint8 idx = 0;
            for (uint8 i = 0; i < COLOR_LIST_COUNT; i++)
                if (color_list[i] == (uint16)val) { idx = i; break; }

            if (key == KEY_U)
                idx = (idx + 1) % COLOR_LIST_COUNT;
            else if (key == KEY_D)
                idx = (idx + COLOR_LIST_COUNT - 1) % COLOR_LIST_COUNT;
            else if (key == KEY_M || key == KEY_L)
            {
                edit_mode = 0;
                return;
            }
            menu_set_param(edit_item, color_list[idx]);
        }
        else
        {
            if (key == KEY_U)
            {
                val += edit_item->step;
                if (val > edit_item->max) val = edit_item->max;
                menu_set_param(edit_item, val);
            }
            else if (key == KEY_D)
            {
                val -= edit_item->step;
                if (val < edit_item->min) val = edit_item->min;
                menu_set_param(edit_item, val);
            }
            else if (key == KEY_M || key == KEY_L)
            {
                edit_mode = 0;
                return;
            }
        }

        if (edit_item->action) edit_item->action();
        return;
    }

    // ---------- 导航模式 ----------
    switch (key)
    {
        case KEY_U:
            if (current_index > 0) current_index--;
            else {
                uint8 n = 0;
                while (current_menu->children[n] != NULL && n < 7) n++;
                if (n > 0) current_index = n - 1;
            }
            break;

        case KEY_D:
            if (current_menu->children[current_index + 1] != NULL) current_index++;
            else current_index = 0;
            break;

        case KEY_M:
        {
            menu_item_t *item = current_menu->children[current_index];
            if (item->type == M_DIR)
            {
                if (item->children[0] != NULL)
                {
                    current_menu = item;
                    current_index = 0;
                }
            }
            else if (item->type == M_U8 || item->type == M_U32 || item->type == M_COLOR)
            {
                edit_mode = 1;
                edit_item = item;
            }
            else if (item->type == M_ACTION)
            {
                if (item->action) item->action();
            }
        } break;

        case KEY_L:
            if (current_menu->parent != NULL)
            {
                current_menu = current_menu->parent;
                current_index = 0;
            }
            break;

        case KEY_KEY1:   // 快捷保存
            params_save();
            break;

        case KEY_KEY2:   // 快捷复位
            params_reset();
            params_apply_all();
            break;
    }
}