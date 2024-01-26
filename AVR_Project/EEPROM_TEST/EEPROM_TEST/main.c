/*
 * EEPROM_TEST.c
 *
 * Created: 9/8/2023 7:43:37 PM
 * Author : Arabtech
 */ 

#include "STD_TYPE.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "EEPROM_Adresses.h"
#include "EEPROM_Interface.h"
#include "LCD_config.h"
#include "LCD_Interface.h"

int main(void)
{
	set_port_dir(PORTA,OUTPUT);
	set_port_dir(PORTB,OUTPUT);
	LCD_init();
	
    EEPROM_Send_Data('m',0x15);
	LCD_send_data(EEPROM_Read_Data(0x15));
    while (1) 
    {
		
    }
}

