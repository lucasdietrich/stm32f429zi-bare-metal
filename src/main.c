#include <stm32f429xx.h>

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_gpio.h>
#include <stm32f4xx_hal_gpio_ex.h>

#include <stm32f4xx_ll_gpio.h>

#define LED_RED_PIN                                 GPIO_PIN_14
#define LED_RED_GPIO_PORT                           GPIOB
#define LED_RED_GPIO_CLK_ENABLE()                   __HAL_RCC_GPIOB_CLK_ENABLE()

int main(void)
{
	HAL_Init();

	LED_RED_GPIO_CLK_ENABLE();

	HAL_GPIO_Init(LED_RED_GPIO_PORT, &(GPIO_InitTypeDef) {
		.Pin = LED_RED_PIN,
		.Mode = GPIO_MODE_OUTPUT_PP,
		.Pull = GPIO_PULLUP,
		.Speed = GPIO_SPEED_FREQ_HIGH
	});

	HAL_GPIO_WritePin(LED_RED_GPIO_PORT, LED_RED_PIN, GPIO_PIN_SET);
	
	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_InitStruct = {
		.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12,
		.Mode = GPIO_MODE_OUTPUT_PP,
		.Pull = GPIO_PULLUP,
		.Speed = GPIO_SPEED_FREQ_HIGH
	};

	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_8 | LL_GPIO_PIN_9 | LL_GPIO_PIN_10 | LL_GPIO_PIN_11 | LL_GPIO_PIN_12);
	
	uint32_t counter = 0;

	for (;;) {
		for (uint32_t bit = 0U; bit < 5U; bit++) {
			if (counter & (1U << bit)) {
				LL_GPIO_SetOutputPin(GPIOC, GPIO_PIN_8 << bit);
			} else {
				LL_GPIO_ResetOutputPin(GPIOC, GPIO_PIN_8 << bit);
			}
		}

		HAL_GPIO_TogglePin(LED_RED_GPIO_PORT, LED_RED_PIN);

		HAL_Delay(1);

		counter++;
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
