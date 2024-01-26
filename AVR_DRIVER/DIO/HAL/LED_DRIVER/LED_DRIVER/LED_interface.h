/*
 * led.h
 *
 * Created: 7/7/2023 3:05:01 AM
 *  Author: Arabtech
 */ 


#ifndef LED_H_
#define LED_H_

#define ON 1
#define OFF 0


void LED_ON(u8 copy_u8_port,u8 copy_u8_pin);
void LED_OFF(u8 copy_u8_port,u8 copy_u8_pin);
void LED_TOGGLE(u8 copy_u8_port,u8 copy_u8_pin);

#endif /* LED_H_ */