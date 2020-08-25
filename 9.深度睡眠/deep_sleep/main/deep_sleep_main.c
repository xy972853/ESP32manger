/* Deep sleep wake up example
 分区16M  14M用于存储 2M用于APP和OTA
 SPI-flash分区表如下： 前36K系统使用分区表存放在0x8000处
nvs,      data, nvs,     0x9000,  0x4000,   16K
otadata,  data, ota,     0xd000,  0x2000,   8K
phy_init, data, phy,     0xf000,  0x1000,   4K
ota_0,    0,    ota_0,   0x10000,  1M,      1M  --要保证地址与0x10000对齐多以分配1M
ota_1,    0,    ota_1,   0x110000, 0xF0000   960K
共 2M 其余14M用于存储
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_sleep.h"
#include "esp_log.h"
#include "driver/rtc_io.h"
#include "soc/sens_periph.h"
#include "soc/rtc.h"

void app_main()
{
    //中断唤醒源判断
    switch (esp_sleep_get_wakeup_cause()) {
        //外部外部EXT1
        case ESP_SLEEP_WAKEUP_EXT1: {
            uint64_t wakeup_pin_mask = esp_sleep_get_ext1_wakeup_status();
            if (wakeup_pin_mask != 0) {
                int pin = __builtin_ffsll(wakeup_pin_mask) - 1;
                printf("Wake up from GPIO %d\n", pin);
            } else {
                printf("Wake up from GPIO\n");
            }
            break;
        }
        //定时器
        case ESP_SLEEP_WAKEUP_TIMER: {
            printf("Wake up from timer. Time spent in deep sleep: \n");
            break;
        }
        case ESP_SLEEP_WAKEUP_UNDEFINED:
        default:
            printf("Not a deep sleep reset\n");
        
     }
     vTaskDelay(1000 / portTICK_PERIOD_MS);

    const int wakeup_time_sec = 20;
    printf("Enabling timer wakeup, %ds\n", wakeup_time_sec);
    //设置定时器唤醒时间 单位为us
    esp_sleep_enable_timer_wakeup(wakeup_time_sec * 1000000);
    //
    const int ext_wakeup_pin_1 = 25;
    const uint64_t ext_wakeup_pin_1_mask = 1ULL << ext_wakeup_pin_1;
    const int ext_wakeup_pin_2 = 26;
    const uint64_t ext_wakeup_pin_2_mask = 1ULL << ext_wakeup_pin_2;
    //设置打开外部EXT1的IO25和IO26为唤醒引脚
    //第一个参数：mask位，如果引脚为34 则mask = 1ull<<34
	//第二个参数：是高电平唤醒还是低电平唤醒
    printf("Enabling EXT1 wakeup on pins GPIO%d, GPIO%d\n", ext_wakeup_pin_1, ext_wakeup_pin_2);
    esp_sleep_enable_ext1_wakeup(ext_wakeup_pin_1_mask | ext_wakeup_pin_2_mask, ESP_EXT1_WAKEUP_ANY_HIGH);
    printf("Entering deep sleep\n");
    esp_deep_sleep_start();
}


