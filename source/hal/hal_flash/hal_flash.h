/*
 * hal_flash.h
 *
 *  Created on: Sep 11, 2023
 *      Author: hoanpx
 */
/*************************************************/
#ifndef HAL_HAL_FLASH_HAL_FLASH_H_
#define HAL_HAL_FLASH_HAL_FLASH_H_
/*************************************************/
/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t HAL_FLASH_START_PROCESS(void);

/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t HAL_FLASH_FTFA_FCCOB0_SetCMD(uint8_t cmd);

/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t HAL_FLASH_FTFA_FCCOB1_SetCMD(uint8_t value);

/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t HAL_FLASH_FTFA_FCCOB2_SetCMD(uint8_t value);

/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t HAL_FLASH_FTFA_FCCOB3_SetCMD(uint8_t value);

/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t HAL_FLASH_FTFA_FCCOB4_SetCMD(uint8_t value);

/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t HAL_FLASH_FTFA_FCCOB5_SetCMD(uint8_t value);

/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t HAL_FLASH_FTFA_FCCOB6_SetCMD(uint8_t value);

/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t HAL_FLASH_FTFA_FCCOB7_SetCMD(uint8_t value);
#endif /* HAL_HAL_FLASH_HAL_FLASH_H_ */
