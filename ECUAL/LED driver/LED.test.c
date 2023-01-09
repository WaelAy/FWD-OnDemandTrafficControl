/*
 * LED.c
 *
 * Created: 1/9/2023 6:44:10 PM
 *  Author: Wael Ayman
 */ 
#include "LED.h"


void led_initTest() {

	LED_init(PortA,5);
	
}
void LED_onTest() {
 LED_on(PortA,5);

}

void LEDs_offTEST(){
	LEDs_off(PortA);
}