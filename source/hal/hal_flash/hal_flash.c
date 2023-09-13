/*
 * hal_flash.c
 *
 *  Created on: Sep 11, 2023
 *      Author: hoanpx
 */
/*************************************************/
#include <MKE16Z4.h>
#include <stdint.h>
#include "hal_flash.h"
/*************************************************/
uint8_t HAL_FLASH_START_PROCESS(void){
    FTFA->FSTAT  = 0x80;
    while(!((FTFA->FSTAT)  & 0x80));
    return 0;
}
uint8_t HAL_FLASH_FTFA_FCCOB0_SetCMD(CMD_Code cmd){
    FTFA->FCCOB0 = cmd;
    return 0;
}
uint8_t HAL_FLASH_FTFA_FCCOB1_SetCMD(uint8_t value){
    FTFA->FCCOB1 = value;
    return 0;
}
uint8_t HAL_FLASH_FTFA_FCCOB2_SetCMD(uint8_t value){
    FTFA->FCCOB2 = value;
    return 0;
}
uint8_t HAL_FLASH_FTFA_FCCOB3_SetCMD(uint8_t value){
    FTFA->FCCOB3 = value;
    return 0;
}
uint8_t HAL_FLASH_FTFA_FCCOB4_SetCMD(uint8_t value){
    FTFA->FCCOB4 = value;
    return 0;
}
uint8_t HAL_FLASH_FTFA_FCCOB5_SetCMD(uint8_t value){
    FTFA->FCCOB5 = value;
    return 0;
}
uint8_t HAL_FLASH_FTFA_FCCOB6_SetCMD(uint8_t value){
    FTFA->FCCOB6 = value;
    return 0;
}
uint8_t HAL_FLASH_FTFA_FCCOB7_SetCMD(uint8_t value){
    FTFA->FCCOB7 = value;
    return 0;
}
