/*
 * KEYPAD_Prog.c
 *
 * Created: 7/15/2023 6:37:16 PM
 *  Author: Arabtech
 */ 

#include "MATH.h"
#include "STD_TYPE.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "KEYPAD_Config.h"
#include "KEYPAD_Interface.h"

u8 KEYPAD_DISPLAY[4][4] = {{'1','2','3','A'},
						   {'4','5','6','B'},
						   {'7','8','9','C'},
						   {'*','0','#','D'},
						  };
void KEYPAD_init(void)
{
	u8 KEYPAD_ROWS[4] = {KEYPAD_ROW0,KEYPAD_ROW1,KEYPAD_ROW2,KEYPAD_ROW3};
	u8 KEYPAD_COLS[4] = {KEYPAD_COL0,KEYPAD_COL1,KEYPAD_COL2,KEYPAD_COL3};
	//activate pull up resistors
	for (u8 itr = 0;itr < 4;itr++)
	{
		DIO_void_Set_pin_dir(KEYPAD_PORT,KEYPAD_ROWS[itr],INPUT);
		DIO_void_Set_pin_val(KEYPAD_PORT,KEYPAD_ROWS[itr],HIGH);//to activate pull up resistors
	}
	for (u8 itr = 0;itr < 4;itr++)
	{
		DIO_void_Set_pin_dir(KEYPAD_PORT,KEYPAD_COLS[itr],OUTPUT);
		DIO_void_Set_pin_val(KEYPAD_PORT,KEYPAD_COLS[itr],HIGH);
	}
	
}
u8 KEYPAD_get_key(void)
{
	u8 KEYPAD_ROWS[4] = {KEYPAD_ROW0,KEYPAD_ROW1,KEYPAD_ROW2,KEYPAD_ROW3};
	u8 KEYPAD_COLS[4] = {KEYPAD_COL0,KEYPAD_COL1,KEYPAD_COL2,KEYPAD_COL3};
	u8 val=0xff;
	for (u8 col_index = 0;col_index < 4;col_index++)
	{
		DIO_void_Set_pin_val(KEYPAD_PORT,KEYPAD_COLS[col_index],LOW);
		for (u8 row_index = 0;row_index < 4;row_index++)
		{
			if (DIO_u8_Get_pin_val(KEYPAD_PORT,KEYPAD_ROWS[row_index]) == 0)
			{
				while (DIO_u8_Get_pin_val(KEYPAD_PORT,KEYPAD_ROWS[row_index]) == 0);
				val = KEYPAD_DISPLAY[row_index][col_index];
				return  val;
			}
		}
		DIO_void_Set_pin_val(KEYPAD_PORT,KEYPAD_COLS[col_index],HIGH);
	}
	return val;
}