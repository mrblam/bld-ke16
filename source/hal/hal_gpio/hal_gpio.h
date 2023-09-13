/*
 * hal_button.h
 *
 *  Created on: Aug 26, 2023
 *      Author: hoanpx
 */

#ifndef HAL_HAL_GPIO_HAL_GPIO_H_
#define HAL_HAL_GPIO_HAL_GPIO_H_
/****************************************/
typedef enum GPIO_Mode{
    Input = 0,
    Output = 1,
    Mode_default = 0xff
}GPIO_Mode;
typedef enum GPIO_Instance{
    GPIOA_Inst = 0,
    GPIOB_Inst = 1,
    GPIOC_Inst = 2,
    GPIOD_Inst = 3,
    GPIOE_Inst = 4,
    GPIO_default = 0xff
}GPIO_Instance;
typedef enum {
    Logic_Low = 0x8U,
    Rising_Edge = 0x9U,
    Falling_Edge = 0xAU,
    Either_Edge = 0xBU,
    Logic_High = 0xCU
}Pin_Interrup;
/****************************************/
uint8_t HAL_GPIO_PDDR_Write(uint8_t instance,uint8_t pin, uint8_t mode);

/*
 * @brief Sets the output level of the multiple GPIO pins to the logic 1 or 0.
 *
 * @param base    GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * @param pin     GPIO pin number
 * @param output  GPIO pin output logic level.
 *        - 0: corresponding pin output low-logic level.
 *        - 1: corresponding pin output high-logic level.
 */
int8_t HAL_GPIO_PDOR_Write(uint8_t instance,uint8_t pin, uint8_t mode);

/*
 * @brief Reads the current input value of the GPIO port.
 *
 * @param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * @param pin     GPIO pin number
 * @retval GPIO port input value
 *        - 0: corresponding pin input low-logic level.
 *        - 1: corresponding pin input high-logic level.
 */
uint32_t HAL_GPIO_PDIR_Read(uint8_t instance,uint8_t pin, uint8_t mode);

/*
 * @brief Reverses the current output logic of the GPIO pins.
 *
 * @param base GPIO peripheral base pointer (GPIOA, GPIOB, GPIOC, and so on.)
 * @param mask GPIO pin number macro
 */
int8_t HAL_GPIO_PTOR_Toggle(uint8_t instance,uint8_t pin, uint8_t mode);
#endif /* HAL_HAL_GPIO_HAL_GPIO_H_ */
