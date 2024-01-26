/*
 * WDT_Prog.c
 *
 * Created: 8/18/2023 7:30:08 PM
 *  Author: Arabtech
 */ 

#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_Adress.h"
#include "DIO_Interface.h"
#include "ISR_Vector.h"

void WDT_Start(u8 time_out)
{
	SET_BIT(WDTCR_REG,WDE_bit);// Enable NOT
	/* configure WDT time out*/
	WDTCR_REG |= time_out;
}

void WDT_Stop(void)
{
	WDTCR_REG |= (1<<WDTOE) | (1<<WDE);// logical one to WDTOE & WDE
	WDTCR_REG = 0x00; // Turn off WDT
}
