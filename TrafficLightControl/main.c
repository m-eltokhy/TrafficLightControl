/*
 * TrafficLightControl.c
 *
 * Created: 2023-02-01 7:12:38 PM
 * Author : M.Eltokhy
 */ 

#include "Application/app.h"

//counter for testing timer driver
uint8 counter=0;

int main(void)
{
	/*
	//DIO driver test initialization
	uint8 button=0;
	//DIO_init(PORT_A,0,OUTPUT);
	//DIO_init(PORT_A,1,INPUT);
	//Interrupt driver test initialization
	DIO_init(PORT_D,0,OUTPUT);
	DIO_init(PORT_D,2,INPUT);
	int0Init();
	//Timer driver test initialization
	timer0Init();
	DIO_init(PORT_A,7,OUTPUT);
	//LED driver test initialization
	LedInit(PORT_A,0);
	//Button driver test initialization
	BUTTON_init(PORT_A,1);
	while(1){
		//DIO_read(PORT_A,1,&button);
		//(button)?DIO_write(PORT_A,0,HIGH):DIO_write(PORT_A,0,LOW);
		BUTTON_read(PORT_A,1,&button);
		(button)?LedOn(PORT_A,0):LedOff(PORT_A,0);
		if((!(counter%4)) && counter){
			DIO_toggle(PORT_A,7);
		}
	}
	*/
	APP_init();
	APP_start();
	return 0;
}

/*
//interrupt driver test
ISR(EXT_INT_0){
	DIO_toggle(PORT_D,0);
}

//timer driver test
ISR(Timer_0_OVF){
	counter++;
}
*/

