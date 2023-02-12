/*
 * dio.c
 *
 * Created: 2023-02-03 1:09:33 PM
 *  Author: M.Eltokhy
 */ 

//include .h
#include "dio.h"
//global variables

//functions definitions
void DIO_init(ports_t portNumber,pins_t pinNumber,direction_t direction){
	switch(portNumber){
		case PORT_A:
			(direction)?setBit(DDRA,pinNumber):clearBit(DDRA,pinNumber);	//SETTING PORTA DIRECTION
			break;
		case PORT_B:
			(direction)?setBit(DDRB,pinNumber):clearBit(DDRB,pinNumber);	//SETTING PORTB DIRECTION
			break;
		case PORT_C:
			(direction)?setBit(DDRC,pinNumber):clearBit(DDRC,pinNumber);	//SETTING PORTC DIRECTION
			break;
		case PORT_D:
			(direction)?setBit(DDRD,pinNumber):clearBit(DDRD,pinNumber);	//SETTING PORTD DIRECTION
			break;
		default:
			//error handling
			break;
	}
}

void DIO_write(ports_t portNumber,pins_t pinNumber,state_t state){
	switch(portNumber){
		case PORT_A:
			(state)?setBit(PORTA,pinNumber):clearBit(PORTA,pinNumber);
			break;
		case PORT_B:
			(state)?setBit(PORTB,pinNumber):clearBit(PORTB,pinNumber);
			break;
		case PORT_C:
			(state)?setBit(PORTC,pinNumber):clearBit(PORTC,pinNumber);
			break;
		case PORT_D:
			(state)?setBit(PORTD,pinNumber):clearBit(PORTD,pinNumber);
			break;
		default:
			//error handling
			break;
	}
}

void DIO_toggle(ports_t portNumber,pins_t pinNumber){
	switch(portNumber){
		case PORT_A:
			toggleBit(PORTA,pinNumber);
			break;
		case PORT_B:
			toggleBit(PORTB,pinNumber);
			break;
		case PORT_C:
			toggleBit(PORTC,pinNumber);
			break;
		case PORT_D:
			toggleBit(PORTD,pinNumber);
			break;
		default:
		//error handling
		break;
	}
}

void DIO_read(ports_t portNumber,pins_t pinNumber,uint8 *state){
	switch(portNumber){
		case PORT_A:
			*state=getBit(PINA,pinNumber);
			break;
		case PORT_B:
			*state=getBit(PINB,pinNumber);
			break;
		case PORT_C:
			*state=getBit(PINC,pinNumber);
			break;
		case PORT_D:
			*state=getBit(PIND,pinNumber);
			break;
		default:
		//error handling
		break;
	}
}