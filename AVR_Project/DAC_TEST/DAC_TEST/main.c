/*
 * DAC_TEST.c
 *
 * Created: 9/22/2023 7:44:57 PM
 * Author : Arabtech
 */ 
#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#define F_CPU 16000000ul
#include <util/delay.h>

int main(void)
{
    set_port_dir(PORTA,OUTPUT);
    while (1) 
    {
		for (int i = 0;i < 255;i++)
		{
			set_port_val(PORTA,i);
		}
		for (int i = 255;i > 0;i--)
		{
			set_port_val(PORTA,i);
		}
    }
}

