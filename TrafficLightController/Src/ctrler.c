#include "ctrler.h"
#include "bsp.h"

Ctrler_State_t Ctrler_State = RESTART;

void Ctrler_Init()
{
}

uint32_t Ctrler_Exec(Event_t evt)
{
    uint32_t timeout_value = 0;
    
    switch(Ctrler_State) {
        case RESTART:
            break;
        default:
            Ctrler_State = OUT_OF_SERVICE;
    }
    return timeout_value;
}
