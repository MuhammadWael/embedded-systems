/*
 * SPI_Prog.c
 *
 * Created: 8/26/2023 8:34:48 PM
 *  Author: Arabtech
 */ 
#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"
#define F_CPU 16000000ul
#include <util/delay.h>

void SPI_MasterInit(void)
{
	//define MISO as input
	DIO_void_Set_pin_dir(PORTB,PIN6,INPUT);
	//define MOSI as output
	DIO_void_Set_pin_dir(PORTB,PIN5,OUTPUT);
	//SCK output
	DIO_void_Set_pin_dir(PORTB,PIN7,OUTPUT);
	//SS output
	DIO_void_Set_pin_dir(PORTB,PIN4,OUTPUT);
	//Enable SPI by SPE
	SET_BIT(SPCR_REG,6);
	//set MSTR to make it master 
	SET_BIT(SPCR_REG,4);
	//set DORD to make LSB first
	//SET_BIT(SPCR_REG,5);
	//Make in rising (leading and setup)
	//SET_BIT(SPCR_REG,3);
	//SET_BIT(SPCR_REG,2);
	//Clear SPR1 & SPR2 to use Focs/4
	//CLR_BIT(SPCR_REG,1);
	//CLR_BIT(SPCR_REG,0);
}
void SPI_SlaveInit(void)
{
	//define MISO as output
//	DIO_void_Set_pin_dir(PORTB,PIN6,OUTPUT);
	//define MOSI as input
//	DIO_void_Set_pin_dir(PORTB,PIN5,INPUT);
	//SCK input
	//DIO_void_Set_pin_dir(PORTB,PIN7,INPUT);
	//SS  input
	DIO_void_Set_pin_dir(PORTB,PIN4,INPUT);
	//Enable SPI by SPE
	SET_BIT(SPCR_REG,6);
	//set DORD to make LSB first
	//SET_BIT(SPCR_REG,5);
	//clear MSTR to make it slave
	//CLR_BIT(SPCR_REG,4);
	//Make in rising (leading and setup)
	//SET_BIT(SPCR_REG,3);
	//SET_BIT(SPCR_REG,2);
	//Clear SPR1 & SPR2 &SPI2X to use Focs/4
	//CLR_BIT(SPCR_REG,1);
	//CLR_BIT(SPCR_REG,0);	
	//CLR_BIT(SPSR_REG,0);
}
void SPI_Master_Transmit(u8 data)
{
	SPDR_REG = data;
	while(GET_BIT(SPSR_REG,7) == 0);
	_delay_ms(500);
}
u8 SPI_Slave_Recive(void)
{
	while(GET_BIT(SPSR_REG,7) == 0);
	return SPDR_REG ;
}