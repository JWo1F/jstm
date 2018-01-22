#include "cmsis/platform/stm32f0xx.h"
#include "timer.h"

void timer_init(TIMInitType init) {
  uint16_t cr1 = init.timer->CR1;
  
  if(init.timer == TIM1 || init.timer == TIM2 || init.timer == TIM3) {
    cr1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS);
    cr1 |= init.counterMode;
  }

  if(init.timer != TIM6) {
    cr1 &= ~TIM_CR1_CKD;
    cr1 |= init.clockDivision;
  }

  init.timer->CR1 = cr1;
  init.timer->ARR = init.period;
  init.timer->PSC = init.prescaler;

  if(init.timer == TIM1 || init.timer == TIM15 || init.timer == TIM16 || init.timer == TIM17) {
    init.timer->RCR = init.repetitionCounter;
  }

  TIM16->EGR |= TIM_EGR_UG; // Disable auto-update inerrupt
}

void timer_set_interrupt_status(TIM_TypeDef* timer, uint16_t interrupt, FunctionalState status) {
  if(status == ENABLE) timer->DIER |= interrupt;
  else timer->DIER &= ~interrupt;
}

void timer_set_status(TIM_TypeDef* timer, FunctionalState status) {
  if(status == ENABLE) timer->CR1 |= TIM_CR1_CEN;
  else timer->CR1 &= ~TIM_CR1_CEN;
}