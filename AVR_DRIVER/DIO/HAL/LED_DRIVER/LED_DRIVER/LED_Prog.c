/*
 * LED_Prog.c
 *
 * Created: 7/7/2023 3:23:30 AM
 *  Author: Muhmmad Wael
 */ 
#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "LED_interface.h"

void LED_ON(u8 copy_u8_port,u8 copy_u8_pin)
{
	DIO_void_Set_pin_dir(copy_u8_port,copy_u8_pin,OUTPUT);
	DIO_void_Set_pin_val(copy_u8_port,copy_u8_pin,HIGH);
}
void LED_OFF(u8 copy_u8_port,u8 copy_u8_pin)
{
	DIO_void_Set_pin_dir(copy_u8_port,copy_u8_pin,OUTPUT);
	DIO_void_Set_pin_val(copy_u8_port,copy_u8_pin,LOW);	
}
void LED_TOGGLE(u8 copy_u8_port,u8 copy_u8_pin)
{
	u8 led_state = DIO_u8_Get_pin_val(copy_u8_port,copy_u8_pin);
	if (led_state == ON)
	{
		DIO_void_Set_pin_val(copy_u8_port,copy_u8_pin,LOW);	
	}
	if (led_state == OFF)
	{
		DIO_void_Set_pin_val(copy_u8_port,copy_u8_pin,HIGH);
	}
}