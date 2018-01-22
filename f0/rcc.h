/**
 * RCC functions
 * 
 * Author: JWo1F
 * Date: 14.01.2017
*/

#include "cmsis/platform/stm32f0xx.h"

typedef enum {
  RCC_Clock_HSI,
  RCC_Clock_HSE,
  RCC_Clock_PLL,
  RCC_Clock_LSI, // cannot use for SYSClock
  RCC_Clock_LSE // cannot use fro SYSClock
} RCCClock_TypeDef;

void rcc_clock_setup(RCCClock_TypeDef, FunctionalState);
void rcc_clock_use(RCCClock_TypeDef);
void rcc_set_ahb_periph_clock(uint32_t RCC_Type, uint32_t status);
void rcc_set_apb1_periph_clock(uint32_t RCC_Type, uint32_t status);
void rcc_set_apb2_periph_clock(uint32_t RCC_Type, uint32_t status);