/*
 * hal_clock.h
 *
 *  Created on: Aug 27, 2023
 *      Author: PV
 */

#ifndef HAL_HAL_CLOCK_HAL_CLOCK_H_
#define HAL_HAL_CLOCK_HAL_CLOCK_H_
/****************************************/
#define CLK_EN                  1
#define FISR_CLK_OPTION         3
#define DIV1                    1
/****************************************/
/*
 * @brief Enable the PCC clock .
 * "param PCC_type Ptr to PCC base
 * @param value   value of bits
 * @retval 0 if success
 *         1 if error
 */
int8_t HAL_CLOCK_PCC_UART_PCS_Write(uint8_t value);

/*
 * @brief Enable the PCC clock
 * "param PCC_type Ptr to PCC base
 * @param value   value of bits.
 * @retval 0 if success
 *         1 if error
 */
int8_t HAL_CLOCK_PCC_UART_CGC_Write(uint8_t value);

/*
 * @brief Enable the SCG clock
 * "param PCC_type Ptr to PCC base
 * @param value   value of bits
 * @retval 0 if success
 *         1 if error
 */
int8_t HAL_CLOCK_SCG_FIRCDIV_Write(uint8_t value);
int8_t HAL_CLOCK_PCC_PORTB_CGC_Write(uint8_t value);
#endif /* HAL_HAL_CLOCK_HAL_CLOCK_H_ */
