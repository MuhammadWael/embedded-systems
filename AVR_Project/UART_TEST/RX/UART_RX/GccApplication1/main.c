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
	DIO_void_Set_pin_dir(PORTA,PIN2,OUTPUT);
	DIO_void_Set_pin_dir(PORTD,PIN0,INPUT);
	u8 data ;
    while (1) 
    {
		data = USART_RX();
		if (data == 'M')
		{
			DIO_void_Set_pin_val(PORTA,PIN2,HIGH);
		}
		else
		{
			DIO_void_Set_pin_val(PORTA,PIN2,LOW);
		}
    }
}

