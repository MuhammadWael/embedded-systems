/*
 * ADC_LM35.c
 *
 * Created: 7/27/2023 8:35:00 PM
 * Author : Arabtech
 */ 
#include "MATH.h"
#include "STD_TYPE.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "ADC_interface.h"
#include "LCD_config.h"
#include "LCD_Interface.h"
#define F_CPU 16000000ul
#include <util/delay.h>
int main(void)
{
	//set_port_dir(LCD_DATA_PORT,OUTPUT);
	DIO_void_Set_pin_dir(LCD_RS_PORT,LCD_RS_PIN,OUTPUT) ;
	DIO_void_Set_pin_dir(LCD_RW_PORT,LCD_RW_PIN,OUTPUT) ;
	DIO_void_Set_pin_dir(LCD_E_PORT,LCD_E_PIN,OUTPUT) ;
	LCD_init();
	ADC_Init();
	s32 ADC_READ;
	DIO_void_Set_pin_dir(PORTA,PIN0,OUTPUT);
	DIO_void_Set_pin_dir(PORTC,PIN1,OUTPUT);
	DIO_void_Set_pin_dir(PORTC,PIN0,OUTPUT);
	
    while (1) 
    {	
		ADC_READ = ADC_Read(ADC0);
		ADC_READ = ADC_READ*500/1023;
		LCD_send_command(0x80);
		LCD_send_string("Temp is :");
		LCD_send_number(ADC_READ);
		LCD_send_string("'C"); 
		if (ADC_READ >= 35)
		{
			DIO_void_Set_pin_val(PORTC,PIN1,LOW);
			DIO_void_Set_pin_val(PORTC,PIN0,HIGH);
		}
		else
		{
			DIO_void_Set_pin_val(PORTC,PIN0,LOW);
			DIO_void_Set_pin_val(PORTC,PIN1,HIGH);
		}
    }
}

