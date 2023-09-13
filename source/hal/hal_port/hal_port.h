/*
 * hal_port.h
 *
 *  Created on: Sep 10, 2023
 *      Author: hoanpx
 */

#ifndef HAL_HAL_PORT_HAL_PORT_H_
#define HAL_HAL_PORT_HAL_PORT_H_
/*************************************************/
#define PIN0            0
#define PIN1            1
#define ALT2            2
/*************************************************/
uint8_t HAL_PORT_PCR_MUX_Write(uint8_t instance,uint8_t pin,uint8_t value);
/*************************************************/
#endif /* HAL_HAL_PORT_HAL_PORT_H_ */
