/*
 * EEPROM_Adresses.h
 *
 * Created: 9/8/2023 6:58:35 PM
 *  Author: Arabtech
 */ 


#ifndef EEPROM_ADRESSES_H_
#define EEPROM_ADRESSES_H_

#define EEAR_REG	*((volatile u16*)0x3E)
#define EEDR_REG	*((volatile u8*)0x3D)
#define EECR_REG	*((volatile u8*)0x3C)

#endif /* EEPROM_ADRESSES_H_ */