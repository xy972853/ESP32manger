/* /* Deep sleep wake up example
 分区16M  14M用于存储 2M用于APP和OTA
 SPI-flash分区表如下： 前36K系统使用分区表存放在0x8000处
nvs,      data, nvs,     0x9000,  0x4000,   16K
otadata,  data, ota,     0xd000,  0x2000,   8K
phy_init, data, phy,     0xf000,  0x1000,   4K
ota_0,    0,    ota_0,   0x10000,  1M,      1M  --要保证地址与0x10000对齐所以分配1M
ota_1,    0,    ota_1,   0x110000, 0xF0000   960K
共 2M 其余14M用于存储
*/
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"


void app_main()
{
    printf("Hello world!\n");
   
    /* 打印芯片相关信息启动时可以查看分区信息 每10S重新启动芯片循环打印*/
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is ESP32 chip with %d CPU cores, WiFi%s%s, ",
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    for (int i = 10; i >= 0; i--) {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}
