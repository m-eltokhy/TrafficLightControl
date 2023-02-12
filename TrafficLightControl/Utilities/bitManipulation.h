/*
 * bitManipulation.h
 *
 * Created: 2023-02-03 2:14:34 PM
 *  Author: M.Eltokhy
 */ 


#ifndef BITMANIPULATION_H_
#define BITMANIPULATION_H_

#define setBit(port,bit)	(port|=(1<<bit))
#define clearBit(port,bit)	(port&=~(1<<bit))
#define toggleBit(port,bit)	(port^=(1<<bit))
#define getBit(port,bit)	((port&(1<<bit))>>bit)



#endif /* BITMANIPULATION_H_ */