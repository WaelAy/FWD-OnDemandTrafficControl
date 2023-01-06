/*
 * LED.h
 *
 * Created: 12/24/2022 11:22:12 AM
 *  Author: Wael Ayman
 */ 


#ifndef LED_H_

// including our drivers.
#include "../../MCAL/GPIO driver/DIO.h"
#include "../../MCAL/Timer driver/timer.h"
#include "../../MCAL/Interrupt driver/interrupt.h"

// function prototypes.
void LED_init(uint8_t port_number,uint8_t pin_number); // to initialize led.
void LED_on(uint8_t port_number,uint8_t pin_number); // to turn on led.
void LEDs_off(uint8_t port_number); // to turn off led.



#endif /* LED_H_ */