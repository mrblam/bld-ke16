/*
 * drv_systick.c
 *
 *  Created on: Aug 26, 2023
 *      Author: PV
 */
/*************************************************/
#include <stdint.h>
#include <stddef.h>
#include "drv_systick.h"
#include "hal/hal_systick/hal_systick.h"
/*************************************************/
call_back sys_tick_callback = NULL;
/*************************************************/
void SysTick_Handler(void){
    sys_tick_callback();
}
int8_t DRV_Systick_Register_Callback(call_back func_ptr){
    sys_tick_callback = func_ptr;
	return 0;
}
int8_t DRV_Init_SysTick(uint32_t freq){
	HAL_Init_SystemTick(freq);
	return 0;
}
