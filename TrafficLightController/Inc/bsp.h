#ifndef __BSP_H
#define __BSP_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "stm32f4xx_hal.h"
#include "main.h"

// exported global variables
extern volatile int Button_Status;

// exported macros
#define RED_ON()        HAL_GPIO_WritePin(RED_LAMP_GPIO_Port, RED_LAMP_Pin, GPIO_PIN_SET)
#define RED_OFF()       HAL_GPIO_WritePin(RED_LAMP_GPIO_Port, RED_LAMP_Pin, GPIO_PIN_RESET)

#define MODE_READ()     (HAL_GPIO_ReadPin(MODE_SW_GPIO_Port, MODE_SW_Pin) == SET)
    
// Function prototype
void BSP_Init(void);
void Signal_Pass(void);
void Signal_Block(void);
void Signal_Flash(void);

#ifdef __cplusplus
}
#endif

#endif // __BSP_H
