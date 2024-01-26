/*
 * EEPROM_Interface.h
 *
 * Created: 9/8/2023 6:59:26 PM
 *  Author: Arabtech
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_Send_Data(u8 data,u16 address);
u8 EEPROM_Read_Data(u16 address);

#endif /* EEPROM_INTERFACE_H_ */