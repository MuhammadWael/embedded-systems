/*
 * Kernal.c
 *
 * Created: 9/30/2023 7:26:01 PM
 * Author : Arabtech
 */ 
#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "ISR_Vector.h"
#include "TIMER_Interface.h"
#include "Kernal_Interface.h"

void led1()
{
	TOGGLE_BIT(PORTA_REG,0);
}
void led2()
{
	TOGGLE_BIT(PORTA_REG,1);
}
void led3()
{
	TOGGLE_BIT(PORTA_REG,2);
}
int main(void)
{
	DIO_void_Set_pin_dir(PORTA,PIN0,OUTPUT);
	DIO_void_Set_pin_dir(PORTA,PIN1,OUTPUT);
	DIO_void_Set_pin_dir(PORTA,PIN2,OUTPUT);
	RTOS_void_CreateTask(0,100,led1);
	RTOS_void_CreateTask(1,200,led2);
	RTOS_void_CreateTask(2,300,led3);
	RTOS_void_Start();
    while (1) 
    {
    }
}

