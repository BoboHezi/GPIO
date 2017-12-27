#ifndef GPIO_H
#define GPIO_H

#include "stm32f1xx_hal.h"

#define INPUT     GPIO_MODE_INPUT
#define OUTPUT    GPIO_MODE_OUTPUT_PP
#define OUTPUT_PP GPIO_MODE_OUTPUT_PP
#define OUTPUT_OD GPIO_MODE_OUTPUT_OD
#define LOW       GPIO_PIN_RESET
#define HIGH      GPIO_PIN_SET

class Gpio
{
public:
	
	Gpio(GPIO_TypeDef* group, uint16_t pin);
	
	void setGroup(GPIO_TypeDef* group);
	void setPin(uint16_t pin);
	void pinMode(int pinMode);
	void digitalWrite(GPIO_PinState state);
	int  digitalRead();
	void digitalTogglePin();
	
private:
	GPIO_TypeDef * group;
	uint16_t pin;
	
	void initPin();
};

#endif