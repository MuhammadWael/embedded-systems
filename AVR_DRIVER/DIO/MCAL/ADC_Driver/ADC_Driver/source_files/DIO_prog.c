/*
 * DIO_prog.c
 *
 * Created: 12/22/2022 8:00:08 PM
 *  Author: fathi
 */ 
#include "../header_files/LIB.h"
#include "../header_files/MATH.h"
#include "../header_files/DIO_privte.h"
#include "../header_files/DIO_prog.h"



/* I/O PORT */
extern void DIO_vid_SetPortValue(u8 u8port,u8 u8value) {


	switch (u8port){

		/* Check on the Required PORT Number */
		case   DIO_u8PORTA: DIO_u8PORTA_REG =u8value ; break ;
		case   DIO_u8PORTB: DIO_u8PORTB_REG =u8value ; break ;
		case   DIO_u8PORTC: DIO_u8PORTC_REG =u8value ; break ;
		case   DIO_u8PORTD: DIO_u8PORTD_REG =u8value ; break ;

		default : /* worng port*/  break ;

	}

}
/* I/O POTR */
extern void DIO_vid_SetPortDirection(u8 u8port,u8 u8Dir) {


	switch (u8port){

		/* Check on the Required PORT Number */
		case DIO_u8PORTA:  DIO_u8DDRA_REG = u8Dir; break ;
		case DIO_u8PORTB:  DIO_u8DDRB_REG = u8Dir; break ;
		case DIO_u8PORTC:  DIO_u8DDRC_REG = u8Dir; break ;
		case DIO_u8PORTD:  DIO_u8DDRD_REG = u8Dir; break ;

		default : /* worng port*/  break ;

	}


}

/* set pin value */
extern void DIO_vid_SetPintValue(u8 u8port, u8 u8pin ,u8 u8value) {



	if (u8value==HIGH){


		switch (u8port){

			case   DIO_u8PORTA: SET_BIT( DIO_u8PORTA_REG,u8pin) ; break ;
			case   DIO_u8PORTB: SET_BIT( DIO_u8PORTB_REG,u8pin) ; break ;
			case   DIO_u8PORTC: SET_BIT( DIO_u8PORTC_REG,u8pin) ; break ;
			case   DIO_u8PORTD: SET_BIT( DIO_u8PORTD_REG,u8pin) ; break ;

			default : /* worng port */ break;
		}
	}
	else if (u8value==LOW){

		switch (u8port){
			case  DIO_u8PORTA: CLR_BIT( DIO_u8PORTA_REG,u8pin) ; break ;
			case   DIO_u8PORTB: CLR_BIT( DIO_u8PORTB_REG,u8pin) ; break ;
			case   DIO_u8PORTC: CLR_BIT( DIO_u8PORTC_REG,u8pin) ; break ;
			case   DIO_u8PORTD: CLR_BIT( DIO_u8PORTD_REG,u8pin) ; break ;

		}
	}
	else {
		/* Do nothing, Wrong value to set */

	}






}

/* set pin direction */
extern void DIO_vid_SetPintDirection(u8 u8port,u8 u8pin,u8  u8dir) {



	if (u8dir==OUTPUT){


		switch (u8port){

			case   DIO_u8PORTA: SET_BIT( DIO_u8DDRA_REG,u8pin) ; break ;
			case   DIO_u8PORTB: SET_BIT( DIO_u8DDRB_REG,u8pin) ; break ;
			case   DIO_u8PORTC: SET_BIT( DIO_u8DDRC_REG,u8pin) ; break ;
			case   DIO_u8PORTD: SET_BIT( DIO_u8DDRD_REG,u8pin) ; break ;

			default : /* worng port */ break;
		}
	}
	else  if (u8dir == INPUT){

		switch (u8port){
			case   DIO_u8PORTA: CLR_BIT( DIO_u8DDRA_REG,u8pin) ; break ;
			case   DIO_u8PORTB: CLR_BIT( DIO_u8DDRB_REG,u8pin) ; break ;
			case   DIO_u8PORTC: CLR_BIT( DIO_u8DDRC_REG,u8pin) ; break ;
			case   DIO_u8PORTD: CLR_BIT( DIO_u8DDRD_REG,u8pin) ; break ;

		}
	}
	else {
		/* Do nothing, Wrong value to set */

	}


}

extern u8 DIO_GetPinValue(u8 u8port,u8 u8pin){

	u8  Loc_u8PinValue=0 ;


	switch (u8port){

		case   DIO_u8PORTA:Loc_u8PinValue= GET_BIT( DIO_u8PINA_REG,u8pin) ; break ;
		case   DIO_u8PORTB: Loc_u8PinValue=GET_BIT( DIO_u8PINB_REG,u8pin) ; break ;
		case   DIO_u8PORTC:Loc_u8PinValue= GET_BIT( DIO_u8PINC_REG,u8pin) ; break ;
		case   DIO_u8PORTD: Loc_u8PinValue=GET_BIT( DIO_u8PIND_REG,u8pin) ; break ;

		default : /* worng port */ break;
	}


	return Loc_u8PinValue ;
}
 extern void DIO_TOGLEPinValue(u8 u8port,u8 u8pin){
	 
	 
	 switch (u8port){

		 case   DIO_u8PORTA:TOGGLE_BIT( DIO_u8PINA_REG,u8pin) ; break ;
		 case   DIO_u8PORTB: TOGGLE_BIT( DIO_u8PINB_REG,u8pin) ; break ;
		 case   DIO_u8PORTC:TOGGLE_BIT( DIO_u8PINC_REG,u8pin) ; break ;
		 case   DIO_u8PORTD: TOGGLE_BIT( DIO_u8PIND_REG,u8pin) ; break ;

		 default : /* worng port */ break;
	 }
	 
	 
	 
	 
 }