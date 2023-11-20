/*
 * uart_communication.c
 *
 *  Created on: Nov 18, 2023
 *      Author: Admin
 */

#include "uart_communication.h"

void uart_communication_fsm(){
	char str[50];
	switch (communication_status) {
		case RECEIVE_COMMAND:
			ADC_Value= HAL_ADC_GetValue(&hadc1);
			if (command_flag==1) {
				uint8_t temp[MAX_BUFFER_SIZE]="!RST#";
				if (compare(command_data, temp)==1) {
					communication_status=SEND_ADC;
					setTimer1(1);
				}
				command_flag=0;
			}

			break;
		case SEND_ADC:
			if (command_flag==1) {
				uint8_t temp[MAX_BUFFER_SIZE]="!OK#";
				if (compare(command_data, temp)==1) {
					setTimer1(0);
					communication_status=RECEIVE_COMMAND;
				}
				command_flag=0;
			}
			if (timer1_flag==1) {

				HAL_UART_Transmit (&huart2 , (void*)str , sprintf (str , "\n%ld\n", ADC_Value), 1000);
				setTimer1(300);
			}

			break;
		default:
			break;
	}
}
