#include "timer.h"

volatile uint32_t Tick = 0;
uint32_t Timeout_Value = 0;
int Timeout_Status = 0;

/** @brief Set timeout value
*/
void Timeout_Config(uint32_t timeout_value)
{
    if (timeout_value > 0) {
        Timeout_Value = Tick + timeout_value;
    }
}

/** @brief Delay by 0.1 second resolution
*/
void Delay(uint32_t delay_value)
{
    uint32_t start_tick = Tick;
    
    while ((Tick - start_tick) < delay_value);
}

/** @brief Update Tick every 0.1 second and check timeout
*/
void HAL_IncTick(void)
{
    static int Count = 0;
    Count = (Count+1)%100;
    if (Count == 0) {
        Tick++;
        if (Tick == Timeout_Value) {
            Timeout_Status = 1;
        }
    }
}
