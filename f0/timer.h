/**
 * RCC functions
 * 
 * Author: JWo1F
 * Date: 14.01.2017
*/

#include "cmsis/platform/stm32f0xx.h"

typedef enum {
  TIM_Clock_Division_1 = 0x0000,
  TIM_Clock_Division_2 = 0x0100,
  TIM_Clock_Division_4 = 0x0200
} TIMClockDivision_TypeDef;

typedef enum {
  TIM_CounterMode_Up = 0x0000,
  TIM_CounterMode_Down = 0x0010,
  TIM_CounterMode_CenterAligned1 = 0x0020,
  TIM_CounterMode_CenterAligned2 = 0x0040,
  TIM_CounterMode_CenterAligned3 = 0x0060
} TIMCounterMode_TypeDef;

typedef struct {
  TIM_TypeDef* timer;
  uint32_t period;
  uint16_t prescaler;
  TIMClockDivision_TypeDef clockDivision; // Only if timer != TIM6
  TIMCounterMode_TypeDef counterMode; // Only if timer == TIM1||TIM2||TIM3
  uint8_t repetitionCounter; // Only if timer == TIM1||TIM15||TIM16||TIM17
} TIMInitType;

void timer_init(TIMInitType);
void timer_set_interrupt_status(TIM_TypeDef* timer, uint16_t interrupt, FunctionalState status);
void timer_set_status(TIM_TypeDef* timer, FunctionalState status);