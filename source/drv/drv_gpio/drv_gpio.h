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
    BLUE_LED    = BLUE_LED_PIN,
    GREEN_LED   = GREEN_LED_PIN,
    RED_LED     = RED_LED_PIN
} LED_COLOR;
typedef enum BUTTON {
    SW2 = SW2_PIN,
    SW3 = SW3_PIN
} BUTTON;
typedef enum SW_STATE {
    SW_ON,
    SW_OFF
} SW_STATE;
typedef struct LED_t LED;
struct LED_t{
    LED_COLOR color;
    uint8_t   value;
};
/******************************************/
#endif /* DRV_DRV_GPIO_DRV_GPIO_H_ */
