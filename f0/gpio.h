/**
 * RCC functions
 * 
 * Author: JWo1F
 * Date: 14.01.2017
*/

#include "cmsis/platform/stm32f0xx.h"

typedef enum {
  GPIO_Mode_IN = 0x00,
  GPIO_Mode_OUT = 0x01,
  GPIO_Mode_AF = 0x02,
  GPIO_Mode_AN = 0x03
} GPIOMode_TypeDef;

typedef enum {
  GPIO_Speed_2Mhz = 0b00,
  GPIO_Speed_10Mhz = 0b01,
  GPIO_Speed_50Mhz = 0b11
} GPIOSpeed_TypeDef;

typedef enum {
  GPIO_OType_PP = 0x00,
  GPIO_OType_OD = 0x01
} GPIOOType_TypeDef;

typedef enum {
  GPIO_PuPd_NOPULL = 0x00,
  GPIO_PuPd_UP     = 0x01,
  GPIO_PuPd_DOWN   = 0x02
} GPIOPuPd_TypeDef;

typedef struct {
  GPIO_TypeDef* port;
  uint32_t pin;
  GPIOMode_TypeDef mode;
  GPIOPuPd_TypeDef PuPd;
  GPIOSpeed_TypeDef speed; // Only if mode == OUT||AF
  GPIOOType_TypeDef oType; // Only if mode == OUT||AF
} GPIOInitType;

void $gpio_init_pin(GPIOInitType);
void $gpio_set_pin(GPIO_TypeDef* port, uint32_t pin, FunctionalState status);
void $gpio_toggle_pin(GPIO_TypeDef* port, uint32_t pin);