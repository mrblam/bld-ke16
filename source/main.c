/*
 * drv_uart.c
 *
 *  Created on: Sep 10, 2023
 *      Author: hoanpx
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "MKE16Z4.h"
#include "drv/drv_uart/drv_uart.h"
#include "drv/drv_flash/drv_flash.h"
#include "app/app_queue/app_queue.h"
#include "app/app_srec/app_srec.h"
#include "drv/drv_gpio/drv_gpio.h"
/*************************************************/
void UART0_IRQHandler_Callback(void);
/*************************************************/
uint8_t g_rx_buff[100];
uint8_t g_rx_length;
bool    g_is_new_line = false;
app_queue queue;
SREC record;
static uint32_t    s_line = 0;
uint8_t buff[100] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
uart_config     g_config = {
        .is_DMA = false,
        .is_IRQ = true,
        .baud = 115200,
        .parity = 0,
        .dataLength = 8,
        .enableRX = true,
        .enableTX = true,
        .stopBit = 1,
        .rx_call_back = UART0_IRQHandler_Callback,
        .tx_call_back = NULL,
        .error_call_back =NULL,
};

typedef void (*fnc_ptr)(void);
/*************************************************/
void BUTTON_IRQHandler_Callback(void){

}
void UART0_IRQHandler_Callback(void){
    g_is_new_line = true;
    s_line++;
}
uint8_t jump_to_app(uint32_t app_address){
    /* Function pointer to the address of the user application. */
    fnc_ptr jump_to_app;
    jump_to_app = (fnc_ptr)(*(volatile uint32_t*) (app_address+4u));
    /* Change the main stack pointer. */
    __set_MSP(*(volatile uint32_t*)app_address);
    jump_to_app();
    return 0;
}
uint8_t boot_process(void)
{
    if (g_is_new_line) {
            if (!APP_QUEUE_CheckFull(&queue)) {
                APP_QUEUE_EnQueue(&queue, g_rx_buff);
            }
        g_is_new_line = false;
    }
    if(queue.level == 1){
        strcpy((char*)buff, (char*)APP_QUEUE_DeQueue(&queue));
        if(APP_CheckSrecLine(&record, buff, s_line)){
            while(1);
        }else{
            if (record.type == S1 || record.type == S2 || record.type == S3){
                APP_GetDataSrec(&record, buff);
                __disable_irq();
                DRV_FLASH_Program(record.address,buff,record.data_len);
                __enable_irq();
            }
        }
    }
    return 0;
}
int main(void) {
    g_rx_length = sizeof(g_rx_buff);
    APP_QUEUE_Init(&queue);
    DRV_GPIO_LED_Init(RED_LED);
    DRV_GPIO_LED_Init(GREEN_LED);
    DRV_GPIO_LED_Init(BLUE_LED);
    DRV_GPIO_SW_Init(SW3);
    DRV_UART_Init(UART0,&g_config);
    DRV_UART_ReceivedNonBlocking(UART0,g_rx_buff,g_rx_length);
    while(1) {
        if(1){
            boot_process();
        }else{
            jump_to_app(0x00A000);
        }
    }
    return 0 ;
}
