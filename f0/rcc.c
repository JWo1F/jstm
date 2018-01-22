#include "cmsis/platform/stm32f0xx.h"
#include "rcc.h"

void rcc_set_ahb_periph_clock(uint32_t RCC_Type, uint32_t status) {
  if(status == ENABLE) RCC->AHBENR |= RCC_Type;
  else RCC->AHBENR &= ~RCC_Type;
}

void rcc_set_apb1_periph_clock(uint32_t RCC_Type, uint32_t status) {
  if(status == ENABLE) RCC->APB1ENR |= RCC_Type;
  else RCC->APB1ENR &= ~RCC_Type;
}

void rcc_set_apb2_periph_clock(uint32_t RCC_Type, uint32_t status) {
  if(status == ENABLE) RCC->APB2ENR |= RCC_Type;
  else RCC->APB2ENR &= ~RCC_Type;
}

void rcc_clock_setup(RCCClock_TypeDef type, FunctionalState status) {
  if(type == RCC_Clock_HSI) {
    if(status == ENABLE) {
      RCC->CR &= RCC_CR_HSION; // Enable HSI
      while((RCC->CR & RCC_CR_HSIRDY) == 0); // Wait HSI RDY
    } else {
      RCC->CR |= ~RCC_CR_HSION; // Disable HSI
    }
  } else if(type == RCC_Clock_HSE) {
    if(status == ENABLE) {
      RCC->CR |= RCC_CR_HSEON; // Enable HSE
      while((RCC->CR & RCC_CR_HSERDY) == 0); // Wait HSE RDY
    } else {
      RCC->CR &= ~RCC_CR_HSEON; // Disable HSE
    }
  } else if(type == RCC_Clock_LSI) {
    if(status == ENABLE) {
      RCC->CSR |= RCC_CSR_LSION;
      while((RCC->CSR & RCC_CSR_LSIRDY) == 0);
    } else {
      RCC->CSR &= ~RCC_CSR_LSION;
    }
  } else if(type == RCC_Clock_PLL) {
    if(status == ENABLE) {
      RCC->CR |= RCC_CR_PLLON; // Enable HSE
      while((RCC->CR & RCC_CR_PLLRDY) == 0); // Wait HSE RDY
    } else {
      RCC->CR &= ~RCC_CR_PLLON;
    }
  } else if(type == RCC_Clock_LSE) {
    if(status == ENABLE) {
      RCC->BDCR |= RCC_BDCR_LSEON;
      while((RCC->BDCR & RCC_BDCR_LSERDY) == 0);
    } else {
      RCC->BDCR &= ~RCC_BDCR_LSEON;
    }
  }
}

void rcc_clock_use(RCCClock_TypeDef type) {
  uint32_t cfgr = (RCC->CFGR & (~RCC_CFGR_SW));

  if(type == RCC_Clock_HSE) {
    cfgr |= RCC_CFGR_SW_HSE;
  } else if(type == RCC_Clock_HSI) {
    cfgr |= RCC_CFGR_SW_HSI;
  } else if(type == RCC_Clock_PLL) {
    cfgr |= RCC_CFGR_SW_PLL;
  }

  RCC->CFGR = cfgr;
}