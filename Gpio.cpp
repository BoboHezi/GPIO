#include "gpio.hpp"

/*
* ���췽��
* @param group: ����
* @param pin: ����
*/
Gpio::Gpio(GPIO_TypeDef* group, uint16_t pin) {
	Gpio::group = group;
	Gpio::pin = pin;

	initPin();
}

/*
* ��ʼ������
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
* �������ŷ���
* @param group: ����
*/
void Gpio::setGroup(GPIO_TypeDef* group) {
	Gpio::group = group;
	initPin();
}

/*
* ��������
* @param: ����
*/
void Gpio::setPin(uint16_t pin) {
	Gpio::pin = pin;
	initPin();
}

/*
* ��������ģʽ
* @param pinMode: ����ģʽ(INPUT/OUTPUT)
*/
void Gpio::pinMode(int pinMode) {
	gpioStruct.Mode = pinMode;
	HAL_GPIO_Init(group, &gpioStruct);
}

/*
* д����
* @param state: ����״̬(LOW/HIGH)
*/
void Gpio::digitalWrite(GPIO_PinState state) {
	if (Gpio::group != 0 && Gpio::pin != 0) {
		HAL_GPIO_WritePin(group, pin, state);
	}
}

/*
* ��ȡ����
* @return: ����״̬(LOW/HIGH)
*/
int Gpio::digitalRead() {
	return HAL_GPIO_ReadPin(group, pin);
}

/**
 * �л�����״̬
 */
void Gpio::digitalTogglePin() {
	HAL_GPIO_TogglePin(group, pin);
}