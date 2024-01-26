/*
 * LCD_config.h
 *
 * Created: 7/7/2023 7:30:42 PM
 *  Author: Arabtech
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#if LCD_MODE == FOUR_BIT_MODE
#define LCD_DPORT PORTB
#define LCD_D4 PIN4
#define LCD_D5 PIN5
#define LCD_D6 PIN6
#define LCD_D7 PIN7
#endif 

/*LCD DATA PORT*/
#define LCD_DATA_PORT PORTA 

/*LCD CONTROL PINS*/
#define LCD_RS_PORT PORTB
#define LCD_RS_PIN PIN1

#define LCD_RW_PORT PORTB
#define LCD_RW_PIN PIN2

#define LCD_E_PORT PORTB
#define LCD_E_PIN PIN3




#endif /* LCD_CONFIG_H_ */