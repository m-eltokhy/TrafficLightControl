/*
 * interrupt.c
 *
 * Created: 2023-02-10 3:23:43 PM
 *  Author: M.Eltokhy
 */ 

#include "interrupts.h"

void int0Init(void){
	//set I-bit to enable interrupts
	sei();
	//set external int0 to rising edge trigger
	setBit(MCUCR,0);
	setBit(MCUCR,1);
	//enable int0
	setBit(GICR,6);
}

void int1Init(void){
	//set I-bit to enable interrupts
	sei();
	//set external int1 to rising edge trigger
	setBit(MCUCR,2);
	setBit(MCUCR,3);
	//enable int1
	setBit(GICR,7);
}
