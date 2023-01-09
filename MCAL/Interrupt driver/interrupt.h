/*
 * interrupt.h
 *
 * Created: 12/31/2022 9:36:13 PM
 *  Author: Wael Ayman
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

//defining the used registers in the interrupt module.
// defining registers to enable interrupts.
#define MCUCR *((volatile uint8_t*) 0x55) // The MCU Control Register contains control bits for interrupt sense control and general MCU functions.
#define GICR *((volatile uint8_t*) 0x5B) // general interrupt control register.
#define GIFR *((volatile uint8_t*) 0x5A) // general interrupt flag register.


//defining interrupt vector for pedestrian mode.
#define EXT_INT_0 __vector_1
//defining interrupt service routine.
#define ISR(INT_VECT)void INT_VECT(void) __attribute__((signal,used)) ;\
void INT_VECT(void)
//-----------------------------------------------------------------------
//defining pedestrian modes;
#define ON 1
#define Off 0
//-----------------------------------------------------------------------
//type defs.
typedef unsigned char uint8_t;
typedef enum INTERRUPT_State {intterupt_ok,interrupt_error} interruptState_t;


extern uint8_t pedestrian_mode;


interruptState_t init_interrupts(); //function to initialize interrupts.



#endif /* INTERRUPT_H_ */