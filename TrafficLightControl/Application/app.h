/*
 * app.h
 *
 * Created: 2023-02-03 2:56:53 PM
 *  Author: M.Eltokhy
 */ 


#ifndef APP_H_
#define APP_H_

//application typedefs
typedef enum{
	normalMode,pedestrianMode,haltMode}trafficModes;

//defines
#define trafficRed			PORT_A,PIN_0
#define trafficYellow		PORT_A,PIN_1
#define trafficGreen		PORT_A,PIN_2
#define pedestrianRed		PORT_B,PIN_0
#define pedestrianYellow	PORT_B,PIN_1
#define pedestrianGreen		PORT_B,PIN_2
#define pedestrianButton	PORT_D,PIN_2

//application includes
//#include <avr/io.h>
#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Button Driver/button.h"

//application function
void APP_init(void);
void APP_start(void);

#endif /* APP_H_ */