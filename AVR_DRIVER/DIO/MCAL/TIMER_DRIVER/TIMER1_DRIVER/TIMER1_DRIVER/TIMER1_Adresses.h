/*
 * TIMER1_Adresses.h
 *
 * Created: 8/12/2023 8:49:34 PM
 *  Author: Arabtech
 */ 


#ifndef TIMER1_ADRESSES_H_
#define TIMER1_ADRESSES_H_

#define TIFR_REG	*((volatile u8*)0x58)
#define TCCR1B_REG	*((volatile u8*)0x4e)
#define TCCR1A_REG	*((volatile u8*)0x4f)
#define OCR1A_REG	*((volatile u16*)0x4a)
#define OCR1B_REG	*((volatile u16*)0x48)
#define ICR_REG		*((volatile u16*)0x46)

#endif /* TIMER1_ADRESSES_H_ */