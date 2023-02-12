/*
 * registers.h
 *
 * Created: 2023-02-03 12:49:00 PM
 *  Author: M.Eltokhy
 */ 

/************************************************************************/
/*                     All Micro controller Registers                   */
/************************************************************************/

#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"

/************************************************************************/
/*                         DIO Registers                                */
/************************************************************************/

//Port A Registers
#define PORTA	*((volatile uint8*)0x3B)	//8-bit register
#define DDRA	*((volatile uint8*)0x3A)	//8-bit register
#define PINA	*((volatile uint8*)0x39)	//8-bit register

//Port B Registers
#define PORTB	*((volatile uint8*)0x38)	//8-bit register
#define DDRB	*((volatile uint8*)0x37)	//8-bit register
#define PINB	*((volatile uint8*)0x36)	//8-bit register

//Port C Registers
#define PORTC	*((volatile uint8*)0x35)	//8-bit register
#define DDRC	*((volatile uint8*)0x34)	//8-bit register
#define PINC	*((volatile uint8*)0x33)	//8-bit register

//Port D Registers
#define PORTD	*((volatile uint8*)0x32)	//8-bit register
#define DDRD	*((volatile uint8*)0x31)	//8-bit register
#define PIND	*((volatile uint8*)0x30)	//8-bit register

/************************************************************************/
/*               External Interrupts Registers                          */
/************************************************************************/
//External interrupts registers
#define SREG	*((volatile uint8*)0x5F)	//8-bit Interrupt register
#define MCUCR	*((volatile uint8*)0x55)	//8-bit edge control for Interrupt register
#define GICR	*((volatile uint8*)0x5B)	//8-bit Interrupt enable register
#define GIFR	*((volatile uint8*)0x5A)	//8-bit Interrupt flag register

/************************************************************************/
/*			               Timers Registers                             */
/************************************************************************/

//general timers registers
#define TIMSK	*((volatile uint8*)0x59)	//8-bit register timers interrupt
#define TIFR	*((volatile uint8*)0x58)	//8-bit register timers flags

//timer 0 Registers
#define TCCR0	*((volatile uint8*)0x53)	//8-bit register for mode
#define TCNT0	*((volatile uint8*)0x52)	//8-bit register for counting
#define OCR0	*((volatile uint8*)0x5C)	//8-bit register for compare match

#endif /* REGISTERS_H_ */