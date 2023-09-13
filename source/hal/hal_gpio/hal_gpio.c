/*
 * hal_gpio.c
 *
 *  Created on: Sep 13, 2023
 *      Author: hoanpx
 */
/****************************************/
#include <stdint.h>
#include <MKE16Z4.h>
#include "hal_gpio.h"
/****************************************/
static GPIO_Type *const s_gpioBases[] = GPIO_BASE_PTRS;
/****************************************/
uint8_t HAL_GPIO_PDDR_Write(uint8_t instance,uint8_t pin, uint8_t mode){
    s_gpioBases[instance]->PDDR = GPIO_PDDR_PDD(mode << pin);
    return 1;
}
