/*
 * TWO_AVR_LED_SWITCH.c
 *
 * Created: 8/25/2023 10:05:17 PM
 * Author : Arabtech
 */ 

#include "MATH.h"
#include "STD_TYPE.h"
#include "DIO_Interface.h"
#include "USART_Interface.h"

int main(void)
{
    DIO_void_Set_pin_dir(PORTB,PIN0,INPUT);
	DIO_void_Set_pin_dir(PORTD,PIN6,INPUT);
	DIO_void_Set_pin_dir(PORTD,PIN3,INPUT);
	USART_Init();
	DIO_void_Set_pin_dir(PORTD,PIN1,OUTPUT);
	
    while (1) 
    {
		if (DIO_u8_Get_pin_val(PORTB,PIN0) == 1)
		{
			
			USART_TX('0');
			while(DIO_u8_Get_pin_val(PORTB,PIN0) == 1);
		}
		if (DIO_u8_Get_pin_val(PORTD,PIN6) == 1)
		{
			USART_TX('1');
			while(DIO_u8_Get_pin_val(PORTD,PIN6) == 1);
		}
		if (DIO_u8_Get_pin_val(PORTD,PIN2) == 1)
		{
			USART_TX('2');
			while(DIO_u8_Get_pin_val(PORTD,PIN2) == 1);
		}
    }
}

