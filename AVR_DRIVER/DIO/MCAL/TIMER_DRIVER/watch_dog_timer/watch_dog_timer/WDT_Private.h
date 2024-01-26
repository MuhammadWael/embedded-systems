/*
 * WDT_Private.h
 *
 * Created: 8/18/2023 7:28:50 PM
 *  Author: Arabtech
 */ 


#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_

#define WDTCR_REG *((volatile u8*)0x41)

#define WDE_bit		3
#define WDTOE		4
#define WDT_TIME_OUT_16_3ms 0x00
#define WDT_TIME_OUT_32_5ms 0x01
#define	WDT_TIME_OUT_65ms	0x02
#define	WDT_TIME_OUT_0_13s	0x03
#define	WDT_TIME_OUT_0_26s	0x04
#define	WDT_TIME_OUT_0_52s	0x05
#define	WDT_TIME_OUT_1s		0x06
#define	WDT_TIME_OUT_2_1s	0x07
							



#endif /* WDT_PRIVATE_H_ */