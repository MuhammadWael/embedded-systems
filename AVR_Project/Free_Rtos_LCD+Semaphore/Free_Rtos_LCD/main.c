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
#include "LCD_config.h"
#include "LCD_Interface.h"
#include "Free_RTOS/FreeRTOS.h"
#include "Free_RTOS/FreeRTOSConfig.h"
#include "Free_RTOS/task.h"
#include "Free_RTOS/semphr.h"
#define F_CPU 16000000
#include <util/delay.h>

xSemaphoreHandle LCD_SEM;


void task1(){
	u8 state = 0;
	while(1)
	{	
		state = xSemaphoreTake(LCD_SEM,100);//time in waiting is 10
		//when returning 1 means it's avalable but when zero it hold in waiting for 10
		if (state == 1)
		{
			LCD_send_string("First");
			xSemaphoreGive(LCD_SEM);
		}
		vTaskDelay(2000);
		 // the task will be in bolckage state for 150 ticks
	}
}

void task2(){
	u8 state =0;
	while(1)
	{
		state = xSemaphoreTake(LCD_SEM,100);//time in waiting is 10
		//when returning 1 means it's avalable but when zero it hold in waiting for 10
		if (state == 1)
		{
			LCD_send_string("Second");
			xSemaphoreGive(LCD_SEM);
		}
		vTaskDelay(2000);
	}
}

/*void task3(){
	while(1)
	{
		LCD_send_string("EF");
		vTaskDelay(1500); //block it after it finishies
		LCD_send_command(0x01);
	}
}*/

int main (void)
{
	vSemaphoreCreateBinary(LCD_SEM);
	set_port_dir(PORTA,OUTPUT);
	LCD_init();
	xTaskCreate(task1,"task1",100,NULL,2,NULL);
	xTaskCreate(task2,"task2",100,NULL,1,NULL);
	//xTaskCreate(task3,"task3",100,NULL,1,NULL);
	vTaskStartScheduler();

	
	//while(1){} MUST BE DELETED
		
}