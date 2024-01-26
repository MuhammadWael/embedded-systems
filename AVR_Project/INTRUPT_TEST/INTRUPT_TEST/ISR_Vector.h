/*
 * ISR_Vector.h
 *
 * Created: 12/28/2022 7:08:31 PM
 *  Author: fathi
 */ 


#ifndef ISR_VECTOR_H_
#define ISR_VECTOR_H_

#define ISR(vector)\
void vector(void) __attribute__ ((signal));\
void vector (void)


#define INT0                   __vector_1
#define INT1                   __vector_2
#define INT2                   __vector_3
#define TIMER2_COMP            __vector_4
#define TIMER2_OVF             __vector_5
#define TIMER1_CAPT            __vector_6
#define TIMER1_COMPA           __vector_7
#define TIMER1_COMPB           __vector_8
#define TIMER1_OVF             __vector_9
#define TIMER0_COMP            __vector_10
#define TIMER0_OVF             __vector_11
#define SPI_STC                __vector_12
#define USART_RXC              __vector_13
#define USART_UDRE             __vector_14
#define USART_TXC              __vector_15
#define ADC                    __vector_16
#define EE_RDY                 __vector_17
#define ANA_COMP               __vector_18
#define  TWI                   __vector_19
#define SPM_RDY                __vector_20





#endif /* ISR_VECTOR_H_ */