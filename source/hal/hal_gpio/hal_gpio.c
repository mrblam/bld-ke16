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
#define GPIO_FIT_REG(value) ((uint32_t)(value))
/****************************************/
static GPIO_Type *const s_gpioBases[] = GPIO_BASE_PTRS;
/****************************************/
uint8_t HAL_GPIO_PDDR_Write(uint8_t instance, uint8_t pin, uint8_t mode)
{
    s_gpioBases[instance]->PDDR |= GPIO_PDDR_PDD(mode << pin);
    return 1;
}
int8_t HAL_GPIO_PDOR_Write(uint8_t instance, uint8_t pin, uint8_t mode)
{
    if (mode == 0U) {
        s_gpioBases[instance]->PDOR |= (uint32_t) (1UL << pin);
    } else {
        s_gpioBases[instance]->PDOR &= ~((uint32_t) (1UL << pin));
    }
    return 1;
}
uint32_t HAL_GPIO_PDIR_Read(uint8_t instance, uint8_t pin)
{
    return (((uint32_t) (s_gpioBases[instance]->PDIR) >> pin) & 0x01UL);
}
