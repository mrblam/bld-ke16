/*
 * drv_flash.h
 *
 *  Created on: Sep 11, 2023
 *      Author: hoanpx
 */
/*************************************************/
#ifndef DRV_DRV_FLASH_DRV_FLASH_H_
#define DRV_DRV_FLASH_DRV_FLASH_H_
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
}FLASH_CMD_Code;
/*************************************************/
uint8_t DRV_FLASH_Program(uint32_t address,uint8_t* data,uint32_t length);
uint8_t DRV_FLASH_VerifyProgram(uint32_t address,uint8_t* data,uint32_t length);
uint8_t DRV_FLASH_Erase(uint32_t address,FLASH_CMD_Code mode);
uint8_t DRV_FLASH_VerifyErase(uint32_t address,FLASH_CMD_Code mode);
#endif /* DRV_DRV_FLASH_DRV_FLASH_H_ */
