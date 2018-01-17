#include "cmsis/platform/stm32f0xx.h"
#include "gpio.h"

void gpio_init_pin(GPIO_TypeDef* port, uint32_t pin, GPIOMode_TypeDef mode, GPIOPuPd_TypeDef PuPd, GPIOSpeed_TypeDef speed, GPIOOType_TypeDef oType) {
  if(mode == GPIO_Mode_OUT || mode == GPIO_Mode_AF) {
    port->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0 << (pin * 2)); // Clear old speed
    port->OSPEEDR |= speed << (pin * 2); // Set current speed

    port->OTYPER &= ~(oType << pin); // Clear output mode
    port->OTYPER |= oType << pin; // Set output mode
  }

  port->MODER &= ~(GPIO_MODER_MODER0 << (pin * 2)); // Clear old moder
  port->MODER |= mode << (pin * 2); // Set mode

  port->PUPDR &= ~(GPIO_PUPDR_PUPDR0 << (pin * 2)); // Clear PuPd
  port->PUPDR |= PuPd << (pin * 2); // Set PuPd
}

void gpio_set_pin(GPIO_TypeDef* port, uint32_t pin, FunctionalState status) {
  if(status == ENABLE) port->BSRR = 1<<pin;
  else port->BRR = 1<<pin;
}

void gpio_toggle_pin(GPIO_TypeDef* port, uint32_t pin) {
  if(port->ODR & (1 << pin)) gpio_set_pin(port, pin, DISABLE);
  else gpio_set_pin(port, pin, ENABLE);
}