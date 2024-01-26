/*
 * TIMER_Config.h
 *
 * Created: 8/4/2023 8:41:38 PM
 *  Author: Arabtech
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


#define TCCR0_REG  *((volatile u8*)0x53)
#define TCNT0_REG *((volatile u8*)0x52)
#define OCR0_REG *((volatile u8*)0x5c)
#define TIMSK_REG *((volatile u8*)0x59)
#define TIFR_REG *((volatile u8*)0x58)
#define SREG_REG *((volatile u8*)0x5f)

/*TIMER TERMENOLOGY*/
#define F_SYSTEM 16000000
#define TIMER_OVERFLOW_COUNT       256
#define TIMER_TICK (1/F_SYSTEM)
#define TIMER_OVERFLOW_TIME (TIMER_OVERFLOW_COUNT*TIMER_TICK)
/*Timer usage*/

#endif /* TIMER_CONFIG_H_ */