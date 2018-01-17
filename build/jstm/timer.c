#include "cmsis/platform/stm32f0xx.h"
#include "timer.h"

void timer_init(TIM_TypeDef* timer, uint32_t period, uint16_t prescaler, TIMClockDivision_TypeDef clockDivision, TIMCounterMode_TypeDef counterMode, uint8_t repetitionCounter) {
  uint16_t cr1 = timer->CR1;
  
  if(timer == TIM1 || timer == TIM2 || timer == TIM3) {
    cr1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS);
    cr1 |= counterMode;
  }

  if(timer != TIM6) {
    cr1 &= ~TIM_CR1_CKD;
    cr1 |= clockDivision;
  }

  timer->CR1 = cr1;
  timer->ARR = period;
  timer->PSC = prescaler;

  if(timer == TIM1 || timer == TIM15 || timer == TIM16 || timer == TIM17) {
    timer->RCR = repetitionCounter;
  }

  timer->EGR = 1; // Generate update event
}

void timer_set_interrupt_status(TIM_TypeDef* timer, uint16_t interrupt, FunctionalState status) {
  if(status == ENABLE) timer->DIER |= interrupt;
  else timer->DIER &= ~interrupt;
}

void timer_set_status(TIM_TypeDef* timer, FunctionalState status) {
  if(status == ENABLE) timer->CR1 |= TIM_CR1_CEN;
  else timer->CR1 &= ~TIM_CR1_CEN;
}