/*
 * hal_clock.c
 *
 *  Created on: Sep 11, 2023
 *      Author: hoanpx
 */
/*************************************************/
#include <MKE16Z4.h>
#include "hal_clock.h"
/*************************************************/
int8_t HAL_CLOCK_PCC_UART_PCS_Write(uint8_t value){
    PCC->CLKCFG[PCC_LPUART0_INDEX] |= PCC_CLKCFG_PCS(value); /*Select FIRC is source for uart0*/
    return 0;
}
int8_t HAL_CLOCK_PCC_UART_CGC_Write(uint8_t value){
    PCC->CLKCFG[PCC_LPUART0_INDEX] |= PCC_CLKCFG_CGC(value); /*after write pcs*/
    return 0;
}
int8_t HAL_CLOCK_SCG_FIRCDIV_Write(uint8_t value){
    SCG->FIRCDIV |= SCG_FIRCDIV_FIRCDIV2(value);
    return 0;
}
int8_t HAL_CLOCK_PCC_PORTB_CGC_Write(uint8_t value){
    PCC->CLKCFG[PCC_PORTB_INDEX] |= PCC_CLKCFG_CGC(value);
    return 0;
}
