/*
 * LCD_Interface.h
 *
 * Created: 7/7/2023 7:29:30 PM
 *  Author: Arabtech
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define FOUR_BIT_MODE 4
#define EIGHT_BIT_MODE 8
#define LCD_MODE FOUR_BIT_MODE

void LCD_init(void);
void LCD_send_command(u8 command);
void LCD_send_data(u8 data);
void LCD_send_string(u8 string[]);
void LCD_send_number(u16 number);

#endif /* LCD_INTERFACE_H_ */