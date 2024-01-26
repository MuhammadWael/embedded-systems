/*
 * DIO_Interface.h
 *
 * Created: 5/26/2023 8:34:12 PM
 *  Author: Muhammad Wael
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/*Direction*/
#define OUTPUT 1
#define INPUT 0

/*ports*/
#define PORTA 0 
#define PORTB 1
#define PORTC 2
#define PORTD 3
/*value*/
#define HIGH 1
#define LOW 0
/*PINS*/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

void DIO_void_Set_pin_dir(u8 copy_u8_port, u8 copy_u8_pin,u8 copy_u8_dir); //set the pin's direction by taking the port and pin and direction in or out 
void DIO_void_Set_pin_val(u8 copy_u8_port, u8 copy_u8_pin,u8 copy_u8_val);// set the value of pin
void DIO_void_toggle_pin(u8 copy_u8_port, u8 copy_u8_pin);
u8 DIO_u8_Get_pin_val(u8 copy_u8_port, u8 copy_u8_pin);// get the value of the pin

void set_port_dir(u8 copy_u8_port,u8 copy_u8_dir);
void set_port_val(u8 copy_u8_port,u8 copy_u8_val);

#endif /* DIO_INTERFACE_H_ */