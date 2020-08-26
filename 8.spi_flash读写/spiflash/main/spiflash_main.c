/* SPIFFS filesystem example.
   写数据的时间很短，擦除的时间很长，但是写数据之前都要擦除，这个没办法，
   这个spi flash主要还是作为大量的数据保存，
   例如字库或者图片，但是不适合高速的数据存取。
  经过测试写入1M的数据时时间会特别久
  写入30K数据时大约要5S左右。
  1M数据用37S
  数据越大，删除的时间就越长。
  文件系统比SPI_flash 要慢
    建议：在使用时应该提前创建好文件再进行读写操作，不要每次都创建新的文件进行读写。
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
char buffer[1024*4];//创建4KB文件
void app_main(void)
{
    ESP_LOGI(TAG, "Initializing SPIFFS");
    
    esp_vfs_spiffs_conf_t conf = {
      .base_path = "/spiffs",
      .partition_label = NULL,
      .max_files = 5,
      .format_if_mount_failed = true
    };
    
    //挂载文件系统
    esp_err_t ret = esp_vfs_spiffs_register(&conf);

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
    ret = esp_spiffs_info(NULL, &total, &used);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to get SPIFFS partition information (%s)", esp_err_to_name(ret));
    } else {
        ESP_LOGI(TAG, "Partition size: total: %d, used: %d", total, used);
    }
    //进行数据copy 4KB数据
     unsigned short len=0,j;
     for(j=0;j<4;j++)
     {
      for(len=0;len<1024;len++)
        {
            buffer[len+1024*j]=j+0x30;
        }
     }
     //打印信息用于计算创建时间  
    printf("creat start time\r\n");
     //创建文件 test.txt
      FILE* f = fopen("/spiffs/test1.txt", "w");
      if (f == NULL) {
        //ESP_LOGE(TAG, "Failed to open file for writing");
        return;
     }
     else 
     {
       //ESP_LOGE(TAG, "creat file success ,ready to write");
     }
     printf("create end time\r\n");
     //打印开始写数据，开始计时
     //  printf("File written start\r\n");
     for(j=0;j<256;j++)
     {
       fprintf(f, "%s",buffer);
     }
      
     //打印写数据结束，结束计时
      printf("File written end\r\n");
     fclose(f);
     // vTaskDelay(1000/portTICK_RATE_MS );
     //文件读取
     //printf("start time\r\n");
     f = fopen("/spiffs/test1.txt", "r");
       fgets(buffer, sizeof(buffer), f);
       fclose(f);
    
    printf("end time\r\n");
    //在数组结尾加\0;
    //char* pos = strchr(buffer, '\n');
    //if (pos) 
    //{
       // *pos = '\0';
    // }
      printf("delete start time\r\n");
    //文件删除
    struct stat st;
    if (stat("/spiffs/test.txt1", &st) == 0) {
        // Delete it if it exists
       
        unlink("/spiffs/test1.txt");
    }
    //打印信息用于测试
     printf("delete test1.txt end\r\n");
   // ESP_LOGI(TAG, "Read from file: '%s'", buffer);
    // All done, unmount partition and disable SPIFFS
    esp_vfs_spiffs_unregister(NULL);
    ESP_LOGI(TAG, "SPIFFS unmounted");
}
