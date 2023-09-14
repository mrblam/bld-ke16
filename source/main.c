/*
 * drv_uart.c
 *
 *  Created on: Sep 10, 2023
 *      Author: hoanpx
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "drv/drv_uart/drv_uart.h"
#include "drv/drv_flash/drv_flash.h"
#include "drv/drv_gpio/drv_gpio.h"
#include "app/app_queue/app_queue.h"
#include "app/app_srec/app_srec.h"
#include "boot/boot.h"
/*************************************************/
void UART0_IRQHandler_Callback(void);
/*************************************************/

/*************************************************/
uint8_t 			g_rx_buff[100];
uint8_t				g_rx_length;
bool    			g_is_new_line = false;
bool				g_is_finish = false;
bool    			g_is_user_app = false;
app_queue 			queue;
SREC 				record;
static uint32_t    	s_line = 0;
uint8_t 			buff[100];
Boot_State  		boot_state = Boot_State_Idle;
uart_config	g_config = {
        .is_DMA = false,
        .is_IRQ = true,
        .baud = 38400,
        .parity = 0,
        .dataLength = 8,
        .enableRX = true,
        .enableTX = true,
        .stopBit = 1,
        .rx_call_back = UART0_IRQHandler_Callback,
        .tx_call_back = NULL,
        .error_call_back =NULL,
};
/*************************************************/
void delay_time(uint32_t time);
/*************************************************/
void UART0_IRQHandler_Callback(void)
{
    g_is_new_line = true;
    s_line++;
}
uint8_t boot_process(void)
{
    if (g_is_new_line) {
            if (!APP_QUEUE_CheckFull(&queue)) {
                APP_QUEUE_EnQueue(&queue, g_rx_buff);
            }
        g_is_new_line = false;
        g_is_new_line = false;
    }
    if(queue.level == 1){
        strcpy((char*)buff, (char*)APP_QUEUE_DeQueue(&queue));
        if(APP_CheckSrecLine(&record, buff, s_line)){
            while(1);
        }else{
            if (record.type == S1 || record.type == S2 || record.type == S3){
                APP_GetDataSrec(&record, buff);
                DRV_FLASH_Program(record.address,buff,record.data_len);
                DRV_UART_SendDataBlocking(UART0, ">", 1);
            }
            if(record.type == S9 || record.type == S8 || record.type == S7){
            	g_is_finish = true;
            }
        }
    }
    if(g_is_finish == true){
    	boot_state = Boot_State_Success;
    	DRV_UART_SendDataBlocking(UART0, "Boot Success", 12);
    	g_is_user_app = true;
    }
    return 0;
}
int main(void) {
    DRV_GPIO_LED_Init(RED_LED);
    DRV_GPIO_LED_Init(BLUE_LED);
    DRV_GPIO_LED_Control(RED_LED,ON);
    DRV_GPIO_SW_Init(SW3);
    while(1) {
        switch (boot_state){
        case Boot_State_Idle:
            if(!DRV_GPIO_SW_ReadState(SW3)){
            	delay_time(100000);
            	if(!DRV_GPIO_SW_ReadState(SW3)){
                    DRV_GPIO_LED_Control(RED_LED,OFF);
                    DRV_GPIO_LED_Control(BLUE_LED,ON);
                    boot_state = Boot_State_Init;
            	}
            }else{
            	boot_state = Boot_State_Success;
            }
        	break;
        case Boot_State_Init:
        	APP_QUEUE_Init(&queue);
            DRV_UART_Init(UART0,&g_config);
            DRV_UART_ReceivedNonBlocking(UART0,g_rx_buff,sizeof(g_rx_buff));
            boot_state = Boot_State_Process;
        	break;
        case Boot_State_Process:
            boot_process();
        	break;
        case Boot_State_Success:
            DRV_GPIO_LED_DeInit();
            DRV_GPIO_SW_DeInit();
            DRV_UART_DeInit(UART0);
            boot_jump_to_app(0xa000);
        	break;
        default:
        	break;
        }
    }
    return 0 ;
}
void delay_time(uint32_t time){
	for(uint32_t i = 0;i<time;i++){
		__asm("nop");
	}
}
