/*
 * app.c
 *
 * Created: 1/9/2023 6:12:18 PM
 *  Author: Wael Ayman
 */ 
#include "app.h"
void turnOffRequiredLEDsTest(){
	//if function returns ok led 5 port c will be on.
	if(turnOffRequiredLEDs()==0)
		LED_on(PortC,5);
	else
		return;	
}

void turnOnRequiredLEDsTest(){
	if (turnOnRequiredLEDs(5,1)==0)
	{
		LED_on(PortC,5);
	}
	else
		return;
}
void getCarLEDTest(uint8_t iteration){
		if (getCarLED(1)==1)
		{
			LED_on(PortC,5);
		}
		else
		return;
	} 
	
void getPedestrianLEDTest(uint8_t iteration){
			if (getPedestrianLED(1)==0)
			{
				LED_on(PortC,5);
			}
			else
			return;
		
}
void APP_initTest(){
	if(APP_init()==0){
		LED_on(PortC,5);
	}
	else
		return;
}
void APP_startTest(){
		if(APP_start()==0){
			LED_on(PortC,5);
		}
		else
		return;
	} 
void pedestrianModeTest(){
	uint8_t iteration = 0;
	uint8_t curr_led = 2;	
			if(pedestrianMode(2,&iteration,&curr_led)==0){
				LED_on(PortC,5);
			}
			else
			return;
	} 
