/*
 * LCD_interface.c
 *
 * Created: 12/24/2022 7:55:31 PM
 *  Author: fathi
 */ 
#include "../header_files/LIB.h"
#include "../header_files/MATH.h"
#include "../header_files/LCD_interface.h"
#include "../header_files/LCD_CFG.h"
#include "../header_files/DIO_privte.h"
#include <avr/io.h>   // this file include all register addresses macros like DDRA
#define F_CPU 12000000UL // set the frequency of Microcontroller
#include <util/delay.h> // this header include all delay function like _delay_ms

/*****************************************************************************
* Function Name: LCD_init
* Purpose      : Init LCD in 4 bit mode, clear lcd and turn off cursor
* Parameters   : void
* Return value : void
*****************************************************************************/
void LCD_init(void){
	INIT_LCD_PIN;
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	
	LCD_write_command(0x2);
	LCD_write_command(0x28);
	LCD_write_command(0x08);
	LCD_write_command(0x1);
	LCD_write_command(0x6);
	LCD_write_command(0xC);
	_delay_ms(20);
	
}



/*****************************************************************************
* Function Name: LCD_write_command
* Purpose      : write command to lcd
* Parameters   : data: one of LCD commands
* Return value : void
*****************************************************************************/
void LCD_write_command(uint8_t data){ // 0x53
	RS(0);
	D7(GET_BIT(data,7)); // Data bit7  = D7
	D6(GET_BIT(data,6)); // Data bit6  = D6
	D5(GET_BIT(data,5)); // Data bit5  = D5
	D4(GET_BIT(data,4)); // Data bit4  = D4
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);

	D7(GET_BIT(data,3)); // Data bit3  = D7
	D6(GET_BIT(data,2)); // Data bit2  = D6
	D5(GET_BIT(data,1)); // Data bit1  = D5
	D4(GET_BIT(data,0)); // Data bit0  = D4
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
}




/*****************************************************************************
* Function Name: LCD_write_data
* Purpose      : write symbol on lcd
* Parameters   : data: Ascii value of specific symbol
* Return value : void
*****************************************************************************/
void LCD_write_data(uint8_t data){ // 0x53
	RS(1);
	D7(GET_BIT(data,7)); // Data bit7  = D7
	D6(GET_BIT(data,6)); // Data bit6  = D6
	D5(GET_BIT(data,5)); // Data bit5  = D5
	D4(GET_BIT(data,4)); // Data bit4  = D4
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);

	D7(GET_BIT(data,3)); // Data bit3  = D7
	D6(GET_BIT(data,2)); // Data bit2  = D6
	D5(GET_BIT(data,1)); // Data bit1  = D5
	D4(GET_BIT(data,0)); // Data bit0  = D4
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
}

void LCD_write_string(u8*data){
	
	
	u8 LOC_u8Increment=0 ;
	
	while(data[LOC_u8Increment]!='\0'){
		
		LCD_write_data(data[LOC_u8Increment]) ;
		
		LOC_u8Increment++ ;
		
		
	}
	
	
}
void LCD_write_number(u32 data){
	
	s8 i=0; 
	 u8 array[10] ;
	 
	 if(data==0){
		 
		 LCD_write_data('0') ;
		 return ;
	 }
	for(i=0; data!=0 ;i++){
		
		array[i]= data % 10 + 48 ;
		data /= 10 ;
	
	}
	i-- ;
	while(i >= 0){
		
		LCD_write_data(array[i]) ;
		i-- ;
		
	}
}