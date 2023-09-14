/*
 * boot.c
 *
 *  Created on: Sep 14, 2023
 *      Author: hoanpx
 */
/*********************************************/
#include <stdint.h>
#include <MKE16Z4.h>
#include "boot.h"
/*********************************************/
uint8_t boot_jump_to_app(uint32_t app_address)
{
	__disable_irq();
    fnc_ptr jump_to_app;
    __set_MSP(*(volatile uint32_t*)app_address);
    SCB->VTOR = (uint32_t)(volatile uint32_t*)app_address;
    jump_to_app = (fnc_ptr)(*(volatile uint32_t*) (app_address+4u));
    __enable_irq();
    jump_to_app();
    return 0;
}
