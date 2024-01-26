/*
 * led_blink.c
 *
 * Created: 5/20/2023 7:26:18 PM
 * Author : Arabtech
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "math.h"


int main(void)
{
    SET_BIT(DDRC,2);
	SET_BIT(DDRC,7);
	SET_BIT(DDRD,3);
	
    while (1) 
    {
	CLR_BIT(PORTC,7);
    SET_BIT(PORTC,2);
	_delay_ms(200);
	CLR_BIT(PORTC,2);
	SET_BIT(PORTD,3);
	_delay_ms(200);
	CLR_BIT(PORTD,3);
	SET_BIT(PORTC,7);
	_delay_ms(200);
    
    }
}

