/*
 * ADC_interface.c
 *
 * Created: 1/1/2023 9:48:02 AM
 *  Author: fathi
 */ 


#include "../header_files/LIB.h"
#include "../header_files/MATH.h"
#include "../header_files/ADC_private.h"
#include "../header_files/ADC_interface.h"
#include "../header_files/DIO_prog.h"
#include "../header_files/ISR_Vector.h"
#include "../header_files/LCD_interface.h"
#define F_CPU 12000000UL // set the frequency of microcontroller
#include <util/delay.h> // this header include all delay function like _delay_ms


 void(*ADC_ptr)(void) ;
/*
function name: ADC_Init
function arguments: (u8 channal) // channal -->ADC pin in porta
function return: void
function description: Init ADC & ADC PIN
*/

void ADC_Init( ){
	                
					
	             
	             SET_BIT(ADMUX_REG,6) ;// AVCC volte
	             SET_BIT(ADCSRA_REG,0); // ADC Prescaller bit0-->bit2 in ADCSRA_REG / 128
	             SET_BIT(ADCSRA_REG,1);
	             SET_BIT(ADCSRA_REG,2);
	             SET_BIT(ADCSRA_REG,7); // Enable ADC			
				//SET_BIT(SREG_REG,7) ;  // Enable  global interrupt
				//SET_BIT(ADCSRA_REG,3) ; //Enable ADC interrupt
}
	
void ADC_StartConversion(u8 channal){
	
	DIO_vid_SetPintDirection(DIO_u8PORTA,channal,INPUT) ;
	ADMUX_REG|=channal ; // Seclect channal ADC0-->ADC7
	SET_BIT(ADCSRA_REG,6) ; // start conversion
	
}	


/*
function name: ADC_Read
function arguments: (u8 channal) // channal -->ADC pin in porta
function return: u16
function description: return value in ADC_REG -->(data conversion)
*/

// return value without interrupt 
u16 ADC_Read( u8 channal ){
	
	DIO_vid_SetPintDirection(DIO_u8PORTA,channal,INPUT) ;
	ADMUX_REG|=channal ; // Seclect channal ADC0-->ADC7
	SET_BIT(ADCSRA_REG,6) ; // start conversion
	 while(GET_BIT(ADCSRA_REG,6)==1) ;
	return ADC_REG ;
 
}
/*
u16 ADC_Read(void ){
	
	 while(GET_BIT(ADCSRA_REG,6)==1) ;
	return ADC_REG ;
	
}
*/
void ADC_SetCallBack(void(*ptr)(void)){
	
	ADC_ptr=ptr ;
	
}


ISR(ADC){
     
  ADC_ptr() ;
  
	
	
}

