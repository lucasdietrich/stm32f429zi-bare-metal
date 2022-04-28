#include <stm32f429xx.h>

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_gpio.h>
#include <stm32f4xx_hal_gpio_ex.h>


/* from UM1974 :
	User LD1: a green user LED is connected to the STM32 I/O PB0 (SB120 ON and SB119
	OFF) or PA5 (SB119 ON and SB120 OFF) corresponding to the ST Zio D13.
	User LD2: a blue user LED is connected to PB7.
	User LD3: a red user LED is connected to PB14.
*/

#define LED_GREEN_PIN                               GPIO_PIN_0
#define LED_GREEN_GPIO_PORT                         GPIOB
#define LED_GREEN_GPIO_CLK_ENABLE()                 __HAL_RCC_GPIOB_CLK_ENABLE()

#define LED_BLUE_PIN                                GPIO_PIN_7
#define LED_BLUE_GPIO_PORT                          GPIOB
#define LED_BLUE_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOB_CLK_ENABLE()

#define LED_RED_PIN                                 GPIO_PIN_14
#define LED_RED_GPIO_PORT                           GPIOB
#define LED_RED_GPIO_CLK_ENABLE()                   __HAL_RCC_GPIOB_CLK_ENABLE()

#define LED_PIN LED_RED_PIN
#define LED_GPIO_PORT LED_RED_GPIO_PORT
#define LED_GPIO_CLK_ENABLE LED_RED_GPIO_CLK_ENABLE

int main(void)
{
	HAL_Init();

	LED_GPIO_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_InitStruct = {
		.Pin = LED_PIN,
		.Mode = GPIO_MODE_OUTPUT_PP,
		.Pull = GPIO_PULLUP,
		.Speed = GPIO_SPEED_FREQ_HIGH
	};

	HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);

	for (;;) {
		HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);

		HAL_Delay(1000);
	}
}

/*___________________________________________________________________________*/

void SysTick_Handler(void)
{
	HAL_IncTick();
}

void NMI_Handler(void)
{

}

void HardFault_Handler(void)
{
	while (1) {}
}


void MemManage_Handler(void)
{
	while (1) {}
}

void BusFault_Handler(void)
{
	while (1) {}
}

void UsageFault_Handler(void)
{
	while (1) {}
}

void SVC_Handler(void)
{

}


void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{

}
