#include "cmsis/platform/stm32f0xx.h"
#include "rcc.h"

void $rcc_set_ahb_periph_clock(uint32_t RCC_Type, uint32_t status) {
  if(status == ENABLE) RCC->AHBENR |= RCC_Type;
  else RCC->AHBENR &= ~RCC_Type;
}

void $rcc_set_apb1_periph_clock(uint32_t RCC_Type, uint32_t status) {
  if(status == ENABLE) RCC->APB1ENR |= RCC_Type;
  else RCC->APB1ENR &= ~RCC_Type;
}

void $rcc_set_apb2_periph_clock(uint32_t RCC_Type, uint32_t status) {
  if(status == ENABLE) RCC->APB2ENR |= RCC_Type;
  else RCC->APB2ENR &= ~RCC_Type;
}

void $rcc_clock_setup_hsi() {
  RCC->CR ^= RCC_CR_HSION; // Enable HSI
  while(!(RCC->CR & RCC_CR_HSIRDY)); // Wait HSI RDY
  RCC->CFGR = (RCC->CFGR & (~RCC_CFGR_SW)) | RCC_CFGR_SW_HSI; // Move to HSI
}