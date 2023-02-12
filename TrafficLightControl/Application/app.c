/*
 * app.c
 *
 * Created: 2023-02-03 2:56:45 PM
 *  Author: M.Eltokhy
 */ 
#include "app.h"

//global counter to keep track of timer overflow counts
uint8 overFlowCounter=0;
//enum variable for mode selection
trafficModes mode = normalMode;
//variable used for blinking yellow led
uint8 yellowLedState = 0;
//flag used for checking if traffic light was red or not
uint8 trafRedLed = 0;

void APP_init(void){
	//pins setup
	LedInit(trafficRed);		//initialize led connected in port A pin 0
	LedInit(trafficYellow);		//initialize led connected in port A pin 1
	LedInit(trafficGreen);		//initialize led connected in port A pin 2
	LedInit(pedestrianRed);		//initialize led connected in port B pin 0
	LedInit(pedestrianYellow);		//initialize led connected in port B pin 1
	LedInit(pedestrianGreen);		//initialize led connected in port B pin 2
	BUTTON_init(pedestrianButton);	//initialize button connected in port D pin 2
	//drivers initialization
	int0Init();				//initialize external interrupt 0
	timer0Init();			//initialize timer 0
}

void APP_start(void){
	while(1){
		switch(mode){
			case normalMode:
				if(overFlowCounter<=20){
					//turn on the traffic green light and the pedestrian red light  for 5 sec and reset the traffic red light flag
					trafRedLed=0;
					LedOn(pedestrianRed);
					LedOn(trafficGreen);
					LedOff(trafficRed);
					LedOff(trafficYellow);
					LedOff(pedestrianYellow);
					LedOff(pedestrianGreen);
				}else if(overFlowCounter > 20 && overFlowCounter <= 40){
					//blink the yellow traffic light for 5 sec and keep the pedestrian light red and reset the red traffic light flag
					trafRedLed=0;
					(yellowLedState)?LedOn(trafficYellow):LedOff(trafficYellow);
					LedOn(pedestrianRed);
					LedOff(trafficRed);
					LedOff(trafficGreen);
					LedOff(pedestrianYellow);
					LedOff(pedestrianGreen);
				}else if(overFlowCounter > 40 && overFlowCounter <= 60){
					//turn traffic red on and turn pedestrian green on for 5 sec and set the red traffic light flag
					trafRedLed=1;
					LedOn(trafficRed);
					LedOn(pedestrianGreen);
					LedOff(trafficYellow);
					LedOff(trafficGreen);
					LedOff(pedestrianYellow);
					LedOff(pedestrianRed);
				}else if(overFlowCounter > 60 ){
					//blink the yellow traffic light for 5 sec and keep the pedestrian light green and reset the red traffic light flag
					trafRedLed=0;
					(yellowLedState)?LedOn(trafficYellow):LedOff(trafficYellow);
					LedOn(pedestrianGreen);
					LedOff(trafficRed);
					LedOff(trafficGreen);
					LedOff(pedestrianYellow);
					LedOff(pedestrianRed);
				}
				break;
			case pedestrianMode:
				if(overFlowCounter<=20){
					//turn red traffic led on and green pedestrian led on
					LedOn(pedestrianGreen);
					LedOn(trafficRed);
					LedOff(pedestrianRed);
					LedOff(pedestrianYellow);
					LedOff(trafficYellow);
					LedOff(trafficGreen);
				}else if(overFlowCounter > 20 && overFlowCounter <= 40){
					//blink the two yellow leds for 5 sec while keeping green pedestrian led on
					(yellowLedState)?LedOn(trafficYellow):LedOff(trafficYellow);
					(yellowLedState)?LedOn(pedestrianYellow):LedOff(pedestrianYellow);
					LedOn(pedestrianGreen);
					LedOff(trafficRed);
					LedOff(trafficGreen);
					LedOff(pedestrianRed);
				}else if(overFlowCounter > 40){
					//at the end of halt mode return to pedestrian mode and reset counter
					overFlowCounter = 0;
					mode = normalMode;
				}
				break;
			case haltMode:
				if(overFlowCounter<=20){
					//turn on pedestrian red led and blink both pedestrian and traffic yellow leds
					(yellowLedState)?LedOn(trafficYellow):LedOff(trafficYellow);
					(yellowLedState)?LedOn(pedestrianYellow):LedOff(pedestrianYellow);
					LedOn(pedestrianRed);
					LedOff(pedestrianGreen);
					LedOff(trafficRed);
					LedOff(trafficGreen);
				}else if(overFlowCounter > 20){
					//at the end of halt mode return to pedestrian mode and reset counter
					overFlowCounter = 0;
					mode = pedestrianMode;
				}
				break;
			default:
			break;
		}
	}
}

//interrupt service routine for button pressing
ISR(EXT_INT_0){
	if((mode == normalMode) && trafRedLed){
		mode = pedestrianMode;
		overFlowCounter=0;
	}else if(mode == normalMode){
		mode = haltMode;
		overFlowCounter=0;
	}
}

//interrupt service routine for timer counting
ISR(Timer_0_OVF){
	overFlowCounter++;	//increment overflow counter
	yellowLedState = !yellowLedState;
	if(overFlowCounter > 80){
		overFlowCounter=0;	//reset timer counter
	}
}