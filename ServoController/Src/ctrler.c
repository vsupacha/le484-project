#include "ctrler.h"


typedef enum {
  IDLE_STATE,
  RUNNING_STATE,
  ERROR_STATE
} Ctrler_State_t;

Ctrler_State_t Ctrl_State = IDLE_STATE;
int Position_Previous = 0;

void Ctrler_Exec(Event_t evt) 
{
  switch(Ctrl_State) {
    case IDLE_STATE:
      // STEP_EVT -> RUNNING_STATE/enable control loop
      if ((evt == STEP_EVT) && (Position_Target != 0)) {
        Ctrl_State = RUNNING_STATE;
        Position_Current = 0;
        Position_Previous = 0;
        Speed_Value = Speed_Read();    
        HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
        HAL_TIM_Base_Start_IT(&htim4);
      }
      // Encoder detected -> ERROR_STATE
      
      break;
    case RUNNING_STATE:
      // Target reached -> IDLE_STATE/disable control loop
      if (Position_Current == Position_Target) {
        Ctrl_State = IDLE_STATE;
        HAL_TIM_Base_Stop_IT(&htim4);
        Pin_Trigger();
      }
      // Encoder not detected -> ERROR_STATE/disable control loop
    
      break;
    case ERROR_STATE:
      // Print status  
      break;   
    default:
      Ctrl_State = IDLE_STATE;
  }      
}

void Ctrler_Loop()
{
  static int pwm_value = 0;
  int position_diff = Position_Current - Position_Previous;
  int error = Speed_Value - position_diff;
  pwm_value += 1 * error;  // I controller
  if (Position_Target != Position_Current) {  
    Motor_Drive(pwm_value);
  }
}
