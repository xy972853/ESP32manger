#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_wifi.h"
#include "driver/gpio.h"
#include "nvs_flash.h"



/* 宏定义WiFi名称和密码 */
#define WIFI_SSID    "TPGuest_5D36"
#define WIFI_PASSWD  "qwertyuiop"


static void wifi_init_sta(void);

void app_main(void)
{
    /* 打印Hello world! */
    printf("Hello world!\n");

    /* 初始化非易失性存储库 (NVS)，存储WIFI相关信息 */
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    printf("ESP_WIFI_MODE_STA \n");
    wifi_init_sta();//初始化WIFI STA 模式          
}

/* 系统事件循环处理函数 */
static void event_handler(void* arg, esp_event_base_t event_base,int32_t event_id, void* event_data)
{
    static int retry_num = 0;           /* 记录wifi重连次数 */
       
    /* 系统事件为WiFi事件 */
    if (event_base == WIFI_EVENT) 
    {
        if(event_id == WIFI_EVENT_STA_START)    /* 事件id为STA开始 */
            esp_wifi_connect();
        else if (event_id == WIFI_EVENT_STA_DISCONNECTED) /* 事件id为失去STA连接 */ 
        {
            esp_wifi_connect();
            retry_num++;
            printf("retry to connect to the AP %d times. \n",retry_num);
            if (retry_num > 10)  /* WiFi重连次数大于10 超时*/
            {
                retry_num=0;
                printf("WIFI CONNECTED FAIL ....RECONNCET.....\n");
                
               
            }
            
           
        }
    } 
    /* 系统事件为ip地址事件，且事件id为成功获取ip地址 */
    else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) 
    {
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data; /* 获取IP地址信息*/
        printf("WIFI CONNECTED SUCCESS.....\n");
        printf("got ip:%d.%d.%d.%d \n" , IP2STR(&event->ip_info.ip));  /* 打印ip地址*/
        retry_num = 0;                                              /* WiFi重连次数清零 */
        vTaskDelay(10000 / portTICK_PERIOD_MS);//断开WIFI时间 10S
        printf("WIFI DISCONNECT NOW.....\n");
        esp_wifi_disconnect();
       
    }
         
 
}




void wifi_init_sta(void)
{
    tcpip_adapter_init(); //初始化TCP/IP协议栈
    /* 创建默认事件循环,*/
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    /* 使用WIFI_INIT_CONFIG_DEFAULT() 来获取一个默认的wifi配置参数结构体变量*/
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    /* 根据cfg参数初始化wifi连接所需要的资源 */
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

	/* 将事件处理程序注册到系统默认事件循环，分别是WiFi事件、IP地址事件及smartconfig事件 */
    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL));
   

    /* 定义WiFi连接的ssid和password参数 */
    wifi_config_t wifi_config = {
        .sta = {
            .ssid     = WIFI_SSID ,
            .password = WIFI_PASSWD
        },
    };
    /* 设置WiFi的工作模式为 STA */
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA) );
    /* 设置WiFi连接的参数，主要是ssid和password */
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config));
    /* 启动WiFi连接 */
    ESP_ERROR_CHECK(esp_wifi_start());

    printf("wifi_init_sta finished. \n");
  
}