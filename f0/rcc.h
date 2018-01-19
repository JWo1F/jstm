/**
 * RCC functions
 * 
 * Author: JWo1F
 * Date: 14.01.2017
*/

#include "cmsis/platform/stm32f0xx.h"

void $rcc_clock_setup_hsi();
void $rcc_set_ahb_periph_clock(uint32_t RCC_Type, uint32_t status);
void $rcc_set_apb1_periph_clock(uint32_t RCC_Type, uint32_t status);
void $rcc_set_apb2_periph_clock(uint32_t RCC_Type, uint32_t status);