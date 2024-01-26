#ifndef KERNAL_INTERFACE_H_
#define KERNAL_INTERFACE_H_

#define TASK_NUM 3
void RTOS_void_Start(void);
void RTOS_void_CreateTask(u8 priority, u16 periodicity, void (*ptr_task)(void));
typedef struct{
	void (*ptr_task)(void);
	u16 periodicity;
}Task_T;

#endif