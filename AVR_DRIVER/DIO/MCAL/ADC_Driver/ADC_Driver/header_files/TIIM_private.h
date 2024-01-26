/*
 * TIIM_private.h
 *
 * Created: 12/27/2022 7:46:48 PM
 *  Author: fathi
 */ 


#ifndef TIIM_PRIVATE_H_
#define TIIM_PRIVATE_H_

#define  TCCR0_REG   *((volatile u8*)0x53)
#define  TCNT0_REG   *((volatile u8*)0x52)
#define  OCR0_REG    *((volatile u8*)0x5C)
#define  TIMSK_REG   *((volatile u8*)0x59)
#define  TIFR_REG   *((volatile u8*)0x58)
#define  SREG_REG   *((volatile u8*)0x5F)


#endif /* TIIM_PRIVATE_H_ */