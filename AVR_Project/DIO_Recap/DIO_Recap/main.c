/*
 * DIO_Recap.c
 *
 * Created: 6/24/2023 6:51:47 PM
 * Author : Arabtech
 */ 

#include "std-type.h"
#include "math.h"
#include "DIO_interface.h"
#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
	DIO_void_set_pin_dir(PORTA,PIN0,OUTPUT);
	DIO_void_set_pin_dir(PORTA,PIN2,OUTPUT);
	DIO_void_set_pin_dir(PORTA,PIN3,OUTPUT);
	DIO_void_set_pin_dir(PORTA,PIN1,INPUT);
	u8 count = 0;
    while (1) 
    {
		if ((DIO_u8_get_pin_val(PORTA,PIN1)==HIGH) && count==0)
		{
			DIO_void_set_pin_val(PORTA,PIN0,HIGH);
			while(DIO_u8_get_pin_val(PORTA,PIN1)==HIGH);
			count++;
		}
		if ((DIO_u8_get_pin_val(PORTA,PIN1)==HIGH) && count==1)
		{
			DIO_void_set_pin_val(PORTA,PIN2,HIGH);
			while(DIO_u8_get_pin_val(PORTA,PIN1)==HIGH);
			count++;
		}
		if ((DIO_u8_get_pin_val(PORTA,PIN1)==HIGH) && count==2)
		{
			DIO_void_set_pin_val(PORTA,PIN3,HIGH);
			while(DIO_u8_get_pin_val(PORTA,PIN1)==HIGH);
			count++;
		}
		
		if ((DIO_u8_get_pin_val(PORTA,PIN1)==HIGH) &&(count == 3))
		{
			DIO_void_set_pin_val(PORTA,PIN0,LOW);
			DIO_void_set_pin_val(PORTA,PIN2,LOW);
			DIO_void_set_pin_val(PORTA,PIN3,LOW);
			while(DIO_u8_get_pin_val(PORTA,PIN1)==HIGH);
			count = 0;
		}
				
	}
}

