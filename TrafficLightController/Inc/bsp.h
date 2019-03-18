#ifndef __BSP_H
#define __BSP_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "stm32f4xx_hal.h"

// exported global variables
extern int Button_Status;

// Function prototype
void BSP_Init(void);
void Signal_Pass(void);
void Signal_Block(void);
void Signal_Flash(void);

#ifdef __cplusplus
}
#endif

#endif // __BSP_H
