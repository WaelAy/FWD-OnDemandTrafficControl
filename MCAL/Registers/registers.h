/*
 * registers.h
 *
 * Created: 12/24/2022 11:18:13 AM
 *  Author: Wael Ayman
 */ 
/************************************************************************/
/* Defining the registers ,bits and typedefs we are using in this project.*/
/************************************************************************/

#ifndef REGISTERS_H_
#define REGISTERS_H_

//type defs..
typedef unsigned int uint8_t;


/************************************************************************/
/*                  registers section                                   */
/************************************************************************/

// status register.
#define SREG *((volatile uint8_t*) 0x5F)

/*##############################################################*/
// Defining port A registers.
#define PORTA *((volatile uint8_t*) 0x3B)  // 8 bit register.
#define DDRA *((volatile uint8_t*) 0x3A)   // 8 bit register.
#define PINA *((volatile uint8_t*) 0x39)	  // 8 bit register.
/*##############################################################*/
// Defining port B registers.
#define PORTB *((volatile uint8_t*) 0x38)   // 8 bit register.
#define DDRB *((volatile uint8_t*) 0x37)   // 8 bit register.
#define PINB *((volatile uint8_t*) 0x36)   // 8 bit register.
/*##############################################################*/
// Defining port D registers.
#define PORTD *((volatile uint8_t*) 0x32)  // 8 bit register.
#define DDRD *((volatile uint8_t*) 0x31)   // 8 bit register.
#define PIND *((volatile uint8_t*) 0x30)   // 8 bit register.
/************************************************************************/
/* TIMER'S SECTION IN THIS PROJECT WILL USE TIMER0.                     */
/************************************************************************/
/*##############################################################*/
// defining timer0 registers.
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
/*###########################################################################*/
// defining registers to enable interrupts.
#define MCUCR *((volatile uint8_t*) 0x55) // The MCU Control Register contains control bits for interrupt sense control and general MCU functions.
#define GICR *((volatile uint8_t*) 0x5B) // general interrupt control register.
#define GIFR *((volatile uint8_t*) 0x5A) // general interrupt flag register.

#endif /* REGISTERS_H_ */