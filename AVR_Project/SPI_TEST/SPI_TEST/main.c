/*
 * SPI_TEST.c
 *
 * Created: 8/26/2023 9:22:46 PM
 * Author : Arabtech
 */ 

#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "SPI_Interface.h"


int main(void)
{
   	DIO_void_Set_pin_dir(PORTA,PIN0,OUTPUT);
   	SPI_SlaveInit();
   	u8 data = 0;
   	while (1)
   	{
	   	data = SPI_Slave_Recive();
	   	if (data == 'F')
	   	{
		   	DIO_void_Set_pin_val(PORTA,PIN0,HIGH);
	   	}
	   	
   	}
}

