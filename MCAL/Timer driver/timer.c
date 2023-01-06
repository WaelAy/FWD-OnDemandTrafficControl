/*
 * timer.c
 *
 * Created: 12/24/2022 11:25:06 AM
 *  Author: Wael Ayman
 */ 
#include "timer.h"




void delayms(unsigned int ms){
	//setting the timer0 register  to 0.
	numberOfCompareMatches = &ms;
	TCNT0 =0;
	// CTC mode CLK/8 prescaler. 
	TCCR0 = 0x0A;
	// number of required milliseconds.
	while(*numberOfCompareMatches>0){
	//one millisecond delay.
		while((TIFR & (1<<1))==0);
		TIFR |= (1<<1); //clearing the ocr0 flag.
		(*numberOfCompareMatches)--;
	}
	TCCR0 = 0x00; // turn off timer.
	TCNT0 = 0x00; // set counter to zero.
	*numberOfCompareMatches = 0;
}

	