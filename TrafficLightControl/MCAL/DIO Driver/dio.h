/*
 * dio.h
 *
 * Created: 2023-02-03 1:10:02 PM
 *  Author: M.Eltokhy
 */ 


#ifndef DIO_H_
#define DIO_H_

//all includes .h
#include "../../Utilities/registers.h"
#include "../../Utilities/bitManipulation.h"
#include "../../Utilities/types.h"

//all internal driver typedef
	//ports enum
	typedef enum {PORT_A,PORT_B,PORT_C,PORT_D}ports_t;
	//pins enum
	typedef enum {PIN_0,PIN_1,PIN_2,PIN_3,PIN_4,PIN_5,PIN_6,PIN_7}pins_t;
	//direction enum
	typedef enum {INPUT,OUTPUT}direction_t;
	//state enum
	typedef enum {LOW,HIGH}state_t;

//all driver macros

//all driver functions prototypes
	void DIO_init(ports_t portNumber,pins_t pinNumber,direction_t direction);	// initialize DIO direction
	void DIO_write(ports_t portNumber,pins_t pinNumber,state_t state);	// write data to DIO
	void DIO_toggle(ports_t portNumber,pins_t pinNumber);	//toggle DIO
	void DIO_read(ports_t portNumber,pins_t pinNumber,uint8 *state);	// read data from DIO




#endif /* DIO_H_ */