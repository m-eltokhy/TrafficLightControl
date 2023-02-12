/*
 * interrupt.h
 *
 * Created: 2023-02-10 3:23:55 PM
 *  Author: M.Eltokhy
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

//all includes .h
#include "../../Utilities/registers.h"
#include "../../Utilities/bitManipulation.h"
#include "../../Utilities/types.h"
#include "../DIO Driver/dio.h"

//Interrupt vectors
#define EXT_INT_0		__vector_1		//external interrupt request 0
#define EXT_INT_1		__vector_2		//external interrupt request 0
#define EXT_INT_2		__vector_3		//external interrupt request 0
#define Timer_0_COMP	__vector_10		//timer 0 compare match interrupt
#define Timer_0_OVF		__vector_11		//timer 0 overflow interrupt

//ISR definition
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

//Global interrupt
//set I-bit
#define sei() __asm__ __volatile__ ("sei" ::: "memory")
//clear I-bit
#define cli() __asm__ __volatile__ ("cli" ::: "memory")


//all driver functions prototypes
void int0Init(void);
void int1Init(void);

#endif /* INTERRUPT_H_ */