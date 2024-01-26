/*
 * LED_DRIVER.c
 *
 * Created: 7/7/2023 3:03:35 AM
 * Author : Arabtech
 */ 

#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Interface.h"
#include "LED_interface.h"
#include <util/delay.h>
#define F_CPU 16000000ul



int main(void)
{
	LED_ON(PORTC,PIN7);
    while (1) 
    {
		LED_TOGGLE(PORTC,PIN7);
		_delay_ms(1500);
    }
}

