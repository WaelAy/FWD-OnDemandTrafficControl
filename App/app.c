/*
 * app.c
 *
 * Created: 1/2/2023 7:11:57 PM
 *  Author: Wael Ayman
 */ 
#include "app.h"



// function to initialize our interrupts and LEDs.
void APP_init(){
		//initializing the interrupts.
		init_interrupts();
		//initializing the used LEDs.
		for (int i = 0; i<3; i++)
		{
			//PortA LEDs.
			LED_init(PortA,i);
			//PortB LEDs.
			LED_init(PortB,i);
		}
		

		
}

// main logic of our project.
void APP_start(){
	
	//flag for the pedestrian mode.
	uint8_t pedestrian_flag = Off;
	pedestrian_mode = Off;
	
	// loop to iterate over the LEDs.
	for (uint8_t  iteration = 0; iteration<4; iteration++)
	{
		// variables to store the LEDs to be toggled.
		uint8_t currled = getCarLED(iteration);
		uint8_t ped_led = getPedestrianLED(iteration);
		
		/************************************************************************/
		/* if the next LED isn't the yellow one we will set this LED to On for 5 secs.  */
		/************************************************************************/
		if(currled!=Yellow){
			// Turning on the needed LEDs.
			turnOnRequiredLEDs(currled,ped_led);
			/************************************************************************/
			/*Loop in which we will check if the pedestrian clicked the button each 100ms for 5s */
			/************************************************************************/
			for(uint8_t j = 0; j<50; j++){
				
				//checking if the user triggered the PED mode each 100ms.
				if(pedestrian_mode==ON&&pedestrian_flag==Off){
					pedestrianMode(currled,&iteration,&pedestrian_flag);
					
					if(currled==0||currled==1)
							break;
						
				}
				//delaying 100ms * 50 = 5s.
				delayms(100);

			}
			//turn off LEDs after 5s.
			turnOffRequiredLEDs();
			
		}
		// if the currLED to be open is the yellow one.
		else if(currled==Yellow){
			// looping for 5 iterations each one will turn on yellow LEDs for 700ms and turn it off for 300ms.
			for (uint8_t k = 0; k<5; k++){
				
				// LEDs open for 700ms.
				turnOnRequiredLEDs(currled,ped_led);
				for (uint8_t j = 0; j<7; j++)
				{
					if (pedestrian_mode==ON&&pedestrian_flag==Off)
						pedestrianMode(currled,&iteration,&pedestrian_flag);				
						
					

					delayms(100);
				}
				//turning off LEDs for 300ms.
				turnOffRequiredLEDs();
				delayms(300);
			}
		}
	}

}

// pedestrian mode logic.
void pedestrianMode(uint8_t currLED,uint8_t *iteration,uint8_t *open_ped_led){
// we will change the iteration in the main logic based on the ped mode requirements.
	// ped_flag is on.	
	*open_ped_led = ON;
	if(currLED==green)
		*iteration = 0;
	
	else if(currLED==Yellow)
		*iteration = 0;

	pedestrian_mode = Off;		
}
	

//function thats returns car LED number based on iteration.
uint8_t getCarLED(uint8_t iteration){
	if (iteration==0)
		return 0;
	else if (iteration==1||iteration==3)
		return 1;
	else if (iteration==2)
		return 2;
	else
		return -1;	
			
}

//function thats returns pedestrian LED number based on iteration.
uint8_t getPedestrianLED(uint8_t iteration){
	if (iteration==0)
	return 2;
	else if (iteration==1||iteration==3)
	return 1;
	else if (iteration==2)
	return 0;
	else
	return -1;
}

//turns on LEDs on for cars and pedestrians based on the given LEDs.
void turnOnRequiredLEDs(uint8_t car_led,uint8_t ped_led){
	LED_on(PortB,ped_led);
	LED_on(PortA,car_led);
}


//turns on LEDs on for cars and pedestrians.
void turnOffRequiredLEDs(){
	LEDs_off(PortA);
	LEDs_off(PortB);
}