/*
 * SWITCH_Prog.c
 *
 * Created: 7/7/2023 3:51:06 AM
 *  Author: Arabtech
 */ 
#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Interface.h"
#include "SWITCH_Interface.h"

u8 IS_PRESSED(u8 copy_u8_port,u8 copy_u8_pin)
{
	if (DIO_u8_Get_pin_val(copy_u8_port,copy_u8_pin) == HIGH)
	{
		return HIGH;
	}
	else
	{
		return LOW;
	}
}