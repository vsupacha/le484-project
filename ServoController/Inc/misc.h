#ifndef _MISC_H
#define _MISC_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include <stm32f4xx.h>
#include "main.h"


void Motor_Drive(int pwm_value);
void Pin_Trigger(void);
uint16_t Speed_Read(void);

#ifdef __cplusplus
}
#endif

#endif // _MISC_H
