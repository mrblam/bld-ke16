/*
 * hal_uart.c
 *
 *  Created on: Sep 10, 2023
 *      Author: hoanpx
 */
/*************************************************/
#include <stdint.h>
#include <MKE16Z4.h>
#include "hal_uart.h"
/*************************************************/
const IRQn_Type s_lpuartIRQ[] = LPUART_RX_TX_IRQS;
static LPUART_Type* const s_lpuartBases[] = LPUART_BASE_PTRS;
/*************************************************/
int8_t HAL_UART_BAUD_SBR_Write(uint8_t instance,uint16_t value){
    s_lpuartBases[instance]->BAUD |= LPUART_BAUD_SBR(value);
    return 0;
}
int8_t HAL_UART_BAUD_OSR_Write(uint8_t instance,uint8_t value){
    s_lpuartBases[instance]->BAUD |= LPUART_BAUD_OSR(value);
    return 0;
}
int8_t HAL_UART_CTRL_RE_Write(uint8_t instance,uint8_t value){
    s_lpuartBases[instance]->CTRL |= LPUART_CTRL_RE(value);
    return 0;
}
int8_t HAL_UART_CTRL_TE_Write(uint8_t instance,uint8_t value){
    s_lpuartBases[instance]->CTRL |= LPUART_CTRL_TE(value);
    return 0;
}
int8_t HAL_UART_CTRL_RIE_Write(uint8_t instance,uint8_t value){
    s_lpuartBases[instance]->CTRL |= LPUART_CTRL_RIE(value);
    return 0;
}
int8_t HAL_UART_DATA_Write(uint8_t instance,uint8_t value){
    s_lpuartBases[instance]->DATA = value;
    return 0;
}
uint8_t HAL_UART_DATA_Read(uint8_t instance){
    return (uint8_t)(s_lpuartBases[instance]->DATA & 0x7FU);
}
uint8_t HAL_UART_STAT_TDRE_Read(uint8_t instance){
    uint8_t TDRE;
    TDRE = ((s_lpuartBases[instance]->STAT) | ~LPUART_STAT_TDRE_MASK) >> LPUART_STAT_TDRE_SHIFT;
    return TDRE;
}
uint8_t HAL_UART_STAT_TC_Read(uint8_t instance){
    uint8_t TC;
    TC = ((s_lpuartBases[instance]->STAT) | ~LPUART_STAT_TC_MASK) >> LPUART_STAT_TC_SHIFT;
    return TC;
}
uint8_t HAL_UART_NVIC_Enable(uint8_t instance){
    NVIC_EnableIRQ(s_lpuartIRQ[instance]);
    return 0;
}
