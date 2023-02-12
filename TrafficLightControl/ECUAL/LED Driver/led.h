/*
 * led.h
 *
 * Created: 2023-02-03 2:37:47 PM
 *  Author: M.Eltokhy
 */ 


#ifndef LED_H_
#define LED_H_

//all includes .h
#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Timer Driver/timer.h"
#include "../../MCAL/Interrupt Driver/interrupts.h"

//all internal driver typedef
typedef enum{OFF,ON}ledState_t;

//all driver typedefs


//all driver functions prototypes
void LedInit(ports_t ledPort,pins_t ledPin);
void LedOn(ports_t ledPort,pins_t ledPin);
void LedOff(ports_t ledPort,pins_t ledPin);
void LedToggle(ports_t ledPort,pins_t ledPin);




#endif /* LED_H_ */