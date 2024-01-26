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

#define CURSOR_ON LCD_send_command(0x0f);


void LCD_init(void);
void LCD_send_command(u8 command);
void LCD_send_data(u8 data);
void LCD_send_string(u8 string[]);
void LCD_send_string_wave_like(u8 string[]);
void LCD_send_number(u16 number);
void LCD_Position_Row_Col(u8 row ,u8 col);
void LCD_void_draw_new_data(u8 *data_array,u8 pattern);
#endif /* LCD_INTERFACE_H_ */