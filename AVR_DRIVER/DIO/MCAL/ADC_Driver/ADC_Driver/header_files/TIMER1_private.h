/*
 * TIMER1_private.h
 *
 * Created: 12/31/2022 4:45:56 PM
 *  Author: fathi
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TCCR1A_REG      *((volatile  u8*)0x4F)
#define TCCR1B_REG      *((volatile  u8*)0x4E)
#define OCR1A_REG       *((volatile  u16*)0x4A)// OCR1AH_REG + OCR1AL_REG

#define OCR1B_REG      *((volatile  u16*)0x48) // OCR1BH_REG + OCR1BL_REG



#endif /* TIMER1_PRIVATE_H_ */