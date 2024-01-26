/*
 * TIMER_Prog.c
 *
 * Created: 8/4/2023 8:42:46 PM
 *  Author: Arabtech
 */ 

#include "STD_TYPE.h"
#include "MATH.h"
#include "TIMER_Config.h"
#include "TIMER_Interface.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "ISR_Vector.h"

void(*ptr)(void) = 0;
void TIMER0_init()
{
	/*preScaler*/
	SET_BIT(TCCR0_REG,0);
	/* ENABLE OVERFLOW*/
	SET_BIT(TIMSK_REG,0);
	/*ENABLE GLOBAL INTERUPT*/
	SET_BIT(SREG_REG,7);
	
}

void TIMER0_START()
{
	 SET_BIT(TCCR0_REG,0);
}

void TIMER0_STOP() 
{
	TCCR0_REG=0x00;
}

void timer0_overflow_delay_us(u16 delay)
{
	    delay=(delay*62.5)/1000; 
		u16 count = 0;
		while (count < delay)
		{
			SET_BIT(TCCR0_REG,0);
			while(GET_BIT(TIFR_REG,0)==0);
			
			SET_BIT(TIFR_REG,0); 
			
			TCCR0_REG=0x00;
			count++;
		}
}
void timer0_overflow_delay_ms(u16 delay)
{
	
	u16 count = 0;
	delay =delay*62.5;
	while (count < delay)
	{
		TIMER0_START();
		while(GET_BIT(TIFR_REG,0)==0);
		SET_BIT(TIFR_REG,0);
		TIMER0_STOP();
		count++;
	}
}


void timer0_CTC(u8 value)
{
	OCR0_REG = value;	
}

void timer0_fast_PWM(u8 duty)
{
/*First we will minimize the F_system
we will divide it by PreScalar 1024 
so it would be 1600000/1024
the Period would be 64 Micro Second*/

//From the data sheet Set bit 3,6 to be Fast PWm
//bit 5 to be in none inverting mode

//to clear the flag do SET for it

	//make the pin output
	DIO_void_Set_pin_dir(PORTB,PIN3,OUTPUT); 
	TCCR0_REG = 0x6D;
	OCR0_REG = duty*2.55;
	//the flag of TIFR bit 1 will be high 
	while((TIFR_REG & 1<<1) == 0);
	TIFR_REG |= 1<<1;
	
}

void set_callback(void(*ptr1)(void))
{
	ptr = ptr1;
}

ISR(TIMER0_OVF)
{
	ptr();
}
