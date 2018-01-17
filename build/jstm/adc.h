/**
 * ADC functions
 * 
 * Author: JWo1F
 * Date: 14.01.2017
*/

#include "cmsis/platform/stm32f0xx.h"

typedef enum {
  ADC_Resolution_12b = 0x00,
  ADC_Resolution_10b = ADC_CFGR1_RES_0,
  ADC_Resolution_8b = ADC_CFGR1_RES_1,
  ADC_Resolution_6b = ADC_CFGR1_RES
} ADCResolution_TypeDef;

typedef enum {
  ADC_ExternalTrigConvEdge_None = 0x00,
  ADC_ExternalTrigConvEdge_Rising = ADC_CFGR1_EXTEN_0,
  ADC_ExternalTrigConvEdge_Falling = ADC_CFGR1_EXTEN_1,
  ADC_ExternalTrigConvEdge_RisingFalling = ADC_CFGR1_EXTEN
} ADCExternalTrigConvEdge_TypeDef;

typedef enum {
  // TIM1
  ADC_ExternalTrigConv_T1_TRGO = 0x00,
  ADC_ExternalTrigConv_T1_CC4 = ADC_CFGR1_EXTSEL_0,
  // TIM2
  ADC_ExternalTrigConv_T2_TRGO = ADC_CFGR1_EXTSEL_1,
  // TIM3
  ADC_ExternalTrigConv_T3_TRGO = ADC_CFGR1_EXTSEL_0 | ADC_CFGR1_EXTSEL_1,
  // TIM15
  ADC_ExternalTrigConv_T15_TRGO = ADC_CFGR1_EXTSEL_2
} ADCExternalTrigConv_TypeDef;

typedef enum {
  ADC_DataAlign_Right = 0x00,
  ADC_DataAlign_Left = ADC_CFGR1_ALIGN
} ADCDataAlign_TypeDef;

typedef enum {
  ADC_ScanDirection_Upward = 0x00,
  ADC_ScanDirection_Backward = ADC_CFGR1_SCANDIR
} ADCScanDirection_TypeDef;

typedef enum {
  ADC_Channel_0 = ADC_CHSELR_CHSEL0,
  ADC_Channel_1 = ADC_CHSELR_CHSEL1,
  ADC_Channel_2 = ADC_CHSELR_CHSEL2,
  ADC_Channel_3 = ADC_CHSELR_CHSEL3,
  ADC_Channel_4 = ADC_CHSELR_CHSEL4,
  ADC_Channel_5 = ADC_CHSELR_CHSEL5,
  ADC_Channel_6 = ADC_CHSELR_CHSEL6,
  ADC_Channel_7 = ADC_CHSELR_CHSEL7,
  ADC_Channel_8 = ADC_CHSELR_CHSEL8,
  ADC_Channel_9 = ADC_CHSELR_CHSEL9,
  ADC_Channel_10 = ADC_CHSELR_CHSEL10,
  ADC_Channel_11 = ADC_CHSELR_CHSEL11,
  ADC_Channel_12 = ADC_CHSELR_CHSEL12,
  ADC_Channel_13 = ADC_CHSELR_CHSEL13,
  ADC_Channel_14 = ADC_CHSELR_CHSEL14,
  ADC_Channel_15 = ADC_CHSELR_CHSEL15,
  ADC_Channel_16 = ADC_CHSELR_CHSEL16,
  ADC_Channel_17 = ADC_CHSELR_CHSEL17
} ADCChannel_TypeDef;

typedef enum {
  ADC_SampleTime_1_5Cycles = 0x00,
  ADC_SampleTime_7_5Cycles,
  ADC_SampleTime_13_5Cycles,
  ADC_SampleTime_28_5Cycles,
  ADC_SampleTime_41_5Cycles,
  ADC_SampleTime_55_5Cycles,
  ADC_SampleTime_71_5Cycles,
  ADC_SampleTime_239_5Cycles
} ADCSampleTime_TypeDef;

void adc_init(ADC_TypeDef* adc, ADCResolution_TypeDef resolution, FunctionalState continuousConvMode, ADCExternalTrigConvEdge_TypeDef externalTrigConvEdge, ADCExternalTrigConv_TypeDef externalTrigConv, ADCDataAlign_TypeDef dataAlign, ADCScanDirection_TypeDef scanDirection);
void adc_start_conversion(ADC_TypeDef* adc);
uint32_t adc_get_conversion_value(ADC_TypeDef* adc);
void adc_channel_config(ADC_TypeDef* adc, ADCChannel_TypeDef channel);
void adc_set_sample_time(ADC_TypeDef* adc, ADCSampleTime_TypeDef sampleTime);
void adc_calibration(ADC_TypeDef* adc);
void adc_enable(ADC_TypeDef* adc);
void adc_disable(ADC_TypeDef* adc);