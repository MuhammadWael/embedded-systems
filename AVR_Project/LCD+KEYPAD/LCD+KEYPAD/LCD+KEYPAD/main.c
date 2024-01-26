/*
 * Keypad_driver.c
 *
 * Created: 6/16/2023 11:31:13 AM
 * Author : AMIT
 */ 

#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_interface.h"
#include "KEYPAD_Config.h"
#include "KEYPAD_Interface.h"
#include "LCD_Config.h" 
#include "LCD_interface.h" 


int main(void)
{
	
	u8 key_val=0 ;
	  /* INIT Lcd pins  */
	  set_port_dir(LCD_DPORT,0x0f) ;
	  DIO_void_Set_pin_dir(LCD_RS_PORT,LCD_RS_PIN,OUTPUT) ;
	  DIO_void_Set_pin_dir(LCD_RW_PORT,LCD_RW_PIN,OUTPUT) ;
	  DIO_void_Set_pin_dir(LCD_E_PORT,LCD_E_PIN,OUTPUT) ;
	  LCD_init() ;
	  KEYPAD_init() ;
	  LCD_send_string("NONE");
    while (1) 
    {
		
		
		do{
			key_val=KEYPAD_get_key() ;
		}while(key_val==0) ;
			LCD_send_command(0x01);
			LCD_send_command(0x80);
			LCD_send_data(key_val) ;
		
		
    }
}

