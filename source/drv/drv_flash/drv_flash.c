/*
 * drv_flash.c
 *
 *  Created on: Sep 11, 2023
 *      Author: hoanpx
 */
/*************************************************/
#include <stdint.h>
#include "hal/hal_flash/hal_flash.h"
#include "drv_flash.h"
/*************************************************/
uint8_t DRV_FLASH_SetCMD(FLASH_CMD_Code cmd){
    HAL_FLASH_FTFA_FCCOB0_SetCMD(cmd);
    return 0;
}
uint8_t DRV_FLASH_SetAddress(uint32_t address){
    HAL_FLASH_FTFA_FCCOB1_SetCMD(0x00U);
    HAL_FLASH_FTFA_FCCOB2_SetCMD((uint8_t)(address >> 8));
    HAL_FLASH_FTFA_FCCOB3_SetCMD((uint8_t)address);
    return 0;
}
uint8_t DRV_FLASH_PrepareDATA(uint8_t* data){
    HAL_FLASH_FTFA_FCCOB7_SetCMD(*data);
    data++;
    HAL_FLASH_FTFA_FCCOB6_SetCMD(*data);
    data++;
    HAL_FLASH_FTFA_FCCOB5_SetCMD(*data);
    data++;
    HAL_FLASH_FTFA_FCCOB4_SetCMD(*data);
    data++;
    return 0;
}
uint8_t DRV_FLASH_Program(uint32_t address,uint8_t* data,uint32_t length){
    uint32_t remainingLength;
    remainingLength = length;
    if(address <= 0xFFFF){
        while (remainingLength > 0U){
            DRV_FLASH_SetCMD(Program_Longword);
            DRV_FLASH_SetAddress(address);
            DRV_FLASH_PrepareDATA(data);
            HAL_FLASH_START_PROCESS();
            data += 4U;
            address += 4U;
            remainingLength -= 4U;
        }
    }else{
        return 1;
    }
    return 0;
}
uint8_t DRV_FLASH_VerifyProgram(uint32_t address,uint8_t* data,uint32_t length){

    return 0;
}
uint8_t DRV_FLASH_EraseSector(uint32_t address){
	HAL_FLASH_FTFA_FCCOB0_SetCMD(Erase_Flash_Sector);
    DRV_FLASH_SetAddress(address);
    HAL_FLASH_START_PROCESS();
    return 0;
}
uint8_t DRV_FLASH_EraseMultiSector(uint32_t address,uint8_t num){
	uint8_t i;
	for(i = 0;i < num;i++){
		DRV_FLASH_EraseSector(address + (uint32_t)(i*1024));
	}
    return 0;
}
uint8_t DRV_FLASH_EraseAllBlocks(void){
	HAL_FLASH_FTFA_FCCOB0_SetCMD(Erase_All_Blocks_Unsecure);
    HAL_FLASH_START_PROCESS();
	return 0;
}
uint8_t DRV_FLASH_VerifyEraseSector(uint32_t address){
	HAL_FLASH_FTFA_FCCOB0_SetCMD(Read_1s_Section);
    DRV_FLASH_SetAddress(address);
//    DRV_FLASH_PrepareDATA(data);
    HAL_FLASH_START_PROCESS();
    return 0;
}
uint8_t DRV_FLASH_VerifyEraseAllBlocks(void){
	HAL_FLASH_FTFA_FCCOB0_SetCMD(Read_1s_All_Blocks);
    HAL_FLASH_START_PROCESS();
    return 0;
}
