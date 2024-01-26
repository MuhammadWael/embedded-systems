/*
 * TIMER1_Prog.c
 *
 * Created: 8/12/2023 8:50:40 PM
 *  Author: Arabtech
 */ 
#include "STD_TYPE.h"
#include "MATH.h"
#include "TIMER1_Adresses.h"
#include "TIMER1_Interface.h"

void TIMER1_fast_PWM_init(void)
{
	
	/* for CLEAR on Compare match SET on HIGH */
	//SET PWM for channel A (OCR1A) -- clear bit 6 and set bit 7
	SET_BIT(TCCR1A_REG,7);
	CLR_BIT(TCCR1A_REG,6);
	/* SET Fast PWM --> ICR*/
	CLR_BIT(TCCR1A_REG,0);
	SET_BIT(TCCR1A_REG,1);
	SET_BIT(TCCR1B_REG,3);
	SET_BIT(TCCR1B_REG,4);
	/*SET ICR */
	ICR_REG = 40000;
	/*SET OCR*/
	//OCR1A_REG = 2000;
	/*SET PRESCALAR*/
	CLR_BIT(TCCR1B_REG,0);
	SET_BIT(TCCR1B_REG,1);
	CLR_BIT(TCCR1B_REG,2);
}

void TIMER1_FAST_PWM(u32 tick)
{	//Range FROM 2000 TO 4000
	OCR1A_REG = tick;
}

