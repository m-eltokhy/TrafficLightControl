/*
 * button.h
 *
 * Created: 2023-02-03 3:12:40 PM
 *  Author: M.Eltokhy
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

//defines

//includes
#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Timer Driver/timer.h"
#include "../../MCAL/Interrupt Driver/interrupts.h"

//functions
void BUTTON_init(ports_t buttonPort,pins_t buttonPin);
void BUTTON_read(ports_t buttonPort,pins_t buttonPin,uint8 *state);




#endif /* BUTTON_H_ */