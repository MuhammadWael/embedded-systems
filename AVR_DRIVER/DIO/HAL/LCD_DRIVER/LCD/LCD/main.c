/*
 * LCD.c
 *
 * Created: 7/7/2023 7:27:59 PM
 * Author : Arabtech
 */ 

#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Interface.h"
#include "LCD_config.h"
#include "LCD_Interface.h"
#define F_CPU 16000000ul
#include <util/delay.h>

int main(void)
{
    /* init LCD pins */
	set_port_dir(LCD_DATA_PORT,OUTPUT);
	DIO_void_Set_pin_dir(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
	DIO_void_Set_pin_dir(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);
	DIO_void_Set_pin_dir(LCD_E_PORT,LCD_E_PIN,OUTPUT);
	LCD_init();
	LCD_send_string("Muhammad Wael");
    while (1) 
    {
    }
}

