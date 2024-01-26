/*
 * LCD_CFG.h
 *
 * Created: 12/24/2022 10:06:38 PM
 *  Author: fathi
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

 /*MAKE PB2 to PB7 output */
#define INIT_LCD_PIN  DIO_u8DDRB_REG |= 0b11111100; 

/* conncect pins in lcd to pins in mc  */
#define EN(x) if(x == 1) SET_BIT(DIO_u8PORTB_REG,2); else CLR_BIT(DIO_u8PORTB_REG,2);
#define RS(x) if(x == 1) SET_BIT(DIO_u8PORTB_REG,3); else CLR_BIT(DIO_u8PORTB_REG,3);
#define D7(x) if(x == 1) SET_BIT(DIO_u8PORTB_REG,7); else CLR_BIT(DIO_u8PORTB_REG,7);
#define D6(x) if(x == 1) SET_BIT(DIO_u8PORTB_REG,6); else CLR_BIT(DIO_u8PORTB_REG,6);
#define D5(x) if(x == 1) SET_BIT(DIO_u8PORTB_REG,5); else CLR_BIT(DIO_u8PORTB_REG,5);
#define D4(x) if(x == 1) SET_BIT(DIO_u8PORTB_REG,4); else CLR_BIT(DIO_u8PORTB_REG,4);



#endif /* LCD_CFG_H_ */