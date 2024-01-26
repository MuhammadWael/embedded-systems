/*
 * 7-Segment display.c
 *
 * Created: 5/26/2023 2:46:36 PM
 * Author : Arabtech
 */ 
#include <avr/io.h>
#define F_CPU 16000000ul
#include <util/delay.h>
#include "std-type.h"

#define SSD(val) PORTA=((val<<4)|(PORTA&0x0f))

int main(void)
{
	DDRA = 0xff;
	u8 arr[10] = {0,1,2,3,4,5,6,7,8,9};
    while (1) 
    {
		for (int i = 0; i <= 9;i++)
		{
			PORTA = SSD(arr[i]);
			_delay_ms(500);
		}
    }
}

