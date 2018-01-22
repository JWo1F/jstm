/**
 * IWDG functions
 * 
 * Author: JWo1F
 * Date: 14.01.2017
*/

#include "cmsis/platform/stm32f0xx.h"

typedef enum {
  IWDG_Prescaler_4 = 0x00,
  IWDG_Prescaler_8 = 0x01,
  IWDG_Prescaler_16 = 0x02,
  IWDG_Prescaler_32 = 0x03,
  IWDG_Prescaler_64 = 0x04,
  IWDG_Prescaler_128 = 0x05,
  IWDG_Prescaler_256 = 0x06
} IWDGPrescaler_TypeDef;

void iwdg_set_write_access(FunctionalState);
void iwdg_set_prescaler(IWDGPrescaler_TypeDef);
void iwdg_set_reload(uint16_t);
void iwdg_set_window_value(uint16_t);
void iwdg_wait_for_update();
void iwdg_reload_counter();
void iwdg_enable();