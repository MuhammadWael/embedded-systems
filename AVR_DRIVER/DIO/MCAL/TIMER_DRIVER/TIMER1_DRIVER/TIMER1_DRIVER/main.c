/*
 * TIMER1_DRIVER.c
 *
 * Created: 8/12/2023 8:47:53 PM
 * Author : Arabtech
 */ 

#include "STD_TYPE.h"
#include "MATH.h"
#include "TIMER1_Adresses.h"
#include "TIMER1_Interface.h"
#include "DIO_Interface.h"
#define F_CPU 16000000
#include <util/delay.h>


int main(void)
{
	
	TIMER1_fast_PWM_init();	 
	DIO_void_Set_pin_dir(PORTD, PIN5, OUTPUT);
	u32 i = 0;
	
     while (1) 
    {
		for (i = 2000; i <= 4000;i++)
		{
			TIMER1_FAST_PWM(i);
			_delay_ms(5);
		}
    }
}

