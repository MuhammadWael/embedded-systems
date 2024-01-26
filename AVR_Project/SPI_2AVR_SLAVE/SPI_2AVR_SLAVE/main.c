/*
 * SPI_2AVR_SLAVE.c
 *
 * Created: 8/26/2023 10:50:21 PM
 * Author : Arabtech
 */ 
#include "STD_TYPE.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "SPI_Interface.h"


int main(void)
{
    DIO_void_Set_pin_dir(PORTC,PIN2,OUTPUT);
    DIO_void_Set_pin_dir(PORTC,PIN7,OUTPUT);
	DIO_void_Set_pin_dir(PORTD,PIN3,OUTPUT);
	SPI_SlaveInit();
	u8 data = 0;
    while (1) 
    {		
			data = SPI_Slave_Recive();
			if(data = 'A')
			{
		    DIO_void_Set_pin_val(PORTC,PIN2,HIGH);
		    }
			if(data = 'B')
			{
				    DIO_void_Set_pin_val(PORTC,PIN7,HIGH);
		    }
			if(data = 'C')
			{
			    DIO_void_Set_pin_val(PORTD,PIN3,HIGH);
			}
    }
}

