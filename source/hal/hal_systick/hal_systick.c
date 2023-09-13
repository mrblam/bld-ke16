/*
 * hal_systick.c
 *
 *  Created on: Aug 27, 2023
 *      Author: PV
 */
/****************************************/
#include <stdio.h>
#include <MKE16Z4.h>
#include "hal_systick.h"
/****************************************/
uint32_t HAL_Init_SystemTick(uint32_t value){
    SysTick->LOAD  = (uint32_t)(value - 1UL);                         /* set reload register */
    NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL); /* set Priority for Systick Interrupt */
    SysTick->VAL   = 0UL;                                             /* Load the SysTick Counter Value */
    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                     SysTick_CTRL_TICKINT_Msk   |
                     SysTick_CTRL_ENABLE_Msk; /* Enable SysTick IRQ and SysTick Timer */
    return 0;
}
uint32_t HAL_DeInit_SystemTick(void){
	 SysTick->CTRL = (uint32_t)0;
	 return 0;
}
uint8_t HAL_SYSTICK_LOAD_Write(uint32_t value){
    SysTick->LOAD  = (uint32_t)(value - 1UL);
    return 0;
}
uint8_t HAL_SYSTICK_VAL_Write(uint32_t value){
    SysTick->VAL   = value;
    return 0;
}
uint8_t HAL_SYSTICK_CTRL_ENCLKSOURCE(void){
    SysTick->CTRL  |= SysTick_CTRL_CLKSOURCE_Msk;
    return 0;
}
uint8_t HAL_SYSTICK_CTRL_ENTICKINT(void){
    SysTick->CTRL  |= SysTick_CTRL_TICKINT_Msk;
    return 0;
}
uint8_t HAL_SYSTICK_CTRL_ENABLE(void){
    SysTick->CTRL  |= SysTick_CTRL_ENABLE_Msk;
    return 0;
}
