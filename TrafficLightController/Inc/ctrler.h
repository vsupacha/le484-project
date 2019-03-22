#ifndef __CTRLER_H
#define __CTRLER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include "main.h"

typedef enum {
    NO_EVT,
    BUTTON,
    TIMEOUT,
    MODE_CHANGE
} Event_t;

typedef enum {
    RESTART, 
    THROUGH, 
    BLOCKED, 
    WAIT, 
    OUT_OF_SERVICE
} Ctrler_State_t;

void Ctrler_Init(void);
uint32_t Ctrler_Exec(Event_t evt);


#ifdef __cplusplus
}
#endif

#endif /* __CTRLER_H */
