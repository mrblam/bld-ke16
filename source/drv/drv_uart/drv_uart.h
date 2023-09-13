/*
 * drv_uart.h
 *
 *  Created on: Sep 8, 2023
 *      Author: hoanpx
 */

#ifndef DRV_DRV_UART_DRV_UART_H_
#define DRV_DRV_UART_DRV_UART_H_
/*************************************************/
typedef enum {
    UART0 = 0,
    UART1 = 1,
    UART2 = 2,
    UART_undef = 0xFF
}UART_Instance;
typedef enum {
    error = 1,
    success = 0,
    status_undefine = 0xFF
}status;
typedef enum {
    UART_STATE_RESET = 0,
    UART_STATE_READY = 1,
    UART_STATE_BUSY = 2,
    UART_STATE_BUSY_TX = 3,
    UART_STATE_BUSY_RX = 4,
    State_undefine = 0xFF
}Drv_UART_State;
typedef void (*call_back)(void);
typedef struct uart_config{
    bool        is_DMA;
    bool        is_IRQ;
    bool        enableTX;
    bool        enableRX;
    call_back   tx_call_back;
    call_back   rx_call_back;
    call_back   error_call_back;
    uint32_t    baud;
    uint8_t     parity;
    uint8_t     dataLength;
    uint8_t     stopBit;
}uart_config;
/*************************************************/
/*
 * @brief
 * @param
 * @param
 * @retval
 */
status DRV_UART_Init(UART_Instance uart_instance,uart_config* config);
/*
 * @brief This function waits for transmit to complete, disables TX and RX, and disables the UART clock.
 *  status DRV_UART_DeInit(UART_Instance uart_instance);
 * @param
 * @param
 * @retval
 */
status DRV_UART_SendDataBlocking(UART_Instance uart_instance,uint8_t* data,uint16_t lengh);
status DRV_UART_SendDataInterrup(UART_Instance uart_instance,uint8_t* data,uint16_t lengh);
status DRV_UART_SendDataDMA(UART_Instance uart_instance,uint8_t* data,uint16_t lengh);
status DRV_UART_ReceiveDataBlocking(UART_Instance* uart_instance,uint8_t* data,uint16_t lengh);
status DRV_UART_ReceivedNonBlocking(UART_Instance uart_instance,uint8_t* data,uint16_t lengh);
status DRV_UART_ReceiveDataDMA(UART_Instance uart_instance,uint8_t* data,uint16_t lengh);
status DRV_UART_RegisterCallback(call_back func_ptr);
#endif /* DRV_DRV_UART_DRV_UART_H_ */
