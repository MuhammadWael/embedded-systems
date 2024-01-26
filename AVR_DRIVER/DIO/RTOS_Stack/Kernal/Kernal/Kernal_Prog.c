/*-
 * Kernal.c
 *
 * Created: 8/4/2023 8:42:46 PM
 *  Author: MW
 */ 
#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "ISR_Vector.h"
#include "TIMER_Interface.h"
#include "Kernal_Interface.h"

Task_T TaskArr[TASK_NUM] = {{0}};
	
static void RTOS_void_Schdular(void) //static to be accessed inside the file only
{
	static u16 counter = 0;
	u8 task_itr = 0;
	counter++;
	for (task_itr = 0; task_itr < TASK_NUM; task_itr++)
	{
		if (counter % TaskArr[task_itr].periodicity == 0)
		{
			
			TaskArr[task_itr].ptr_task();
		}
	}
}
void RTOS_void_Start(void)
{
	TIMER0_CTC_Init();
	set_callback(CTC_MODE,RTOS_void_Schdular); //we used callback function in order to use the static 
}
void RTOS_void_CreateTask(u8 priority, u16 periodicity, void (*ptr)(void))
{
	TaskArr[priority].periodicity = periodicity;
	TaskArr[priority].ptr_task = ptr;
}

