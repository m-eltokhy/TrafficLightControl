/*
 * led.c
 *
 * Created: 2023-02-03 2:37:57 PM
 *  Author: M.Eltokhy
 */ 
#include "led.h"

void LedInit(ports_t ledPort,pins_t ledPin){
	DIO_init(ledPort,ledPin,OUTPUT);
}

void LedOn(ports_t ledPort,pins_t ledPin){
	DIO_write(ledPort,ledPin,HIGH);
}

void LedOff(ports_t ledPort,pins_t ledPin){
	DIO_write(ledPort,ledPin,LOW);
}

void LedToggle(ports_t ledPort,pins_t ledPin){
	DIO_toggle(ledPort,ledPin);
}
