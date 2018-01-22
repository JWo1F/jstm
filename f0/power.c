#include "cmsis/platform/stm32f0xx.h"
#include "power.h"

void pwr_go_to_standby() {
  PWR->CR |= PWR_CR_PDDS;
  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
  __WFI();
}