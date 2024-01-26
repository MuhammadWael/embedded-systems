/*
 * Counter_by_LCD.c
 *
 * Created: 7/8/2023 9:35:22 PM
 * Author : Arabtech
 */ 

 #include "STD_TYPE.h"
 #include "MATH.h"
 #include "DIO_Interface.h"
 #include "LCD_config.h"
 #include "LCD_Interface.h"
 #include "SWITCH_Interface.h"
 #define F_CPU 16000000UL
 #include <util/delay.h>
 
int main(void)
{
	set_port_dir(LCD_DATA_PORT,OUTPUT);
	DIO_void_Set_pin_dir(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
	DIO_void_Set_pin_dir(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);
	DIO_void_Set_pin_dir(LCD_E_PORT,LCD_E_PIN,OUTPUT);
	DIO_void_Set_pin_dir(PORTD,PIN6,INPUT);
	LCD_init();
	s32 count = 0;
	u8 flag = 0;
    while (1) 
    {
		
			LCD_send_command(0x80);
			LCD_send_number(count);
			if (IS_PRESSED(PORTD,PIN2))
			{
				while(IS_PRESSED(PORTD,PIN2));
				LCD_send_command(0x01);
				count++;
			}
			if (IS_PRESSED(PORTD,PIN6))
			{
				while(IS_PRESSED(PORTD,PIN6));
				LCD_send_command(0x01);
				count--;
			}
			if (IS_PRESSED(PORTB,PIN0))
			{
				while(IS_PRESSED(PORTB,PIN0));
				LCD_send_command(0x01);
				count = 0;
			}
    }
}

