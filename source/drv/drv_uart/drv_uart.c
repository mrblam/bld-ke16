/*
 * drv_uart.c
 *
 *  Created on: Sep 8, 2023
 *      Author: hoanpx
 */
/*************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "drv_uart.h"
#include "hal/hal_port/hal_port.h"
#include "hal/hal_clock/hal_clock.h"
#include "hal/hal_uart/hal_uart.h"
/*************************************************/
#define EN_RX_IRQ               1
#define DISABLE	                0
#define SBR_MAX					8191U
#define CLK_SRC					48000000U
/*************************************************/
typedef struct communication{
    uint8_t* buffer;
    uint16_t length;
    uint16_t index;
    Drv_UART_State state;
}communication;
static communication s_rx;
static call_back   rx_call_back = NULL;
/*************************************************/
void LPUART0_IRQHandler(void)
{
#if 0
    if(s_rx.index == s_rx.length){
        s_rx.index = 0;
        rx_call_back();
    }
#endif
    if (s_rx.index < 100) {
        s_rx.buffer[s_rx.index] = HAL_UART_DATA_Read(UART0);
        s_rx.index++;
        if (s_rx.buffer[s_rx.index - 1] == '\n') {
            rx_call_back();
            s_rx.index = 0;
        }
//        HAL_Init_SystemTick(960000);
    } else {
        s_rx.index = 0;
    }
}
status DRV_UART_Init(UART_Instance uart_instance,uart_config* config){
    /*Clk-SCG(busclk,Div)-PCC(CGC,PCS)*/
    HAL_CLOCK_SCG_FIRCDIV_Write(DIV1);
    /*PCC*/
    HAL_CLOCK_PCC_UART_PCS_Write(FISR_CLK_OPTION);/*Select FIRC is source for uart0*/
    HAL_CLOCK_PCC_UART_CGC_Write(CLK_EN);
    /*Port-Mux-In/Out*/
    HAL_CLOCK_PCC_PORTB_CGC_Write(1);
    HAL_PORT_PCR_MUX_Write(PortB, PIN0, ALT2);
    HAL_PORT_PCR_MUX_Write(PortB, PIN1, ALT2);
    /*BAUD*/
    DRV_UART_SetBaud(uart_instance,config->baud);
    /*CTRL*/
    HAL_UART_CTRL_RE_Write(uart_instance, config->enableRX);
    HAL_UART_CTRL_TE_Write(uart_instance, config->enableTX);
    HAL_UART_CTRL_RIE_Write(uart_instance, config->is_IRQ);
    /*Register Callback*/
    rx_call_back = config->rx_call_back;
    /*IRQ*/
    HAL_UART_NVIC_Enable(uart_instance);
    return success;
}
status DRV_UART_DeInit(UART_Instance uart_instance){
    HAL_CLOCK_PCC_UART_CGC_Write(CLK_DIS);
    return success;
}
status DRV_UART_ReceivedNonBlocking(UART_Instance uart_instance, uint8_t* const data,uint16_t lengh){
    s_rx.buffer = data;
    s_rx.length = lengh;
    HAL_UART_CTRL_RIE_Write(uart_instance, EN_RX_IRQ);
    return success;
}
status DRV_UART_RegisterCallback(call_back func_ptr){
    rx_call_back = func_ptr;
    return success;
}
status DRV_UART_SendDataBlocking(UART_Instance uart_instance,const char* const data,uint16_t lengh){
    uint8_t i;
    for(i = 0;i < lengh;i++){
        HAL_UART_DATA_Write(uart_instance, *(&data[i]));
        for(int i = 0;i < 10000;i++){
               __asm("nop");
        }
//      while(!HAL_UART_ReadTC(uart_hal));
    }
    return success;
}
status DRV_UART_SetBaud(UART_Instance uart_instance,uint32_t baudrate){
#if 0
	uint8_t	 osrValue = 0U;
	uint8_t	 osrTemp = 0U;
	uint16_t sbrValue = 0U;
	uint16_t sbrTemp = 0U;
	uint32_t baudTemp = 0U;
	uint32_t baudDiff = baudrate;
	uint32_t tempDiff = 0U;
	for (osrTemp = 4U; osrTemp < 32U; osrTemp++)
	{
	    sbrTemp = (uint16_t)(CLK_SRC/(baudrate*(osrTemp + 1)));
	    baudTemp = (CLK_SRC/((sbrTemp)*(osrTemp + 1)));
	    tempDiff = baudTemp > baudrate ? (baudTemp - baudrate) : (baudrate - baudTemp);
	    if (tempDiff <= baudDiff)
	    {
	        baudDiff = tempDiff;
	        osrValue = osrTemp;
	        sbrValue = sbrTemp;
	    }
	}
#endif
    HAL_UART_BAUD_SBR_Write(uart_instance, 78);//312//78
    HAL_UART_BAUD_OSR_Write(uart_instance, 15);//15//15
	return success;
}


