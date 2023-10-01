#include"main.h"
#include"cmsis_os2.h"

static const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

static void task(void *argument){
    for(;;){
        HAL_GPIO_WritePin(BUILTIN_LED_GPIO_Port, BUILTIN_LED_Pin, 1);
        osDelay(1000);
        HAL_GPIO_WritePin(BUILTIN_LED_GPIO_Port, BUILTIN_LED_Pin, 0);
        osDelay(500);
    }
}

void testInit(){
    // osThreadNew(task, NULL, &defaultTask_attributes);
}