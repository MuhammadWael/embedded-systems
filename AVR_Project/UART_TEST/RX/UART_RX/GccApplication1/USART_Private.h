/*
 * USART_Private.h
 *
 * Created: 8/19/2023 9:37:31 PM
 *  Author: Arabtech
 */ 


#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#define UDR_REG		*((volatile u8*)0x2C)
#define UCSRA_REG	*((volatile u8*)0x2B)
#define USCRB_REG	*((volatile u8*)0x2A)
#define UBRRL_REG	*((volatile u8*)0x29)
#define UDRE		5
#define RXEN		4 
#define TXEN		3
#define RXCIE		7
#define TXCIE		6
#define TXC			6
#define RXC			7


#endif /* USART_PRIVATE_H_ */