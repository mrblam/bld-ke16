/*
 * handle_srec.h
 *
 *  Created on: Jul 17, 2023
 *      Author: hoanpx
 */

#ifndef HANDLE_SREC_HANDLE_SREC_H_
#define HANDLE_SREC_HANDLE_SREC_H_
/*************************/
#define MIN_RECORD_SIZE 4
#define ROW_SIZE    16
/*************************/
typedef enum {
    S0 = 0,
    S1 = 1,
    S2 = 2,
    S3 = 3,
    S4 = 4,
    S5 = 5,
    S6 = 6,
    S7 = 7,
    S8 = 8,
    S9 = 9,
	srec_type_default = 0xff
} srec_type;
typedef struct line_type_t {
	uint32_t 	line_s1;
	uint32_t 	line_s2;
	uint32_t 	line_s3;
	uint32_t 	s_line_of_s1s2s3;
	uint8_t		line_s4;
	uint8_t 	line_s0;
	uint8_t 	line_s5;
	uint8_t 	line_s6;
	uint8_t 	line_s7;
	uint8_t 	line_s8;
	uint8_t 	line_s9;
}line_type;
typedef struct SREC_t {
    uint8_t		header;
    srec_type 	type;
    uint8_t 	byte_count;
    uint8_t 	data_len;
    uint8_t 	data_offset;
    uint32_t 	address;
    uint8_t 	data[32];
    uint8_t 	check_sum;
    line_type	line_num;
    uint32_t    main_add;
}SREC;
/*******Declare**********/
/*
 * @brief  	Convert line to SREC format
 * @param	record: line SREC type
 * @param	arr: arr contain one line of file SREC
 * @param	line: line of file present
 * @retval	1: ERROR
 * 			0: NOT_ERR
 */
uint8_t APP_CheckSrecLine(SREC *record, uint8_t *arr, uint32_t line);

/* Write data to file
 *
 * @param file: pointer point to file
 *        record: pointer to SREC type
 * @retval 0
 * */
uint8_t APP_GetDataSrec(SREC *record,uint8_t* buff);
/*
 *
 * @param
 *
 *
 * @retval 1: ERROR
 *         0: NOT ERROR
 */
#endif /* HANDLE_SREC_HANDLE_SREC_H_ */

