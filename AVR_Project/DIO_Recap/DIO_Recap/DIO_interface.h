/*
 * DIO_interface.h
 *
 * Created: 6/24/2023 6:54:13 PM
 *  Author: Arabtech
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/* PINS*/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
/* Status*/
#define OUTPUT 1
#define INPUT 0
/* PORTS*/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
/*VALUE*/
#define HIGH 1
#define LOW 0

void DIO_void_set_pin_dir(u8 copy_u8_port ,u8 copy_u8_pin ,u8 copy_u8_status);

void DIO_void_set_pin_val(u8 copy_u8_port ,u8 copy_u8_pin ,u8 copy_u8_value);

u8 DIO_u8_get_pin_val(u8 copy_u8_port ,u8 copy_u8_pin);

#endif /* DIO_INTERFACE_H_ */