/*
 * 7-SEGMENT.c
 *
 * Created: 7/7/2023 3:59:08 AM
 * Author : Arabtech
 */ 
#include "STD_TYPE.h"
#include "MATH.h"
#include "SEGMENT_Interface.h"
#include "DIO_Interface.h"
#define F_CPU 16000000ul
#include <util/delay.h>



int main(void)
{
    set_port_dir(PORTA,OUTPUT);
    EN1_state(HIGH);
    EN2_state(HIGH);
	u8 j = 0;
	u8 i = 0;
	u8 k = 0;
    while (1) 
    {
		for (i = 0;i <= 9;i++)
		{
			for(j = 0;j <= 9;j++)
			{
				for(k = 0;k <= 50 ; k++)
				{
					SEVEN_SEGMENT_DISPLAY(i);
					EN1_state(LOW);
					EN2_state(HIGH);	
					_delay_ms(5);
					SEVEN_SEGMENT_DISPLAY(j);
					EN2_state(LOW);
					EN1_state(HIGH);
					_delay_ms(5);	
				}	
			}
		}
    }
}

