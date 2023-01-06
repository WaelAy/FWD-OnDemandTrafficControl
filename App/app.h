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
#define Yellow 1
#define  Red 2
#define green 0

//functions prototypes.
void APP_init(); // to initialize our app.
void APP_start(); // function to start our application.
void pedestrianMode(uint8_t currLED,uint8_t *iteration,uint8_t *open_ped_led); // function to toggle pedestrian mode.
uint8_t getCarLED(uint8_t iteration); // function returns the current car led.
uint8_t getPedestrianLED(uint8_t iteration);// function returns current pedestrian led.
void turnOnRequiredLEDs(uint8_t car_led,uint8_t ped_led); // to turn on pedestrian led and car led.
void turnOffRequiredLEDs(); // turn off leds.


extern uint8_t iteration; // variable to hold current iteration.


#endif /* APP_H_ */