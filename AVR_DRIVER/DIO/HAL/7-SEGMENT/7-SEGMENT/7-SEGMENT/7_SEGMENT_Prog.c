/*
 * _7_SEGMENT_Prog.c
 *
 * Created: 7/7/2023 4:00:58 AM
 *  Author: Arabtech
 */ 

#include "STD_TYPE.h"
#include "MATH.h"
#include "SEGMENT_Interface.h"
#include "DIO_Interface.h"
#include "DIO_Adress.h"

void SEVEN_SEGMENT_DISPLAY(u8 number)
{
	PORTA_REG = ((number<<4) | (PORTA_REG & 0x0f));
}
void EN1_state(u8 state)
{
	if(state == HIGH)
	{
		DIO_void_Set_pin_val(PORTB,PIN1,HIGH);
	}
	else
	{
		DIO_void_Set_pin_val(PORTB,PIN1,LOW);
	}
}
void EN2_state(u8 state)
{
	if(state == HIGH)
	{
		DIO_void_Set_pin_val(PORTB,PIN2,HIGH);
	}
	else
	{
		DIO_void_Set_pin_val(PORTB,PIN2,LOW);
	}	
}