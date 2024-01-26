/*
 * UART_TX.c
 *
 * Created: 8/19/2023 10:19:33 PM
 * Author : Arabtech
 */ 
 
 #include "STD_TYPE.h"
 #include "MATH.h"
 #include "USART_Private.h"
 #include "USART_Interface.h"
 #include "DIO_Interface.h"

int main(void)
{
	USART_Init();
	DIO_void_Set_pin_dir(PORTD,PIN1,OUTPUT);
	
    while (1) 
    {
		USART_TX('F');
    }
}

