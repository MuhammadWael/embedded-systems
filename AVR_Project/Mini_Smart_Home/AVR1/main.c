/*
 * AVR1.c
 *
 * Created: 9/22/2023 8:56:12 PM
 * Author : Arabtech
 */ 

#include "MATH.h"
#include "STD_TYPE.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "LCD_config.h"
#include "LCD_Interface.h"
#include "EEPROM_Interface.h"
#include "ADC_interface.h"
#include "KEYPAD_Interface.h"
#define F_CPU 16000000ul
#include <util/delay.h>


int main(void)
{
	set_port_dir(PORTA,OUTPUT);
	set_port_dir(PORTB,INPUT);
	DIO_void_Set_pin_dir(PORTD,PIN7,OUTPUT);
	DIO_void_Set_pin_dir(PORTD,PIN6,OUTPUT);
    KEYPAD_init();
	LCD_init();
	/*save password*/
	u8 x = 0;
	u8 trials = 0;
	 
	for (u8 i = 0;i < 4;i++)
	{
		EEPROM_Send_Data(i,i);
	}
    while (1) 
    {
		u8 val=0xff ;
		u8 entered_password[4];
		for (u8 i = 0;i < 4;i++)
		{
			 do{
				 val=KEYPAD_get_key() ; 

				 
				 }while(val==0xff);
	       entered_password[i]=val ; 
		
		}
		/*Checking password*/
		u8 success =0;
		for (u8 i = 0;i < 4;i++)
		{
			if (EEPROM_Read_Data(i) != entered_password[i])
			{
				if (trials == 2)
				{
					LCD_send_string("Warning !");
					while(1){
					_delay_ms(100);
					DIO_void_Set_pin_val(PORTD,PIN7,HIGH);
					_delay_ms(100);
					DIO_void_Set_pin_val(PORTD,PIN7,LOW);
					DIO_void_Set_pin_val(PORTD,PIN7,HIGH);
					
					}
				}
				else {
				trials++;
				LCD_send_command(0x01);
				LCD_send_string("Wrong Password");
				LCD_Position_Row_Col(1,0);
				LCD_send_string("Trial");
				LCD_send_data(' ');
				LCD_send_number(trials);
				LCD_send_data(' ');
				LCD_send_string("of 3");
				
				}
			}
			else{
				success++;
			}
		}
		if (success == 3)
		{
			LCD_send_string("OK");
		}
		
    }
}



