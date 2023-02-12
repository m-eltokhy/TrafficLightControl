/*
 * timer.c
 *
 * Created: 2023-02-04 9:20:43 PM
 *  Author: M.Eltokhy
 */ 

#include "timer.h"

//setup timer0 to count 250ms each overflow
void timer0Init(void){
	//set the mode to normal mode
	clearBit(TCCR0,3);
	clearBit(TCCR0,6);
	//set to Fclk/1024 prescaler
	TCCR0|=5;
	//set I-bit to enable global interrupt
	sei();
	//set timer0 overflow interrupt on
	setBit(TIMSK,0);
	//reset flag
	setBit(TIFR,0);
	//set timer initial value to 0
	TCNT0 = 0x00;
}