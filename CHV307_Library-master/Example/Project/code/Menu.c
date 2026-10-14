#include "Menu.h"
#include "Key.h"
#include "St7735s.h"

// 这个是一个全局变量，这个的作用就是用来接受从flash中读出的值，然后用来给一些外设进行设置
params_menu params;

// Flash 这就是一个缓冲的位置
static uint32 flash_buffer[256];

// 常用的颜色
const uint16 color_list[COLOR_LIST_COUNT] = {
    ST7735S_WHITE,
    ST7735S_RED,
    ST7735S_GREEN,
    ST7735S_BLUE,
    ST7735S_YELLOW,
    ST7735S_CYAN,
    ST7735S_MAGENTA,
    ST7735S_PINK,
};

//给params这个结构一个初始值
static void params_init(void)
{
    params.magic = PARAMS_MAGIC;
    params.led_level = 0;
    params.pit_is_able = 0;
    params.led_period = 500;
    params.pwm_is_able = 0;
    params.pwm_duty = 5000;
    params.pwm_freq = 1000;
    params.screen_color = ST7735S_BLACK;
    params.charater_color = ST7735S_WHITE;
}
// 问ai来着这个写入操作时以uint32对齐的，所以说在uint8的可以不用填补

// 将params的数据写进Flash
void params_save(void)
{
    params.magic = PARAMS_MAGIC;
    memset(flash_buffer,0xFF,sizeof(flash_buffer));
    memcpy(flash_buffer,&params,sizeof(params_menu));
    flash_write_page(FLASH_SECTOR,FLASH_PAGE,flash_buffer,256);
}

// 将Flash中的数据写进params
void params_load(void)
{
    flash_read_page(FLASH_SECTOR,FLASH_PAGE,flash_buffer,256);
    memcpy(&params,flash_buffer,sizeof(params_menu));
    // 防止出现差错
    if(params.magic != PARAMS_MAGIC)
    {
        params_init();
        params_save();
    }
}

// 重启了
void params_reset(void)
{
    params_init();
    params_save();
}

// 将params应用给所有可以设置的外设，其实这里还少一个颜色的应用:(但是我不想写了
void params_apply(void)
{
    gpio_set_level(LED_PIN,params.led_level);

    if(params.pwm_is_able)
        pwm_set_freq(PWM_PIN,params.pwm_freq,params.pwm_duty);
    else 
        pwm_set_duty(PWM_PIN,0);
}

// 节点的属性,就是指定这个节点具体作用是什么
typedef enum{
    type_dir = 0,
    type_u8,
    type_u32,
    type_color,
    type_action
} node_type;

typedef struct node{
    const char*name;
    node_type type;
    struct node *parent;
    struct node *children[5];
    void *param;  //用void*来管理不同类型的参数
    int32 min,max,step;//这个是这个节点如果有参数调节的化，这个参数的上线下线，还有调整的步长
    void (*action)(void); //C的引用函数指针
}node;

// 声明节点
static node node_main,node_led,node_buzzer,node_screen,node_flash,node_other;
static node led_gpio_on,led_pit_on,led_pit_preiod;
static node buzzer_on,buzzer_freq,buzzer_duty;
static node screen_sc,screen_cc;
static node flash_save,flash_load,flash_reset;
// static node other;


static node *cur_node;// 目前节点
static uint8 cur_index;// 目前节点的子节点的index
static node *post_node;// 编辑的节点
static uint8 edit_mode;// 是否处于编辑模式

// 从一个节点读取参数
static int32 get_param(node *item)
{
    if(item->type == type_u8)
        return *(uint8 *)item->param;
    else if(item->type == type_u32|| item->type == type_color)
        return *(uint32 *)item->param;
    return 0;
}

// 给一个节点写入参数
static void set_param(node *item,int32 val)
{
    if(item->type == type_u8)
        *(uint8 *)item->param = (uint8)val;
    else if(item->type == type_u32 || item->type == type_color)
        *(uint32 *)item->param = val;
}

