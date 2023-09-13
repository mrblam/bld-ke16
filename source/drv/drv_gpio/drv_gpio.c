/*
 * drv_gpio.c
 *
 *  Created on: Sep 13, 2023
 *      Author: hoanpx
 */
/******************************************/
#include <stdint.h>
#include <stddef.h>
#include "hal/hal_port/hal_port.h"
#include "hal/hal_gpio/hal_gpio.h"
#include "hal/hal_clock/hal_clock.h"
#include "drv_gpio.h"
/******************************************/
call_back portbcd_irq_callback = NULL;
/******************************************/
void PORTBCD_IRQHandler(void){
    HAL_PORT_ISFR_ClearIRQFlag(PortD_Idx,2);
    HAL_PORT_ISFR_ClearIRQFlag(PortD_Idx,3);
    portbcd_irq_callback();
}
uint8_t DRV_GPIO_LED_Init(LED_COLOR pin){
    PORT_Index port_idx;
    PORT_Instance port_inst;
    GPIO_Instance gpio_inst;
    if(pin == BLUE_LED){
        port_idx = PortD_Idx;
        port_inst = PortD;
        gpio_inst = GPIOD_Inst;
    }else{
        port_idx = PortB_Idx;
        port_inst = PortB;
        gpio_inst = GPIOB_Inst;
    }
    HAL_CLOCK_PCC_CGC_Write(port_idx,Enable);
    HAL_PORT_PCR_MUX_Write(port_inst,pin,Enable);
    HAL_GPIO_PDDR_Write(gpio_inst,pin,Output);
    HAL_GPIO_PDOR_Write(gpio_inst,pin,Disable);
    return 0;
}
uint8_t DRV_GPIO_LED_Control(LED_COLOR pin,uint8_t mode){
    GPIO_Instance gpio_inst;
    if(pin == BLUE_LED){
        gpio_inst = GPIOD_Inst;
    }else{
        gpio_inst = GPIOB_Inst;
    }
    HAL_GPIO_PDOR_Write(gpio_inst,pin,mode);
    return 0;
}
uint8_t DRV_GPIO_SW_Init(BUTTON pin){
    PORT_Index port_idx = PortD_Idx;
    PORT_Instance port_inst = PortD;
    GPIO_Instance gpio_inst = GPIOD_Inst;
    HAL_CLOCK_PCC_CGC_Write(port_idx,Enable);
    HAL_PORT_PCR_MUX_Write(port_inst,pin,Gpio);
    HAL_PORT_PCR_IRQC_Write(port_inst,pin,Falling_Edge);
    HAL_GPIO_PDDR_Write(gpio_inst,pin,Input);
    return 0;
}
uint8_t DRV_GPIO_SW_ReadState(BUTTON pin){
    GPIO_Instance gpio_inst = GPIOD_Inst;
    return HAL_GPIO_PDIR_Read(gpio_inst,pin);
}
uint8_t DRV_GPIO_register_interrup(call_back func_cb){
    portbcd_irq_callback = func_cb;
    return 0;
}
