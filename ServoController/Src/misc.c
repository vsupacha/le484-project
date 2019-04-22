#include "misc.h"


void Motor_Drive(int pwm_value)    
{
  if (pwm_value == 0) {
    HAL_GPIO_WritePin(INA_SIGNAL_GPIO_Port, INA_SIGNAL_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(INB_SIGNAL_GPIO_Port, INB_SIGNAL_Pin, GPIO_PIN_SET);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
    return;
  }
  if (pwm_value > 0) {
    HAL_GPIO_WritePin(INA_SIGNAL_GPIO_Port, INA_SIGNAL_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(INB_SIGNAL_GPIO_Port, INB_SIGNAL_Pin, GPIO_PIN_RESET);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, pwm_value);
  } else {
    HAL_GPIO_WritePin(INA_SIGNAL_GPIO_Port, INA_SIGNAL_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(INB_SIGNAL_GPIO_Port, INB_SIGNAL_Pin, GPIO_PIN_SET);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, -pwm_value);  
  }
}


void Pin_Trigger()
{
  HAL_GPIO_WritePin(TRIG_SIGNAL_GPIO_Port, TRIG_SIGNAL_Pin, GPIO_PIN_SET);
  HAL_Delay(10);
  HAL_GPIO_WritePin(TRIG_SIGNAL_GPIO_Port, TRIG_SIGNAL_Pin, GPIO_PIN_RESET);
}


uint16_t Speed_Read()
{
  float volt_value;
  int speed_value = 0;
    
  HAL_ADC_Start(&hadc1);
  HAL_ADC_PollForConversion(&hadc1, 1000);
  volt_value = HAL_ADC_GetValue(&hadc1) / 4095 * 3.3F;
  if ((volt_value >= 1.0F) && (volt_value <= 3.0F)) {    // 1.0V - 3.0V
    speed_value = (volt_value - 1.0F) / 2.0F * 90 + 10;  // 10 Hz - 100 Hz
  } else if (volt_value < 1.0F) {
    speed_value = 10;  
  } else if(volt_value > 3.0F) {
    speed_value = 100;   
  }
  return speed_value;
}
