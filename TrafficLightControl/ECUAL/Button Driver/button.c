/*
 * button.c
 *
 * Created: 2023-02-03 3:12:54 PM
 *  Author: M.Eltokhy
 */ 

#include "button.h"


void BUTTON_init(ports_t buttonPort,pins_t buttonPin){
	DIO_init(buttonPort,buttonPin,INPUT);
}

void BUTTON_read(ports_t buttonPort,pins_t buttonPin,uint8 *state){
	DIO_read(buttonPort,buttonPin,state);
}