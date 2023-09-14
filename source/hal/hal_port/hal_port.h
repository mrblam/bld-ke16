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
typedef enum {
    PortA = 0,
    PortB = 1,
    PortC = 2,
    PortD = 3,
    PortE = 4,
    Inst_default = 0xff
}PORT_Instance;
typedef enum Port_Index{
    PortA_Idx = 73,
    PortB_Idx = 74,
    PortC_Idx = 75,
    PortD_Idx = 76,
    PortE_Idx = 77,
    Idx_default = 0xff
}PORT_Index;
typedef enum Bit_State {
    Enable = 1,
    Disable = 0,
    State_default = 0xff
}Bit_State;
typedef enum {
    Gpio = 1,
    Lpuart = 2,
    Mux_default = 0xff
}Mux_Control;
/*************************************************/
/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t HAL_PORT_PCR_MUX_Write(uint8_t instance,uint8_t pin,Mux_Control value);

/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t HAL_PORT_PCR_IRQC_Write(uint8_t instance,uint8_t pin,uint8_t value);

/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t HAL_PORT_ISFR_ClearIRQFlag(uint8_t instance,uint8_t pin);
/*************************************************/
#endif /* HAL_HAL_PORT_HAL_PORT_H_ */
