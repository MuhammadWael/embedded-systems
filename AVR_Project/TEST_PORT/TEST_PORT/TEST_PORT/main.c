/*
 * TEST_PORT.c
 *
 * Created: 7/7/2023 2:59:49 AM
 * Author : Arabtech
 */ 

#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Interface.h"
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    set_port_dir(PORTA,OUTPUT);
	set_port_val(PORTA,HIGH);
    while (1) 
    {
    }
}