// 这个就是一些行动
static void action_save(void)   { params_save(); }
static void action_load(void)   { params_load(); params_apply(); }
static void action_reset(void)  { params_reset(); params_apply(); }
static void action_led(void)    { gpio_set_level(LED_PIN, params.led_level); }
static void action_pwm(void)
{
    if (params.pwm_is_able)
        pwm_set_freq(PWM_PIN, params.pwm_freq, params.pwm_duty);
    else
        pwm_set_duty(PWM_PIN, 0);
}

static void action_about(void)
{
    st7735s_clear(params.screen_color);
    st7735s_show_string(0,  0, "Terraria:)",        ST7735S_PINK,  params.screen_color);
    st7735s_show_string(0, 20, "Minecraft:)",    ST7735S_PINK, params.screen_color);
    st7735s_show_string(0, 40, "StreetFighter6:)",       ST7735S_PINK, params.screen_color);
    st7735s_show_string(0, 60, "SlaytheSpire:)", ST7735S_PINK, params.screen_color);
    system_delay_ms(2000);
}

// 初始化一个节点
static void node_init(node*item,const char*name,node_type type,node *parent,void *param,uint32 min,uint32 max,uint32 step,void (*action)(void))
{
    item->name = name;
    item->type = type;
    item->parent = parent;
    item->param = param;
    item->min = min;
    item->max = max;
    item->step = step;
    item->action = action;
    for(uint8 i = 0;i<5;i++)
        item->children[i] = NULL;
}

//菜单所有节点初始化
void menu_init(void)
{
    // LED 子菜单
    node_init(&node_led, "LED", type_dir, &node_main, NULL, 0, 0, 0, NULL);
    node_init(&led_gpio_on,   "On/Off",  type_u8,  &node_led, &params.led_level,   0, 1,    1,   action_led);
    node_init(&led_pit_on, "BlinkEn", type_u32, &node_led, &params.pit_is_able, 0, 1,    1,   NULL);
    node_init(&led_pit_preiod,   "Period",  type_u32, &node_led, &params.led_period,  100, 5000, 100, NULL);
    node_led.children[0] = &led_gpio_on;
    node_led.children[1] = &led_pit_on;
    node_led.children[2] = &led_pit_preiod;

    // 蜂鸣器子菜单
    node_init(&node_buzzer, "Buzzer", type_dir, &node_main, NULL, 0, 0, 0, NULL);
    node_init(&buzzer_on, "On/Off", type_u8,  &node_buzzer, &params.pwm_is_able, 0, 1,     1,   action_pwm);
    node_init(&buzzer_freq,   "Freq",   type_u32, &node_buzzer, &params.pwm_freq,   100, 5000,  100, action_pwm);
    node_init(&buzzer_duty,   "Duty",   type_u32, &node_buzzer, &params.pwm_duty,   0, 10000, 500, action_pwm);
    node_buzzer.children[0] = &buzzer_on;
    node_buzzer.children[1] = &buzzer_freq;
    node_buzzer.children[2] = &buzzer_duty;

    // 屏幕子菜单
    node_init(&node_screen, "Screen", type_dir, &node_main, NULL, 0, 0, 0, NULL);
    node_init(&screen_sc, "BG Color", type_color, &node_screen, &params.screen_color,   0, COLOR_LIST_COUNT - 1, 1, NULL);
    node_init(&screen_cc, "FG Color", type_color, &node_screen, &params.charater_color, 0, COLOR_LIST_COUNT - 1, 1, NULL);
    node_screen.children[0] = &screen_sc;
    node_screen.children[1] = &screen_cc;

    // 参数子菜单
    node_init(&node_flash, "Params", type_dir, &node_main, NULL, 0, 0, 0, NULL);
    node_init(&flash_save,  "Save",  type_action, &node_flash, NULL, 0, 0, 0, action_save);
    node_init(&flash_load,  "Load",  type_action, &node_flash, NULL, 0, 0, 0, action_load);
    node_init(&flash_reset, "Reset", type_action, &node_flash, NULL, 0, 0, 0, action_reset);
    node_flash.children[0] = &flash_save;
    node_flash.children[1] = &flash_load;
    node_flash.children[2] = &flash_reset;

    // 夹带私货了
    node_init(&node_other, "About", type_action, &node_main, NULL, 0, 0, 0, action_about);

    // 主菜单
    node_init(&node_main, "Main", type_dir, NULL, NULL, 0, 0, 0, NULL);
    node_main.children[0] = &node_led;
    node_main.children[1] = &node_buzzer;
    node_main.children[2] = &node_screen;
    node_main.children[3] = &node_flash;
    node_main.children[4] = &node_other;

    // 初始状态
    cur_node = &node_main;
    cur_index = 0;
    edit_mode = 0;
    post_node = NULL;
}

