/*
 * timer.h
 *
 * Created: 12/24/2022 11:25:31 AM
 *  Author: Wael Ayman
 */ 


#ifndef TIMER_H_
#define TIMER_H_

//defining the timer's registers.
#define TCNT0 *((volatile uint8_t*) 0x52) //timer0 counter register.
#define TCCR0 *((volatile uint8_t*) 0x53)  //timer counter control register.
#define OCR0 *((volatile uint8_t*) 0x5C) // output compare register.
#define TIFR *((volatile uint8_t*) 0x58) // timer interrupt flag register.
//defining TCCR0 bits.
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

/************************************************************************/
/*                                                                      */
/************************************************************************/
typedef unsigned char uint8_t;

unsigned int *numberOfCompareMatches;

//function prototypes.
void delayms(); // to delay the required time in ms.


#endif /* TIMER_H_ */