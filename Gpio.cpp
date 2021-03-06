#include "gpio.hpp"

/*
* 构造方法
* @param group: 分组
* @param pin: 引脚
*/
Gpio::Gpio(GPIO_TypeDef* group, uint16_t pin) {
	Gpio::group = group;
	Gpio::pin = pin;

	initPin();
}

/*
* 初始化引脚
*/
void Gpio::initPin() {
	//GPIO Ports Clock Enable
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	gpioStruct.Pin = pin;
	gpioStruct.Mode = OUTPUT;
	gpioStruct.Speed = GPIO_SPEED_FREQ_LOW;

	//Configure GPIO pin Output Level
	HAL_GPIO_WritePin(group, pin, GPIO_PIN_RESET);
	pinMode(OUTPUT);
}

/*
* 设置引脚分组
* @param group: 分组
*/
void Gpio::setGroup(GPIO_TypeDef* group) {
	Gpio::group = group;
	initPin();
}

/*
* 设置引脚
* @param: 引脚
*/
void Gpio::setPin(uint16_t pin) {
	Gpio::pin = pin;
	initPin();
}

/*
* 设置引脚模式
* @param pinMode: 引脚模式(INPUT/OUTPUT)
*/
void Gpio::pinMode(int pinMode) {
	gpioStruct.Mode = pinMode;
	HAL_GPIO_Init(group, &gpioStruct);
}

/*
* 写引脚
* @param state: 引脚状态(LOW/HIGH)
*/
void Gpio::digitalWrite(GPIO_PinState state) {
	if (Gpio::group != 0 && Gpio::pin != 0) {
		HAL_GPIO_WritePin(group, pin, state);
	}
}

/*
* 读取引脚
* @return: 引脚状态(LOW/HIGH)
*/
int Gpio::digitalRead() {
	return HAL_GPIO_ReadPin(group, pin);
}

/**
 * 切换引脚状态
 */
void Gpio::digitalTogglePin() {
	HAL_GPIO_TogglePin(group, pin);
}