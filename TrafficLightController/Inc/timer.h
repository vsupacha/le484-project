#ifndef __TIMER_H
#define __TIMER_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "stm32f4xx_hal.h"
#include "main.h"

extern volatile uint32_t Tick;
extern uint32_t Timeout_Value;
extern int Timeout_Status;
    
void Timeout_Config(uint32_t timeout_value); 
void Delay(uint32_t delay_value);
void HAL_IncTick(void);

#ifdef __cplusplus
}
#endif

#endif /* __TIMER_H */
