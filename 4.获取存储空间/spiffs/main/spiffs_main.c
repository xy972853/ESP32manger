/* 
功能：获取总存储空间和当前剩余空间大小
加入SPIFFS文件系统来进行文件的管理  前2M用来下载程序和OTA升级 后14M用来存储文件 文件
系统管理的是14M存储空间，烧录spiffs镜像 ，文件为spiffs.bin
镜像制作：
spiffsgen.py 0xE00000 spiffs_image spiffs.bin
烧录镜像命令
esptool.py --chip esp32 --port COM5 write_flash -z 0x200000 spiffs.bin

镜像制作方法参考网址：
 https://blog.csdn.net/rbin_yao/article/details/105225145
 https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-reference/storage/spiffs.html

*/

#include <stdio.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_spiffs.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "example";
//读取镜像hello.txt 文件内容为 hello world
static void read_hello_txt()
{
    ESP_LOGI(TAG, "Reading hello.txt");

    // Open for reading hello.txt
    FILE* f = fopen("/spiffs/hello.txt", "r");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open hello.txt");
        return;
    }

    char buf[64];
    memset(buf, 0, sizeof(buf));
    fread(buf, 1, sizeof(buf), f);
    fclose(f);

    // Display the read contents from the file
    ESP_LOGI(TAG, "Read from hello.txt: %s", buf);
}
void ReadCount_task(void * parameter)
{   
    
    while(1)
    {
        printf("Hello world!\n");
        //初始化spiffs文件系统
        ESP_LOGI(TAG, "Initializing SPIFFS");

        esp_vfs_spiffs_conf_t conf = {
        .base_path = "/spiffs",
        .partition_label = NULL,
        .max_files = 5,
        .format_if_mount_failed = false
        };
        esp_err_t ret = esp_vfs_spiffs_register(&conf);
        //判断文件系统是否挂载成功和出错
        if (ret != ESP_OK) {
            if (ret == ESP_FAIL) {
                ESP_LOGE(TAG, "Failed to mount or format filesystem");
            } else if (ret == ESP_ERR_NOT_FOUND) {
                ESP_LOGE(TAG, "Failed to find SPIFFS partition");
            } else {
                ESP_LOGE(TAG, "Failed to initialize SPIFFS (%s)", esp_err_to_name(ret));
            }
            return;
        }
        size_t total = 0, used = 0;
        //读取内存使用情况，总容量和剩余容量并打印输出
        ret = esp_spiffs_info(NULL, &total, &used);
        if (ret != ESP_OK) {
            ESP_LOGE(TAG, "Failed to get SPIFFS partition information (%s)", esp_err_to_name(ret));
        } else {
            ESP_LOGI(TAG, "Partition size: total: %dMB, used: %d bits", total/1000/1000, used);
        }
        //读取hello.txt文件内容并打印输出  
        read_hello_txt();
        esp_vfs_spiffs_unregister(NULL);
        //读取完成卸载文件系统
        ESP_LOGI(TAG, "SPIFFS unmounted");
        vTaskDelay(20000 / portTICK_PERIOD_MS);
   }
}
void app_main()
{
    //创建任务每20S进行一次数据读取
    xTaskCreate(
                    ReadCount_task,          /* Task function. */
                    "ReadCount_task",        /* String with name of task. */
                    10000,            /* Stack size in bytes. */
                    NULL,             /* Parameter passed as input of the task */
                    1,                /* Priority of the task. */
                    NULL);            /* Task handle. */
    
}
