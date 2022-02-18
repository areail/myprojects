#include <stdio.h>
#include "esp_system.h"
#include "esp_event.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define RELAY_GPIO_PIN_1  (2)
#define RELAY_GPIO_PIN_2  (4)
#define RELAY_GPIO_PIN_3  (5)
#define RELAY_GPIO_PIN_4  (10)

void Relay_init(void)
{
  gpio_config_t io_config;
  io_config.mode = GPIO_MODE_INPUT_OUTPUT;
  io_config.pin_bit_mask = (1ULL << RELAY_GPIO_PIN_1 || 1ULL << RELAY_GPIO_PIN_2 ||
		  	  	  	  	  	  1ULL << RELAY_GPIO_PIN_3  || 1ULL << RELAY_GPIO_PIN_4 );
  io_config.pull_down_en=false;
  io_config.pull_up_en=false;
  io_config.intr_type=GPIO_INTR_DISABLE;
  gpio_config(&io_config);
}

void Relay_on(void)
{
  gpio_set_level(RELAY_GPIO_PIN_1,1);
  gpio_set_level(RELAY_GPIO_PIN_2,1);
  gpio_set_level(RELAY_GPIO_PIN_3,1);
  gpio_set_level(RELAY_GPIO_PIN_4,1);
}

void Relay_off(void)
{
  gpio_set_level(RELAY_GPIO_PIN_1,0);
  gpio_set_level(RELAY_GPIO_PIN_2,0);
  gpio_set_level(RELAY_GPIO_PIN_3,0);
  gpio_set_level(RELAY_GPIO_PIN_4,0);
}

