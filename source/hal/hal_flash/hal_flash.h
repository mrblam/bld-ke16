/*
 * hal_flash.h
 *
 *  Created on: Sep 11, 2023
 *      Author: hoanpx
 */

#ifndef HAL_HAL_FLASH_HAL_FLASH_H_
#define HAL_HAL_FLASH_HAL_FLASH_H_
/*************************************************/
typedef enum CMD_Code{
    Read_1s_Section = 0x01,
    Program_Check = 0x02,
    Read_Resource = 0x03,
    Program_Longword = 0x06,
    Erase_Flash_Sector = 0x09,
    Read_1s_All_Blocks = 0x40,
    Read_Once = 0x41,
    Program_Once = 0x43,
    Erase_All_Blocks = 0x44,
    Verify_Backdoor_Access_Key = 0x45,
    Erase_All_Blocks_Unsecure = 0x49,
    undef = 0xFF
}CMD_Code;
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
uint8_t HAL_FLASH_FTFA_FCCOB0_SetCMD(CMD_Code cmd);

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
