/*
 * TIM_interface.h
 *
 * Created: 12/27/2022 7:47:05 PM
 *  Author: fathi
 */ 


#ifndef TIM_INTERFACE_H_
#define TIM_INTERFACE_H_


void TIM0_Vid_NormalMode_Init() ;
void TIM0_Vid_CTCMode_Init(u8 comp) ;
void TIM0_Vid_GenerateFreq_Init(u8 comp) ;
void TIM0_Vid_Delay_mS(u32 delay) ;

extern void (*INT_OverFlow_Mode)(void) ;
extern void (*INT_CTC_Mode)(void) ;

#endif /* TIM_INTERFACE_H_ */