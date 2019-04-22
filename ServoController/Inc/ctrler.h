#ifndef _CTRL_H
#define _CTRL_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include <stm32f4xx.h>
#include "main.h"
    
    
typedef enum {
  NONE_EVT,  
  STEP_EVT
} Event_t;


void Ctrler_Exec(Event_t evt);
void Ctrler_Loop(void);


#ifdef __cplusplus
}
#endif

#endif // _CTRL_H
