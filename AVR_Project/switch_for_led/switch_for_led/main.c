/*
 * switch_for_led.c
 *
 * Created: 5/20/2023 8:18:22 PM
 * Author : Arabtech
 */ 

#include <avr/io.h>
#include "math.h"


int main(void)
{
	int led = 0;
	SET_BIT(DDRC,2);
	CLR_BIT(DDRB,0);
    while (1) 
    {
		if(GET_BIT(PINB,0)==1) && (led == 0)
		{
			SET_BIT(PORTC,2);
			while(GET_BIT(PINB,0)==1);
			led = 1;
		}
		if((GET_BIT(PINB,0)==1) && (led == 1))
		{
			CLR_BIT(PORTC,2);
			
			led = 0;
		}
    }
}

