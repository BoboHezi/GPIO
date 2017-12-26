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
	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(group, pin, GPIO_PIN_RESET);
	pinMode(GPIO_MODE_OUTPUT_PP);
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
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = pin;
	GPIO_InitStruct.Mode = pinMode;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(group, &GPIO_InitStruct);
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