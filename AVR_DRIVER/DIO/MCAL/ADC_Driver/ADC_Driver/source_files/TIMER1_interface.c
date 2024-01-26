/*
 * TIMER1_interface.c
 *
 * Created: 12/31/2022 4:46:54 PM
 *  Author: fathi
 */ 

#include "../header_files/LIB.h"
#include "../header_files/MATH.h"
#include "../header_files/TIMER1_private.h"
#include "../header_files/TIMER1_interface.h"
#include "../header_files/DIO_prog.h"
#include <avr/io.h>

/*
function name: TIMER1_PWM_FastFreq_Init
function arguments: (uint8  pin,) pin --> oc1b (pD4) , oc1a (pD5)
function return: void
function description: init PWM fast  ferequancy  mode / non inverting / No prescaling
*/

void TIMER1_PWM_FastFreq_Init(u8 pin) {
	
     switch(pin){
	 case 1: 
	            DIO_vid_SetPintDirection(DIO_u8PORTD,DIO_u8PIN5,OUTPUT) ; // Make bit 5(OC1A) in POTRD-->OUTPUT 
	            SET_BIT(TCCR1A_REG,7) ; // non inverting mode --> OC1A
				/* Fast PWM  10 bit */
				SET_BIT(TCCR1A_REG,0) ;
				SET_BIT(TCCR1A_REG,1) ;
				SET_BIT(TCCR1B_REG,3) ;
				SET_BIT(TCCR1B_REG,0) ;// NOprescaller
				break;
				
	 
	 case 2:
	             DIO_vid_SetPintDirection(DIO_u8PORTD,DIO_u8PIN4,OUTPUT) ; // Make bit4 (OC1B) in POTRD-->OUTPUT 
	            SET_BIT(TCCR1A_REG,5) ;  // non inverting mode --> OC1B
				/* Fast PWM  10 bit */
				SET_BIT(TCCR1A_REG,0) ;
				SET_BIT(TCCR1A_REG,1) ;
				SET_BIT(TCCR1B_REG,3) ;
				SET_BIT(TCCR1B_REG,0) ;// NOprescaller
	                   break;
	 
	 }
	
	
	
	
}

/*
function name: TIMER1_PWM_FastFreq_Duty_cycle
function arguments: (uint8  duty) , pin 
function return: void
function description: configer OC1A Register
*/

/* duty= oc/max *100

oc= max/duty*100---> 1023 
OC = 1023/100*duty = 10.23*duty
 */
void TIMER1_PWM_FastFreq_Duty_cycle(u8 duty , u8 pin ) {
	
 
 
	          switch(pin){
				  
				  case 1: 
				         OCR1A_REG= duty*10.23 ; break;
				  case 2:
				         OCR1B_REG=duty*10.23; break;
			     default: 
						             // noting  
									 break;
						 
						 
			  }
	
	
}
