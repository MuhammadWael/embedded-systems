/*
 * DIO_interface.c
 *
 * Created: 6/24/2023 6:53:33 PM
 *  Author: Arabtech
 */ 
#include "MATH.H"
#include "std-type.h"
#include "DIO_adress.h"
#include "DIO_interface.h"

void DIO_void_set_pin_dir(u8 copy_u8_port ,u8 copy_u8_pin ,u8 copy_u8_status)
{
	if (copy_u8_status == OUTPUT)
	{
		switch(copy_u8_port)
		{
			case PORTA : SET_BIT(DDRA_REG,copy_u8_pin); break;
			case PORTB : SET_BIT(DDRB_REG,copy_u8_pin); break;
			case PORTC : SET_BIT(DDRC_REG,copy_u8_pin); break;
			case PORTD : SET_BIT(DDRD_REG,copy_u8_pin); break;	
		}
	}
	else if (copy_u8_status == INPUT)
	{
		switch(copy_u8_port)
		{
			case PORTA : CLR_BIT(DDRA_REG,copy_u8_pin); break;
			case PORTB : CLR_BIT(DDRB_REG,copy_u8_pin); break;
			case PORTC : CLR_BIT(DDRC_REG,copy_u8_pin); break;
			case PORTD : CLR_BIT(DDRD_REG,copy_u8_pin); break;
		}
	}
}

void DIO_void_set_pin_val(u8 copy_u8_port ,u8 copy_u8_pin ,u8 copy_u8_value)
{
	if (copy_u8_value == HIGH)
	{
		switch(copy_u8_port)
		{
			case PORTA : SET_BIT(PORTA_REG,copy_u8_pin); break;
			case PORTB : SET_BIT(PORTB_REG,copy_u8_pin); break;
			case PORTC : SET_BIT(PORTC_REG,copy_u8_pin); break;
			case PORTD : SET_BIT(PORTD_REG,copy_u8_pin); break;
		}	
	}
	else if (copy_u8_value == LOW)
	{
		switch(copy_u8_port)
		{
			case PORTA : CLR_BIT(PORTA_REG,copy_u8_pin); break;
			case PORTB : CLR_BIT(PORTB_REG,copy_u8_pin); break;
			case PORTC : CLR_BIT(PORTC_REG,copy_u8_pin); break;
			case PORTD : CLR_BIT(PORTD_REG,copy_u8_pin); break;
		}
	}
}

u8 DIO_u8_get_pin_val(u8 copy_u8_port ,u8 copy_u8_pin)
{
	u8 LOC_pin_value = 0;
	switch(copy_u8_port)
	{
		case PORTA : LOC_pin_value = GET_BIT(PINA_REG,copy_u8_pin); break;
		case PORTB : LOC_pin_value = GET_BIT(PINB_REG,copy_u8_pin); break;
		case PORTC : LOC_pin_value = GET_BIT(PINC_REG,copy_u8_pin); break;
		case PORTD : LOC_pin_value = GET_BIT(PIND_REG,copy_u8_pin); break;
	}
	return LOC_pin_value;
}
