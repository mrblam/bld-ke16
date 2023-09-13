/*
 * drv_queue.h
 *
 *  Created on: Sep 2, 2023
 *      Author: hoanpx
 */

#ifndef DRIVER_DRV_QUEUE_DRV_QUEUE_H_
#define DRIVER_DRV_QUEUE_DRV_QUEUE_H_
/*******************************************************/
typedef struct app_queue {
	int8_t front;
	int8_t rear;
	uint8_t size;
	uint8_t** data;
	uint8_t level;
}app_queue;
/*******************************************************/
int8_t APP_QUEUE_Init(app_queue* queue);
int8_t APP_QUEUE_CheckFull(app_queue* queue);
int8_t APP_QUEUE_EnQueue(app_queue* queue,uint8_t* value);
uint8_t* APP_QUEUE_DeQueue(app_queue* queue);
#endif /* DRIVER_DRV_QUEUE_DRV_QUEUE_H_ */
