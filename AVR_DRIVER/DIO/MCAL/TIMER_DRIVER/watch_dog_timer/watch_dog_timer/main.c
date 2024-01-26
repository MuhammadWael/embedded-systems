/*
 * watch_dog_timer.c
 *
 * Created: 8/18/2023 7:24:59 PM
 * Author : Arabtech
 */ 

#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "WDT_Interface.h"
#define F_CPU 16000000ul
#include <util/delay.h>

int main(void)
{	
	DIO_void_Set_pin_dir(PORTA,PIN0,OUTPUT);
	DIO_void_Set_pin_dir(PORTA,PIN1,OUTPUT);
	DIO_void_Set_pin_val(PORTA,PIN1,HIGH);
    
    while (1) 
    {
		WDT_Start(WDT_TIME_OUT_1s);
		
		
    }
}

