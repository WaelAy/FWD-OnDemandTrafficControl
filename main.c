/*
 * On-demand Traffic light control.c
 *
 * Created: 12/24/2022 9:13:59 AM
 * Author : Wael Ayman
 */ 


#include "App/app.h"
int main(void)
{

	APP_init();
	OCR0 = 0x7C; // to set timer to the disired compare match.
    while (1) 
    {

		APP_start();					

    }
	
}

