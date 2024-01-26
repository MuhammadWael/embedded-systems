/*
 * ADC_private.h
 *
 * Created: 1/1/2023 9:47:02 AM
 *  Author: fathi
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define  ADMUX_REG     *((volatile u8*)0x27)
#define  ADCSRA_REG     *((volatile u8*)0x26)
#define  ADC_REG    *((volatile u16*)0x24) // ADCL + ADCH 
#define  SREG_REG   *((volatile u8*)0x5F)

#endif /* ADC_PRIVATE_H_ */