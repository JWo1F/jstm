#include "cmsis/platform/stm32f0xx.h"
#include "adc.h"

void $adc_init(ADCInitType init) {
  uint32_t config = init.adc->CFGR1 & 0b11111111111111111101001000000011; // Clear

  config |= init.resolution | init.continuousConvMode | init.externalTrigConvEdge | init.dataAlign | init.scanDirection;
  
  init.adc->CFGR1 = config;
}

void $adc_start_conversion(ADC_TypeDef* adc) {
  adc->CR |= ADC_CR_ADSTART;
}

uint32_t $adc_get_conversion_value(ADC_TypeDef* adc) {
  return adc->DR;
}

void $adc_channel_config(ADC_TypeDef* adc, ADCChannel_TypeDef channel) {
  adc->CHSELR |= channel;
}

void $adc_set_sample_time(ADC_TypeDef* adc, ADCSampleTime_TypeDef sampleTime) {
  adc->SMPR |= sampleTime;
}

void $adc_calibration(ADC_TypeDef* adc) {
  if(!(adc->CR & ADC_CR_ADEN)) {
    adc->CR |= ADC_CR_ADCAL; // start calibration
    while(adc->CR & ADC_CR_ADCAL); // wait calibration
  }
}

void $adc_enable(ADC_TypeDef* adc) {
  adc->CR |= ADC_CR_ADEN; // Enable ADC
  while(!(adc->ISR & ADC_ISR_ADRDY)); // Wait for Ready
}

void $adc_disable(ADC_TypeDef* adc) {
  adc->CR |= ADC_CR_ADDIS; // Disable ADC
  while(adc->CR & ADC_CR_ADEN); // Wait for Disable
}