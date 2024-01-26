/*
 * LCD_Prog.c
 *
 * Created: 7/7/2023 7:30:20 PM
 *  Author: MW
 */ 
#include "STD_TYPE.h"
#include "MATH.h"
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