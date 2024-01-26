/*
 * IncFile1.h
 *
 * Created: 12/20/2022 8:53:42 AM
 *  Author: fathi
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_


#define SET_BIT(reg,bin)         (reg|= (1<<bin))  //  make bit 1
#define CLR_BIT(reg,bin)         (reg&=~(1<<bin)) //  make bin 0
#define TOGGLE_BIT(reg,bin)      (reg^= 1<<bin) // if bit =0 make bit 1 // if bit 1 make bit 0
#define GET_BIT(reg,bin)         ((reg>>bin)& 1) // read status of pin 



#endif /* INCFILE1_H_ */