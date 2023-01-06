/*
 * interrupt.c
 *
 * Created: 12/31/2022 9:36:28 PM
 *  Author: Wael Ayman
 */ 
#include "interrupt.h"
#include "../../ECUAL/LED driver/LED.h"
void init_interrupts(){
	__asm("sei"); // to set interrupt bin in SREG To 1 aka to enable interrupts.
	GICR |= (1<<6); // Enabling interrupt zero.
	MCUCR = 0x02;//setting interrupt sense in int0 as rising edge.
	
}
uint8_t pedestrian_mode;
ISR(EXT_INT_0){
pedestrian_mode = 1;
}