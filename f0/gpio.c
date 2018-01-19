#include "cmsis/platform/stm32f0xx.h"
#include "gpio.h"

void $gpio_init_pin(GPIOInitType init) {
  if(init.mode == GPIO_Mode_OUT || init.mode == GPIO_Mode_AF) {
    init.port->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0 << (init.pin * 2)); // Clear old speed
    init.port->OSPEEDR |= init.speed << (init.pin * 2); // Set current speed

    init.port->OTYPER &= ~(init.oType << init.pin); // Clear output mode
    init.port->OTYPER |= init.oType << init.pin; // Set output mode
  }

  init.port->MODER &= ~(GPIO_MODER_MODER0 << (init.pin * 2)); // Clear old moder
  init.port->MODER |= init.mode << (init.pin * 2); // Set mode

  init.port->PUPDR &= ~(GPIO_PUPDR_PUPDR0 << (init.pin * 2)); // Clear PuPd
  init.port->PUPDR |= init.PuPd << (init.pin * 2); // Set PuPd
}

void $gpio_set_pin(GPIO_TypeDef* port, uint32_t pin, FunctionalState status) {
  if(status == ENABLE) port->BSRR = 1<<pin;
  else port->BRR = 1<<pin;
}

void $gpio_toggle_pin(GPIO_TypeDef* port, uint32_t pin) {
  if(port->ODR & (1 << pin)) gpio_set_pin(port, pin, DISABLE);
  else gpio_set_pin(port, pin, ENABLE);
}