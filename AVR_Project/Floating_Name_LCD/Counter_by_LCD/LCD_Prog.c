/*
 * LCD_Prog.c
 *
 * Created: 7/7/2023 7:30:20 PM
 *  Author: MW
 */ 
#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "LCD_config.h"
#include "LCD_Interface.h"
#define F_CPU 16000000ul
#include <util/delay.h>


static void LCD_Send_Enable_Pulse(void) // static to be seen by this file only
{
	DIO_void_Set_pin_val(LCD_E_PORT,LCD_E_PIN,HIGH);
	_delay_ms(2);
	DIO_void_Set_pin_val(LCD_E_PORT,LCD_E_PIN,LOW);
}
static void SH_Data(u8 data)//send half data 
{
	u8 LCD_PINS[4] = {LCD_D4,LCD_D5,LCD_D6,LCD_D7};
	for (u8 itr = 0;itr < 4;itr++)
	{
		DIO_void_Set_pin_val(LCD_DPORT,LCD_PINS[itr],GET_BIT(data,itr));
	}
}

void LCD_init(void)
{	
	_delay_ms(40);
	#if LCD_MODE == EIGHT_BIT_MODE
		//wait for more than 30 sec.
		//send function set
		LCD_send_command(0b00111100);//first 2 digits already done in send command function
		LCD_send_command(0b00001100);
		/*clear LCD*/
		LCD_send_command(0x01);
	#elif LCD_MODE == FOUR_BIT_MODE
		//send function set
		
		SH_Data(0b0010);
		LCD_Send_Enable_Pulse();
		SH_Data(0b0010);
		LCD_Send_Enable_Pulse();
		SH_Data(0b1100);
		LCD_Send_Enable_Pulse();
		//Display ON/OFF Controll
		LCD_send_command(0b00001100);
		//Display Clear
		LCD_send_command(0x01);		
		#endif
}
void LCD_send_command(u8 command)
{
	/* adjust controll signals to send command */
		/*set RS --> 0 to send command*/
	DIO_void_Set_pin_val(LCD_RS_PORT,LCD_RS_PIN,LOW);
	/*set RW --> 0 to wright */
	DIO_void_Set_pin_val(LCD_RW_PORT,LCD_RW_PIN,LOW);	

	#if LCD_MODE == EIGHT_BIT_MODE
	//send enable pulse
	set_port_val(LCD_DATA_PORT,command);
	LCD_Send_Enable_Pulse();
	#elif LCD_MODE == FOUR_BIT_MODE
	SH_Data(command>>4);//SEND MOST SIGNIFICANT BIT
	LCD_Send_Enable_Pulse();//SEND LEAST SIGNIFICANT BIT 
	SH_Data(command);
	LCD_Send_Enable_Pulse();//SEND LEAST SIGNIFICANT BIT
	#endif
	
}
void LCD_send_data(u8 data)
{
	/*set RS --> 1 to send command*/
	DIO_void_Set_pin_val(LCD_RS_PORT,LCD_RS_PIN,HIGH);
	/*set RW --> 0 to write */
	DIO_void_Set_pin_val(LCD_RW_PORT,LCD_RW_PIN,LOW);
	#if LCD_MODE == EIGHT_BIT_MODE
	//send enable pulse
	set_port_val(LCD_DATA_PORT,data);
	LCD_Send_Enable_Pulse();
	#elif LCD_MODE == FOUR_BIT_MODE
	SH_Data(data>>4);//SEND MOST SIGNIFICANT BIT
	LCD_Send_Enable_Pulse();//SEND LEAST SIGNIFICANT BIT
	SH_Data(data);
	LCD_Send_Enable_Pulse();//SEND LEAST SIGNIFICANT BIT
	#endif
}

void LCD_send_string(u8 string[])
{
	u8 itr = 0;
	while(string[itr] != '\0')
	{
		LCD_send_data(string[itr]);
		itr++;
	}
}

void LCD_send_number(s16 number)
{
		u8 itr = 0,remainder = 0,length = 0;
		if (number == 0)
		{
			LCD_send_data('0');
			return;
		}
		else if (number < 0)
		{
			number *=-1;
			LCD_send_data('-');
		}
		u16 temp = number;
		while (temp != 0)
		{
			temp /= 10;
			length++;
		}
		u8 str[length];
		for(itr = 0;itr < length;itr++)
		{
			remainder = number % 10;
			number /= 10;
			str[length - (itr + 1)] = remainder +'0';
		}
		str[length] = '/0';
		for (itr = 0;itr < length;itr++)
		{
			LCD_send_data(str[itr]);
		}
}

void LCD_Position_Row_Col(u8 row ,u8 col)
{
	u8 ddram_address = 0;
	//LCD_send_command(0x3f); // for 2 line display 
	if (row == 0)
	{
		ddram_address = col;
	}
	else if (row == 1)
	{
		ddram_address = col + 0x40;
	}
	SET_BIT(ddram_address,7);
	LCD_send_command(ddram_address);
}
void LCD_send_string_wave_like(u8 string[])
{
	u8 itr = 0;
	u8 i = 0 ;
	u8 itr2 = itr + 1;
	while(string[itr] != '\0' )
	{
		LCD_Position_Row_Col(i,0);
		LCD_send_data(string[itr]);
		LCD_Position_Row_Col(++i,1);
		LCD_send_data(string[itr++]);
		itr++;
	}
}
void LCD_void_draw_new_data(u8 *data_array,u8 pattern)
{
	u8 CGRAM_address = pattern*8;
	u8 i = 0;
	CLR_BIT(CGRAM_address,7);
	SET_BIT(CGRAM_address,6);
	LCD_send_command(CGRAM_address);
	for (i = 0;i < 8;i++)
	{
		LCD_send_data(data_array[i]);
	}
}