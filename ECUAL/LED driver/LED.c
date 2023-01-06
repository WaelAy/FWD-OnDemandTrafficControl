/*
 * LED.c
 *
 * Created: 12/24/2022 11:22:28 AM
 *  Author: Wael Ayman
 */ 
#include "LED.h"

//function bodies.

//To initialize LED pin port to output.
void LED_init(uint8_t port_number,uint8_t pin_number){
	dio_init(port_number,pin_number,OUTPUT);
}

// To turn on LED.
void LED_on(uint8_t port_number,uint8_t pin_number){
	dio_write(port_number,pin_number,HIGH);
}

// Turns off all LEDs on a port.
void LEDs_off(uint8_t port_number){
	
	for (int i = 0; i<3;i++)
		dio_write(port_number,i,LOW);
	
}



