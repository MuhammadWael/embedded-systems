/*
 * LCD_interface.h
 *
 * Created: 12/24/2022 7:55:13 PM
 *  Author: fathi
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_





void LCD_init(void);
void LCD_write_command(u8 data);
void LCD_write_data(u8 data);
void LCD_write_string(u8*data);
void LCD_write_number(u32 data);



#endif /* LCD_INTERFACE_H_ */