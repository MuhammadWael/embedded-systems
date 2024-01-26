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
	LCD_Position_Row_Col(1,4);
	u8 data[8] = {0b00000,0b01010,0b10001,0b10010,0b10001,0b11111,0b00000,0b00000};
	LCD_void_draw_new_data(data,0);
    while (1) 
    {	
			
	}
}
