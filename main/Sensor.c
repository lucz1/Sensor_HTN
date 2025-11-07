#include <stdio.h>
#include "driver/i2c.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "dht20.h"
#include "light_sensor.h"



void app_main(void)
{
    float temperature, humidity, light;

    ESP_ERROR_CHECK(i2c_master_init());
    printf("Khởi tạo I2C xong.\n");

    dht20_init();
    light_sensor_init();
    printf("Cảm biến DHT20 & cảm biến ánh sáng (ADC) sẵn sàng.\n");

    while (1)
    {
        if (dht20_read(&temperature, &humidity) == ESP_OK)
            printf("Nhiệt độ: %.2f °C | Độ ẩm: %.2f %%\n", temperature, humidity);
        else
            printf("Lỗi đọc DHT20!\n");

        if (light_sensor_read(&light) == ESP_OK)
            printf("Cường độ ánh sáng: %.2f \n", light);
        else
            printf("Lỗi đọc cảm biến ánh sáng!\n");

        printf("---------------------------------\n");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
