/*
 * hal_uart.h
 *
 *  Created on: Sep 10, 2023
 *      Author: hoanpx
 */

#ifndef HAL_HAL_UART_HAL_UART_H_
#define HAL_HAL_UART_HAL_UART_H_
/*************************************************/
/*
 * @brief
 * @param
 * @param
 * @retval
 */
int8_t HAL_UART_BAUD_SBR_Write(uint8_t instance,uint16_t value);
int8_t HAL_UART_BAUD_OSR_Write(uint8_t instance,uint8_t value);
int8_t HAL_UART_CTRL_RE_Write(uint8_t instance,uint8_t value);
int8_t HAL_UART_CTRL_TE_Write(uint8_t instance,uint8_t value);
int8_t HAL_UART_CTRL_RIE_Write(uint8_t instance,uint8_t value);
int8_t HAL_UART_DATA_Write(uint8_t instance,uint8_t value);
uint8_t HAL_UART_DATA_Read(uint8_t instance);
uint8_t HAL_UART_STAT_TDRE_Read(uint8_t instance);
uint8_t HAL_UART_STAT_TC_Read(uint8_t instance);
uint8_t HAL_UART_NVIC_Enable(uint8_t instance);
#endif /* HAL_HAL_UART_HAL_UART_H_ */
