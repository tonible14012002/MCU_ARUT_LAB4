/*
 * software_timer.h
 *
 *  Created on: Nov 22, 2023
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

int timer0_flag;
int timer1_flag;

void setTimer0(int duration);
void setTimer1(int duration);

void timer_run();


#endif /* INC_SOFTWARE_TIMER_H_ */
