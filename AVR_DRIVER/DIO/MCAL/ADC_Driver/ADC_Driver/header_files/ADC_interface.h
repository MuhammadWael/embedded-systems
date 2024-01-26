/*
 * ADC_interface.h
 *
 * Created: 1/1/2023 9:46:29 AM
 *  Author: fathi
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#define  ADC0              0x00
#define  ADC1              0x01
#define  ADC2              0x02
#define  ADC3              0x03
#define  ADC4              0x04
#define  ADC5              0x05
#define  ADC6              0x06
#define  ADC7              0x07

/*
function name: ADC_Init
function arguments: (u8 channal) // channal -->ADC pin in porta 
function return: void
function description: Init ADC & ADC PIN 
*/

void ADC_Init() ;

/*
function name: ADC_Read
function arguments: (u8 channal) // channal -->ADC pin in porta
function return: u16
function description: return value in ADC_REG -->(data conversion)
*/
//u16 ADC_Read(void );
u16 ADC_Read( u8 channal ) ;
void ADC_StartConversion(u8 channal);

void ADC_SetCallBack(void(*ptr)(void)) ;


#endif /* ADC_INTERFACE_H_ */