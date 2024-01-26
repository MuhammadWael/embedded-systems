
/*
 * MASTER_SPI.c
 *
 * Created: 8/26/2023 9:27:50 PM
 * Author : Arabtech
 */ 

#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "SPI_Interface.h"
#define F_CPU 16000000ul
#include <util/delay.h>

int main(void)
{
	SPI_MasterInit();
	_delay_ms(200);
	while(1)
	{
		SPI_Master_Transmit('F');	
	}
}

