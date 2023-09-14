/*
 * drv_gpio.h
 *
 *  Created on: Sep 13, 2023
 *      Author: hoanpx
 */

#ifndef DRV_DRV_GPIO_DRV_GPIO_H_
#define DRV_DRV_GPIO_DRV_GPIO_H_
/******************************************/
typedef enum LED_COLOR {
    BLUE_LED    = 1,
    GREEN_LED   = 4,
    RED_LED     = 5,
	LED_default = 0xff
} LED_COLOR;
typedef enum BUTTON {
    SW2 = 3,
    SW3 = 2,
	SW_default = 0xff
} BUTTON;
typedef enum SW_STATE {
    ON = 1,
    OFF = 0,
	BLINK = 2,
	SW_State_default = 0xff
} SW_STATE;
typedef void (*call_back)(void);
/******************************************/
/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t DRV_GPIO_LED_Init(LED_COLOR pin);

/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t DRV_GPIO_LED_DeInit();

/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t DRV_GPIO_LED_Control(LED_COLOR pin,uint8_t mode);

/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t DRV_GPIO_SW_Init(BUTTON pin);

/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t DRV_GPIO_SW_DeInit(void);
/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t DRV_GPIO_SW_ReadState(BUTTON pin);

/*
 * @brief
 * @param
 * @param
 * @retval
 */
uint8_t DRV_GPIO_register_interrup(call_back func_cb);
#endif /* DRV_DRV_GPIO_DRV_GPIO_H_ */
