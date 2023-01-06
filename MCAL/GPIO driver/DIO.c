/*
 * DIO.c
 *
 * Created: 12/24/2022 11:24:28 AM
 *  Author: Wael Ayman
 */ 
#include "DIO.h"

//functions bodies.
void dio_init(uint8_t portNum,uint8_t pinNum, uint8_t direction) // function to initialize DIO pin.
{
	// if pin direction was input we clear pin.
	// if it was output we set bit to one.
	switch (portNum){
		case PortA:
			if (direction == INPUT)
				DDRA &= ~(1<<pinNum);
			else	
				DDRA |= (1<<pinNum);
			break;
		case PortB:
			if(direction == INPUT)
				DDRB &= ~(1<<pinNum);
			else	
				DDRB |= (1<<pinNum);
				
				break;
		case PortD:
			if(direction == INPUT)
				DDRD &= ~(1<<pinNum);
			else 
				DDRD |= (1<<pinNum);
			break;
		default:
			break;		
	}
	
};
void dio_write(uint8_t portNum,uint8_t pinNum,uint8_t value) // function to set the pin's value.
{
		switch (portNum){
			case PortA:
				if (value == LOW)
					PORTA &= ~(1<<pinNum);
				else if(value==HIGH)
					PORTA |= (1<<pinNum);
				else;	
				break;
			case PortB:
				if (value == LOW)
					PORTB &= ~(1<<pinNum);
				else if(value==HIGH)
					PORTB |= (1<<pinNum);
				else ;	
				break;
			case PortD:
				if (value == LOW)
					PORTD &= ~(1<<pinNum);
				else if(value==HIGH)
					PORTD |= (1<<pinNum);
				else;	
				break;	
			default:
				break;	
		}
}
void dio_read(uint8_t portNum,uint8_t pinNum,uint8_t *value) // function to read the pin's value.
{
	
	switch(portNum){
		case PortA:
			*value = (PINA &(1<<pinNum))>>pinNum;
				break;
		case PortB:
			*value = (PINB &(1<<pinNum))>>pinNum;
				break;	
		case PortD:
			*value = (PIND &(1<<pinNum))>>pinNum;
				break;	
		default:
			break;			
		
	}
}
