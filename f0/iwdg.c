#include "cmsis/platform/stm32f0xx.h"
#include "iwdg.h"

void iwdg_set_write_access(FunctionalState status) {
  IWDG->KR = status == ENABLE ? 0x5555 : 0x0000;
}

void iwdg_set_prescaler(IWDGPrescaler_TypeDef prescaler) {
  IWDG->PR = prescaler;
}

void iwdg_set_reload(uint16_t reload) {
  IWDG->RLR = reload;
}

void iwdg_set_window_value(uint16_t value) {
  IWDG->WINR = value;
}

void iwdg_reload_counter() {
  IWDG->KR = 0xAAAA;
}

void iwdg_wait_for_update() {
  while(IWDG->SR != 0);
}

void iwdg_enable() {
  IWDG->KR = 0xCCCC;
}