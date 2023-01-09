/*
 * DIO.c
 *
 * Created: 12/24/2022 11:24:28 AM
 *  Author: Wael Ayman
 */ 
#include "DIO.h"

//functions bodies.

// function to initialize DIO pin.
dio_state dio_init(uint8_t portNum,uint8_t pinNum, uint8_t direction) 
{

	if (pinNum > 7 || pinNum < 0)
		return DIO_ERROR;

	if (direction < 0 || direction>2)
		return DIO_ERROR;

// if pin direction was input we clear pin.
// if it was output we set bit to one.
	switch (portNum){
		case PortA:
			if (direction == INPUT)
				DDRA &= ~(1<<pinNum);

			else if (direction == OUTPUT)
				DDRA |= (1<<pinNum);	
			break;

		case PortB:
			if(direction == INPUT)
				DDRB &= ~(1<<pinNum);

			else if (direction == OUTPUT)
				DDRB |= (1<<pinNum);
				
			break;

		case PortD:
			if(direction == INPUT)
				DDRD &= ~(1<<pinNum);

			else if (direction == OUTPUT)
				DDRD |= (1<<pinNum);
				
			break;

		default:
			return DIO_ERROR;
			break;
			
	}
	return DIO_OK;
}

// function to set the pin's value.
dio_state dio_write(uint8_t portNum,uint8_t pinNum,uint8_t value) 
{
	if (pinNum > 7 || pinNum < 0)
		return DIO_ERROR;

	if (value < 0 || value>2)
		return DIO_ERROR;

		switch (portNum){
			case PortA:
				if (value == LOW)
					PORTA &= ~(1<<pinNum);
					
				else if(value==HIGH)
					PORTA |= (1<<pinNum); 
					
				break;	
				
			case PortB:
				if (value == LOW)
					PORTB &= ~(1<<pinNum);
					
				else if(value==HIGH)
					PORTB |= (1<<pinNum);
					
				break;

			case PortD:
				if (value == LOW)
					PORTD &= ~(1<<pinNum);
					
				else if(value==HIGH)
					PORTD |= (1<<pinNum);
				
				break;
				
			default:
			 return DIO_ERROR;
				break;	
		}
		return DIO_OK;
}

// function to read the pin's value.
dio_state dio_read(uint8_t portNum,uint8_t pinNum,uint8_t *value) 
{
	if (pinNum > 7 || pinNum < 0)
		return DIO_ERROR;

	if (*value < 0 || *value>2)
		return DIO_ERROR;

	switch(portNum){
		case PortA:
			*value = (PINA &(1<<pinNum))>>pinNum;
			return DIO_OK;
		case PortB:
			*value = (PINB &(1<<pinNum))>>pinNum;
			return DIO_OK;
		case PortD:
			*value = (PIND &(1<<pinNum))>>pinNum;
			return DIO_OK;
		default:
			return DIO_ERROR;
			break;			
		
	}
	return DIO_ERROR;
	
}
