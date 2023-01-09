/*
 * LED.h
 *
 * Created: 12/24/2022 11:22:12 AM
 *  Author: Wael Ayman
 */ 


#ifndef LED_H_

// including our drivers.
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/timer/timer.h"
#include "../../MCAL/Interrupt/interrupt.h"
// enums.
typedef enum LED_STATE {LED_ERROR,LED_OK} ledState_t;

// function prototypes.
ledState_t LED_init(uint8_t port_number,uint8_t pin_number); // to initialize led.
ledState_t LED_on(uint8_t port_number,uint8_t pin_number); // to turn on led.
ledState_t LEDs_off(uint8_t port_number); // to turn off led.



#endif /* LED_H_ */