/*
 * boot.h
 *
 *  Created on: Sep 14, 2023
 *      Author: hoanpx
 */
/*********************************************/
#ifndef BOOT_BOOT_H_
#define BOOT_BOOT_H_
/*********************************************/
typedef enum{
	Boot_State_Idle = 0,
	Boot_State_Init = 1,
	Boot_State_Process = 2,
	Boot_State_Success = 3,
	Boot_State_default = 0xff
}Boot_State;
typedef void (*fnc_ptr)(void);
/*********************************************/
/*
 * @brief jump to application user
 * @param address
 * @retval 0 if success
 */
uint8_t boot_jump_to_app(uint32_t app_address);
/*********************************************/
#endif /* BOOT_BOOT_H_ */
