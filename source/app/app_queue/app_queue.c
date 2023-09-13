/*
 * drv_queue.c
 *
 *  Created on: Sep 2, 2023
 *      Author: hoanpx
 */
/*******************************************************/
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "app_queue.h"
/*******************************************************/
uint8_t queue1[100];
uint8_t queue2[100];
uint8_t queue3[100];
uint8_t queue4[100];
uint8_t* queue_data[4] = {queue1,queue2,queue3,queue4};
/*******************************************************/
static void APP_CopyBuff(uint8_t* des,uint8_t* src,uint8_t length);
/*******************************************************/
int8_t APP_QUEUE_Init(app_queue* queue){
    queue->front = queue->rear = -1;
    queue->size = 4;
    queue->data = queue_data;
	return 0;
}
int8_t APP_QUEUE_EnQueue(app_queue* queue,uint8_t* value){
//    if ((queue->front == 0 && queue->rear == queue->size-1) ||
//            ((queue->rear+1) % queue->size == queue->front))
    if(queue->level == queue->size)
    {
//        printf("\nQueue is Full");
        return 1;
    }
    else if (queue->front == -1) /* Insert First Element */
    {
    	queue->front = queue->rear = 0;
    	APP_CopyBuff(queue->data[queue->rear],value,100);
    	queue->level++;
    }
    else if (queue->rear == queue->size-1 && queue->front != 0)
    {
    	queue->rear = 0;
    	strcpy((char*)queue->data[queue->rear],(char*)value);
    	queue->level++;
    }
    else
    {
    	queue->rear++;
    	strcpy((char*)queue->data[queue->rear],(char*)value);
    	queue->level++;
    }
	return 0;
}
uint8_t* APP_QUEUE_DeQueue(app_queue* queue){

    if (queue->front == -1)
    {
//        printf("\nQueue is Empty");
        return 0;
    }
    uint8_t* data = queue->data[queue->front];
//    queue->data[queue->front] = NULL;
    if (queue->front == queue->rear)
    {
    	queue->front = -1;
    	queue->rear = -1;
    }
    else if (queue->front == queue->size-1)
    {
    	queue->front = 0;
    }
    else
    {
        queue->front++;
    }
    queue->level--;
    return data;
}
int8_t APP_QUEUE_CheckFull(app_queue* queue){
//    if ((queue->front == 0 && queue->rear == queue->size-1) ||
//            ((queue->rear+1) % queue->size == queue->front))
    if(queue->level == queue->size)
    {
//        printf("\nQueue is Full");
        while(1);
        return 1;
    }
    return 0;
}
static void APP_CopyBuff(uint8_t* des,uint8_t* src,uint8_t length){
    for(uint8_t i = 0;i < length;i++){
        des[i] = src[i];
    }
}
