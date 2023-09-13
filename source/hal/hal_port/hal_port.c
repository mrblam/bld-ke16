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
uint8_t HAL_PORT_PCR_MUX_Write(uint8_t instance,uint8_t pin,uint8_t value){
//    PORTB->PCR[0] = PORT_PCR_MUX(2);
//    s_portBases[1]->PCR[0] = PORT_PCR_MUX(2);
    s_portBases[instance]->PCR[pin] = PORT_PCR_MUX(value);
    return 0;
}
