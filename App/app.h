/*
 * app.h
 *
 * Created: 1/2/2023 7:11:44 PM
 *  Author: Wael Ayman
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAL/LED driver/LED.h"

//defining macros.


/************************************************************************/
/* Defining Enums.  */
/************************************************************************/

typedef enum carLights{Cgreen,Cyellow,Cred,Cerror} // car lights.
carLights;
typedef enum pedLights {Pred,Pyellow,Pgreen,Perror} // ped lights
pedLights;
typedef enum state {OK,Error} //enum to return process state.	
state_t;
//functions prototypes.
state_t APP_init(); // to initialize our app.
state_t APP_start(); // function to start our application.
state_t pedestrianMode(uint8_t currLED,uint8_t *iteration,uint8_t *open_ped_led); // function to toggle pedestrian mode.
carLights getCarLED(uint8_t iteration); // function returns the current car led.
pedLights getPedestrianLED(uint8_t iteration);// function returns current pedestrian led.
state_t turnOnRequiredLEDs(uint8_t car_led,uint8_t ped_led); // to turn on pedestrian led and car led.
state_t turnOffRequiredLEDs();


extern uint8_t iteration; // variable to hold current iteration.


#endif /* APP_H_ */