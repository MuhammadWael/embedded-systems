/*
 * TIMER1_interface.h
 *
 * Created: 12/31/2022 4:46:19 PM
 *  Author: fathi
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_


#define  OC1A_PIN      1 
#define  OC1B_PIN      2
/*
function name: TIMER1_PWM_FastFreq_Init
function arguments: (uint8  pin,) pin --> oc1b (pD4) , oc1a (pD5)
function return: void
function description: init PWM fast  ferequancy  mode / non inverting / No prescaling
*/

void TIMER1_PWM_FastFreq_Init(u8 pin) ;

/*
function name: TIMER1_PWM_FastFreq_Duty_cycle
function arguments: (u8  duty ,  u8 pin ) 
function return: void
function description: configer OC1A Register 
*/
void TIMER1_PWM_FastFreq_Duty_cycle(u8 duty , u8 pin) ;


#endif /* TIMER1_INTERFACE_H_ */