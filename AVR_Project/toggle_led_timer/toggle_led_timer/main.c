/*
 * toggle_led_timer.c
 *
 * Created: 9/29/2023 7:33:58 PM
 * Author : MW
 */ 

#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "ISR_Vector.h"
#include "TIMER_Config.h"
#include "TIMER_Interface.h"

void LED1()
{
	static u16 count = 0;
	if (count == 100)
	{
		DIO_void_Set_pin_val(PORTA,PIN1,HIGH);
	}
	else if (count == 200)
	{
		DIO_void_Set_pin_val(PORTA,PIN1,LOW);
	}
	count++;
}
void LED2()
{
	static u16 count = 0;
	if (count == 200)
	{
		DIO_void_Set_pin_val(PORTA,PIN2,HIGH);
	}
	else if (count == 400)
	{
		DIO_void_Set_pin_val(PORTA,PIN2,LOW);
	}
	count++;
}

int main(void)
{
	set_port_dir(PORTA,OUTPUT);
	TIMER0_CTC_Init();
    while (1) 
    {
		set_callback(CTC_MODE,LED1);
		set_callback(CTC_MODE,LED2);
    }
}

