/*
 * SPI_Interface.h
 *
 * Created: 8/26/2023 8:35:29 PM
 *  Author: Arabtech
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_MasterInit(void);
void SPI_SlaveInit(void);
void SPI_Master_Transmit(u8 data);
u8 SPI_Slave_Recive(void);



#endif /* SPI_INTERFACE_H_ */