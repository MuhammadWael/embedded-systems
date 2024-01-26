/*
 * ADC_Driver.c
 *
 * Created: 1/1/2023 9:43:56 AM
 * Author : fathi
 */ 

#include "header_files/LIB.h"
#include "header_files/MATH.h"
#include "header_files/ADC_interface.h"
#include "header_files/LCD_interface.h"
#include "header_files/DIO_prog.h"
#include "header_files/TIMER1_interface.h"
#define F_CPU 12000000UL // set the frequency of microcontroller
#include <util/delay.h> // this header include all delay function like _delay_ms

 /*
void FUN_READ(void){
	
	  u16 ADC_ =ADC_Read() ;
	 // ADC_ = (ADC_*5000)/1024 ;
	 ADC_=(ADC_*5)/1023 ;
	  LCD_write_command(0x85) ;
 	   LCD_write_number(ADC_);
	
	_delay_ms(500) ;
	
	if(ADC_>=3){
		DIO_vid_SetPintValue(DIO_u8PORTD,DIO_u8PIN7,HIGH) ;
	}else{
		DIO_vid_SetPintValue(DIO_u8PORTD,DIO_u8PIN7,LOW) ;
		
	}
	
}

*/
int main(void)
{  
	u16 ADC_READ =0 ;
	ADC_Init() ; 
	LCD_init() ;
	
	
    while (1) 
    {
		ADC_READ=ADC_Read(ADC0) ;
		ADC_READ=ADC_READ*500/1023 ;
		LCD_write_command(0x80) ;
		LCD_write_number(ADC_READ) ;
		_delay_ms(500) ;
			
		
	}
}

