/*
 * TIMER_Interface.h
 *
 * Created: 8/4/2023 8:42:11 PM
 *  Author: Arabtech
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define OVERFLOW 1
#define CTC_MODE 0
#define _64_PRESCALER 3
#define TIMER0_PRESCALER _64_PRESCALER
 
void timer0_overflow_delay_us(u16 delay);
void timer0_overflow_delay_ms(u16 delay);
void TIMER0_init();
void set_callback(u8 mode,void(*ptr1)(void));
void TIMER0_CTC_Init(void);
void timer0_CTC(u8 value);
void timer0_fast_PWM(u8 duty);
void TIMER0_START();
void TIMER0_STOP();

#endif /* TIMER_INTERFACE_H_ */