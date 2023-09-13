/*
 * hal_port.c
 *
 *  Created on: Sep 10, 2023
 *      Author: hoanpx
 */
/*************************************************/
#include <stdint.h>
#include <MKE16Z4.h>
#include "hal_port.h"
/*************************************************/
static PORT_Type *const s_portBases[] = PORT_BASE_PTRS;
/*************************************************/
uint8_t HAL_PORT_PCR_MUX_Write(uint8_t instance,uint8_t pin,Mux_Control value){
    s_portBases[instance]->PCR[pin] |= PORT_PCR_MUX(value);
    return 0;
}
uint8_t HAL_PORT_PCR_IRQC_Write(uint8_t instance,uint8_t pin,uint8_t interrup_mode){
    s_portBases[instance]->PCR[pin] |= PORT_PCR_IRQC(interrup_mode);
    return 0;
}
uint8_t HAL_PORT_ISFR_ClearIRQFlag(uint8_t instance,uint8_t pin){
    s_portBases[instance]->ISFR |= PORT_ISFR_ISF((1 << pin));
    return 0;
}
