/*
 * TIM_interface.c
 *
 * Created: 12/27/2022 7:47:31 PM
 *  Author: fathi
 */ 
#include "../header_files/LIB.h"
#include"../header_files/MATH.h"
#include"../header_files/TIIM_private.h"
#include"../header_files/TIM_interface.h"
#include "../header_files/DIO_prog.h"
#include "../header_files/ISR_Vector.h"


     /* pointer to App function --> used overflow mode */
 void (*INT_OverFlow_Mode)(void) ;
 /* pointer to App function --> used CTC mode */
 void (*INT_CTC_Mode)(void) ;

/* 
*global varaible is conunt when the interrupt overflow happen 
*  used : in function TIM0_Vid_Delay_mS
*/
volatile  u32 count ;
void TIM0_Vid_NormalMode_Init() {
	
	SET_BIT(TCCR0_REG,7) ; 
    SET_BIT(TCCR0_REG,0) ; // no pre-scalar 
	SET_BIT(TIMSK_REG,0) ; // enbale overflow interrupt 
	SET_BIT(SREG_REG,7) ;// Enable global interrupt 
	

	
}
void TIM0_Vid_CTCMode_Init(u8 comp) {
	
	
	SET_BIT(TCCR0_REG,7) ;
	SET_BIT(TCCR0_REG,0) ; // no pre-scalar
	SET_BIT(TCCR0_REG,3) ; // CTC mode 
	SET_BIT(TIMSK_REG,1) ; // enbale CTC interrupt
	SET_BIT(SREG_REG,7) ;// Enable global interrupt
	
	OCR0_REG=comp ;
	
}
void TIM0_Vid_GenerateFreq_Init(u8 comp) {
	
	 // Make pin (CO0) in POTRB PB3 pin output 
	 DIO_vid_SetPintDirection(DIO_u8PORTB,DIO_u8PIN3,OUTPUT) ;
	SET_BIT(TCCR0_REG,7) ;
	SET_BIT(TCCR0_REG,0) ; // no pre-scalar
	SET_BIT(TCCR0_REG,3) ; // CTC mode
	SET_BIT(TCCR0_REG,4) ; // SET TOGGL MODE "Toggle OC0 on compare match"

	
	OCR0_REG=comp ;
	
	
}

void TIM0_Vid_Delay_mS(u32 delay) {
	count=0 ;
	TCNT0_REG=253 ;
	SET_BIT(TCCR0_REG,7) ;
	/*prescller 1024 */
	SET_BIT(TCCR0_REG,0) ; 
	SET_BIT(TCCR0_REG,2) ; 
	
	SET_BIT(TIMSK_REG,0) ; // enbale overflow interrupt
	SET_BIT(SREG_REG,7) ;// Enable global interrupt
	while((TCNT0_REG*count)<(delay*1000)) ;
	
}
ISR(TIMER0_OVF){
	INT_OverFlow_Mode() ;
	count++ ;
}
ISR(TIMER0_COMP){
	
	INT_CTC_Mode();
}