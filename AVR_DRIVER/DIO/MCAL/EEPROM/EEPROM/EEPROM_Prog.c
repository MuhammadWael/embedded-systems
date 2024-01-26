/*
 * EEPROM_Prog.c
 *
 * Created: 9/8/2023 6:57:32 PM
 *  Author: Arabtech
 */ 

#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "EEPROM_Adresses.h"
#include "EEPROM_Interface.h"

void EEPROM_Send_Data(u8 data,u16 address)
{
	while(GET_BIT(EECR_REG,1) == 1);
	EEAR_REG = address;
	EEDR_REG = data;
	SET_BIT(EECR_REG,2);
	SET_BIT(EECR_REG,1);
}
u8 EEPROM_Read_Data(u16 address)
{
	while(GET_BIT(EECR_REG,1) == 1);
	EEAR_REG = address;
	SET_BIT(EECR_REG,0);	
}