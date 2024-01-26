/*
 * main.c
 *
 * Created: 10/7/2023 8:01:35 PM
 *  Author: Arabtech
 */ 
#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "Free_RTOS/FreeRTOS.h"
#include "Free_RTOS/FreeRTOSConfig.h"
#include "Free_RTOS/task.h"
#define F_CPU 16000000
#include <util/delay.h>

void LED1(){
	while(1)
	{
		SET_BIT(PORTA_REG,0);
		vTaskDelay(500);	
		CLR_BIT(PORTA_REG,0);
		vTaskDelay(500);
	}
}

void LED2(){
	while(1)
	{
		SET_BIT(PORTA_REG,1);
		vTaskDelay(1000); //block it after it finishies 
		CLR_BIT(PORTA_REG,1);
		vTaskDelay(1000);
	}
}

void LED3(){
	while(1)
	{
		SET_BIT(PORTA_REG,2);
		vTaskDelay(1500); //block it after it finishies
		CLR_BIT(PORTA_REG,2);
		vTaskDelay(1500);
	}
}

int main (void)
{
	
	DIO_void_Set_pin_dir(PORTA,PIN0,OUTPUT);
	DIO_void_Set_pin_dir(PORTA,PIN1,OUTPUT);
	DIO_void_Set_pin_dir(PORTA,PIN2,OUTPUT);
	xTaskCreate(LED1,"LED1",100,NULL,0,NULL);
	xTaskCreate(LED2,"LED2",100,NULL,0,NULL);
	xTaskCreate(LED3,"LED3",100,NULL,0,NULL);
	vTaskStartScheduler();

	
	//while(1){} MUST BE DELETED
		
}