/*
 * DIO.h
 *
 * Created: 12/24/2022 11:23:57 AM
 *  Author: Wael Ayman
 */ 


#ifndef DIO_H_
#define DIO_H_
// defining the used registers.
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
/*                                                                      */
/************************************************************************/
//defining pin direction.
#define INPUT 0
#define OUTPUT 1
/********************************************/
#define HIGH 1
#define LOW 0
/********************************************/
# define PortA 'A'
# define PortB 'B'
# define PortC 'C'
# define PortD 'D'
/********************************************/
typedef unsigned char uint8_t;
typedef enum DIO {DIO_OK,DIO_ERROR} dio_state;
/* defining our functions prototypes. */

dio_state dio_init(uint8_t portNum,uint8_t pinNum, uint8_t direction); // function to initialize DIO pin.
dio_state dio_write(uint8_t portNum,uint8_t pinNum,uint8_t value); // function to set the pin's value.
dio_state dio_read(uint8_t portNum,uint8_t pinNum, uint8_t *value); // function to read the pin's value.



#endif /* DIO_H_ */