// 这个就是屏幕上显示的东西，在每一个while中都要进行一次
void menu_draw(void)
{
    st7735s_clear(params.screen_color);
    st7735s_show_string(0, 0, cur_node->name, ST7735S_CYAN, params.screen_color);
    st7735s_draw_hline(0, 16, 128, ST7735S_PINK);

    uint8 index = 0;
    while(cur_node->children[index]!=NULL&&index<5)
    {
        node *item = cur_node->children[index];
        uint16 y = 20 + index * 18;
        uint16 color = (index == cur_index) ? ST7735S_YELLOW : params.charater_color;

        if (index == cur_index)
            st7735s_show_string(0, y, ">", ST7735S_YELLOW, params.screen_color);

        st7735s_show_string(8, y, item->name, color, params.screen_color);

        if (item->type == type_u8 || item->type == type_u32 || item->type == type_color)
        {
            int32_t val = get_param(item);
            st7735s_show_int(80, y, val, 5, color, params.screen_color);
        }
        index++;
    }
    if(edit_mode)
        st7735s_show_string(64,0,"EDIT",ST7735S_GREEN, params.screen_color);
}

// 按键以及对应的行为，这个有一个按键没有用：）
void menu_handle_key(uint8 key)
{
    // 这个是在编辑模式下的情况
    if (edit_mode && post_node != NULL)
    {
        int32_t val = get_param(post_node);

        if (post_node->type == type_color)
        {
            uint8 idx = 0;
            for (uint8 i = 0; i < COLOR_LIST_COUNT; i++)
                if (color_list[i] == (uint16)val) { idx = i; break; }

            if (key == KEY_D)
                idx = (idx + 1) % COLOR_LIST_COUNT;
            else if (key == KEY_U)
                idx = (idx + COLOR_LIST_COUNT - 1) % COLOR_LIST_COUNT;
            else if (key == KEY_M || key == KEY_L)
            {
                edit_mode = 0;
                return;
            }
            set_param(post_node, color_list[idx]);
        }
        else
        {
            if (key == KEY_D)
            {
                val += post_node->step;
                if (val > post_node->max) val = post_node->max;
                set_param(post_node, val);
            }
            else if (key == KEY_U)
            {
                val -= post_node->step;
                if (val < post_node->min) val = post_node->min;
                set_param(post_node, val);
            }
            else if (key == KEY_M || key == KEY_L)
            {
                edit_mode = 0;
                return;
            }
        }

        if (post_node->action) post_node->action();
        return;
    }
    // 这个就是正常的页面转化了
    switch (key)
    {
        case KEY_D:
            if (cur_index > 0) cur_index--;
            else {
                uint8 n = 0;
                while (cur_node->children[n] != NULL && n < 5) n++;
                if (n > 0) cur_index = n - 1;
            }
            break;

        case KEY_U:
            if (cur_node->children[cur_index + 1] != NULL) cur_index++;
            else cur_index = 0;
            break;

        case KEY_M:
        {
            node *item = cur_node->children[cur_index];
            if (item->type == type_dir)
            {
                if (item->children[0] != NULL)
                {
                    cur_node = item;
                    cur_index = 0;
                }
            }
            else if (item->type == type_u8 || item->type == type_u32 || item->type == type_color)
            {
                edit_mode = 1;
                post_node = item;
            }
            else if (item->type == type_action)
            {
                if (item->action) item->action();
            }
        } break;

        case KEY_L:
            if (cur_node->parent != NULL)
            {
                cur_node = cur_node->parent;
                cur_index = 0;
            }
            break;

        case KEY_KEY1:
            params_save();
            break;

        case KEY_KEY2:
            params_reset();
            params_apply();
            break;
    }
}