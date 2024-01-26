/*
 * USART_Prog.c
 *
 * Created: 8/19/2023 9:42:21 PM
 *  Author: Arabtech
 */ 
#include "STD_TYPE.h"
#include "MATH.h"
#include "USART_Private.h"
#include "USART_Interface.h"

void USART_Init(void)
{
	UBRRL_REG = 103; // for 16MHZ,96000 bps
	SET_BIT(USCRB_REG,TXEN);
	SET_BIT(USCRB_REG,RXEN);
	SET_BIT(USCRB_REG,RXCIE);
	SET_BIT(USCRB_REG,TXCIE);
}
u8 USART_RX(void)
{
	while (GET_BIT(UCSRA_REG,RXC) == 0);
	return UDR_REG;
}
void USART_TX(u8 data)
{
	UDR_REG = data;
	while (GET_BIT(UCSRA_REG,TXC) == 0);	
}