#include "stm32f4xx_hal.h"

 /* This function configures the LED pins
 */
unsigned int t = 0;

void SysTick_Handler(void)
{
    t++;
} /* SysTick_Handler */


void delay(unsigned int msDelay)
{
	
	int tick_end = t + msDelay;
	while (t < tick_end){
	
	};
}
	

void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    // GPIO Ports Clock Enable
    __GPIOG_CLK_ENABLE();

    // Configure GPIO pin PG.13
    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // push-pull output
    GPIO_InitStruct.Pull = GPIO_NOPULL; // no pull
    GPIO_InitStruct.Speed = GPIO_SPEED_LOW; // analog pin bandwidth limited
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

} /* LED_Init */

/**
 * Introduces a noticable delay in program execution
 */




/** Application entry point */
int main(void)
{
  // Initialize STM32Cube HAL library
  HAL_Init();
  // Initialize LED pins
  LED_Init();
  
  while (1) {
    // toggle the PG.13 pin on and off
    HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_13);
    // introduce 500ms delay
    delay(1000);
  } // while (1)
} /* main */