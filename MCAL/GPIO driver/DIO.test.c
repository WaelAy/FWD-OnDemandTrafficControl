/*
 * DIO.c
 *
 * Created: 1/9/2023 6:42:36 PM
 *  Author: Wael Ayman
 */ 

#include "DIO.h"
#include <stdio.h>

void test_helper(uint8_t test_result) {
	if (test_result == 1) {
		printf("Error something went wrong.\n");
	}
	else if (test_result == 0)
		printf("TEST OK.\n");
}

void dio_initTest() {
	//case user entered wrong args.
	printf("Case undefined port.\n");
	test_helper(dio_init('C', 0, OUTPUT));
	printf("Case wrong direction.\n");
	test_helper(dio_init(PortA, 5, 3));
	printf("Case wrong pin number. \n");
	test_helper(dio_init(PortA, 8, INPUT));
	printf("Case All is ok. \n");
	test_helper(dio_init(PortA, 5, OUTPUT));
	
} 
void dio_writeTest() {
	//case user entered wrong args.
	printf("Case undefined port.\n");
	test_helper(dio_write('C', 0, HIGH));
	printf("Case wrong value.\n");
	test_helper(dio_write(PortA, 5, 5 ));
	printf("Case wrong pin. \n");
	test_helper(dio_write(PortA, 8, 3));
	printf("Case All is ok. \n");
	test_helper(dio_write(PortA, 5, OUTPUT));
} 
void dio_readTest() {
	printf("Case undefined port.\n");
	uint8_t variable;
	uint8_t *state = &variable;
	*state = 0;
	test_helper(dio_read('C', 0, state));
	printf("Case wrong state.\n");
	*state = 5;
	test_helper(dio_read(PortA, 5, state));
	printf("Case wrong pin. \n");
	*state = 0;
	test_helper(dio_read(PortA, 8, state));
	printf("Case All is ok. \n");
	test_helper(dio_read(PortA, 5, state));
}

