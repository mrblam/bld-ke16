/*
 * drv_systick.h
 *
 *  Created on: Aug 26, 2023
 *      Author: PV
 */
#ifndef DRIVER_DRV_CORE_DRV_SYSTICK_DRV_SYSTICK_H_
#define DRIVER_DRV_CORE_DRV_SYSTICK_DRV_SYSTICK_H_
/*************************************************/
typedef void (*call_back)(void);
/*************************************************/
/*
 * @brief
 * @param
 * @param
 * @retval
 */
int8_t DRV_Systick_Register_Callback(call_back func_ptr);

/*
 * @brief
 * @param
 * @param
 * @retval
 */
int8_t DRV_Init_SysTick(uint32_t freq);
#endif /* DRIVER_DRV_CORE_DRV_SYSTICK_DRV_SYSTICK_H_ */
