/*
 *							    GPIO_program.c
 *
 *  Author  : Rashad
 *  Date    : 7	OCT 2023
 *  Layer   : MCAL
 *
 */
 
 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"


/* -------------------------------------------------------------------- */


void GPIO_voidSetPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Mode ){

	switch(Copy_u8Port)
	{
	case GPIOA:

		if(Copy_u8Pin <= 7 )
		{
			//GPIO_LOW

			// Clear the 4 Bits of the wanted Pin [0:15]
			GPIOA_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));// R M W
			
			// Set the Value(mode) on the 4 Bits of the wanted Pin [0:15]
			GPIOA_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );

		}
		else if(Copy_u8Pin <=15 )
		{
			//GPIO_HIGH

			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOA_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOA_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );
		}

		break;

	case GPIOB:

		if(Copy_u8Pin <= 7 )
		{//GPIO_LOW

			GPIOB_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			GPIOB_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

		}
		else if(Copy_u8Pin <=15 )
		{//GPIO_HIGH
			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOB_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOB_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		break;
	case GPIOC:
		if(Copy_u8Pin <= 7 )
		{//GPIO_LOW
			GPIOC_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			GPIOC_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		else if(Copy_u8Pin <=15 )
		{//GPIO_HIGH
			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOC_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOC_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		break;
	default :break;
	}


}

/* -------------------------------------------------------------------- */


void GPIO_voidSetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Value ){

	switch(Copy_u8Port)
	{
	case GPIOA:
		if( u8Copy_u8Value == GPIO_HIGH ){

			SET_BIT( GPIOA_ODR , Copy_u8Pin );
			// /*or Using BSR for more speed */==> GPIOA_BSR=(1<<Copy_u8Pin);

		}else if( u8Copy_u8Value == GPIO_LOW ){
			CLR_BIT(  GPIOA_ODR , Copy_u8Pin );
			// /*or Using BSR for more speed */==> GPIOA_BSR=(1<<Copy_u8Pin+16);
			// /*or Using BRR for more speed than BSR */==> GPIOA_BSR=(1<<Copy_u8Pin);
		}
		break;
		
	case GPIOB:
		if( u8Copy_u8Value == GPIO_HIGH ){

			SET_BIT( GPIOB_ODR  , Copy_u8Pin );

		}else if( u8Copy_u8Value == GPIO_LOW ){
			CLR_BIT( GPIOB_ODR  , Copy_u8Pin );
		}
		break;
		
	case GPIOC:
		if( u8Copy_u8Value == GPIO_HIGH ){

			SET_BIT( GPIOC_ODR , Copy_u8Pin );

		}else if( u8Copy_u8Value == GPIO_LOW ){
			CLR_BIT( GPIOC_ODR , Copy_u8Pin );
		}
		break;
	default : break; 

	}

}

/* -------------------------------------------------------------------- */

u8   GPIO_u8GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin ){

	u8 LOC_u8Result = 0 ;

	switch(Copy_u8Port)
	{
	case GPIOA:
		LOC_u8Result = GET_BIT( GPIOA_IDR , Copy_u8Pin );

		break;
	case GPIOB:

		LOC_u8Result = GET_BIT( GPIOB_IDR , Copy_u8Pin );

		break;
	case GPIOC:

		LOC_u8Result = GET_BIT( GPIOC_IDR , Copy_u8Pin );

		break;
	}
	return LOC_u8Result;
}

/* -------------------------------------------------------------------- */

void GPIO_voidSetPortDirection( u8 Copy_u8Port , u8 Copy_u8Position , u8 Copy_u8Mode ){

	switch( Copy_u8Port ){

	case GPIOA:

		if      ( Copy_u8Position == GPIO_LOW  )
		{
			GPIOA_CRL = ( 0x11111111 * Copy_u8Mode ) ;
		}
		else if ( Copy_u8Position == GPIO_HIGH )
		{
			GPIOA_CRH = ( 0x11111111 * Copy_u8Mode ) ;
		}

		break;
	case GPIOB:

		if      ( Copy_u8Position == GPIO_LOW  )
		{
			GPIOB_CRL = ( 0x11111111 * Copy_u8Mode ) ;
		}
		else if ( Copy_u8Position == GPIO_HIGH )
		{
			GPIOB_CRH = ( 0x11111111 * Copy_u8Mode ) ;
		}

		break;
	case GPIOC:

		if      ( Copy_u8Position == GPIO_LOW  )
		{
			GPIOC_CRL = ( 0x11111111 * Copy_u8Mode ) ;
		}
		else if ( Copy_u8Position == GPIO_HIGH )
		{
			GPIOC_CRH = ( 0x11111111 * Copy_u8Mode ) ;
		}

		break;
	default :break;

	}

}

/* -------------------------------------------------------------------- */

void GPIO_voidSetPortValue( u8 Copy_u8Port , u8 Copy_u8Position , u16 Copy_u8Value ){

	switch( Copy_u8Port ){

	case GPIOA:

		if      ( Copy_u8Position == GPIO_LOW  )
		{
			GPIOA_ODR = (GPIOA_ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ;
		}
		else if ( Copy_u8Position == GPIO_HIGH )
		{
			GPIOA_ODR = (GPIOA_ODR & 0x00FF ) | (     Copy_u8Value ) ;
		}

		break;
	case GPIOB:

		if      ( Copy_u8Position == GPIO_LOW  )
		{
			GPIOB_ODR = (GPIOB_ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ;
		}
		else if ( Copy_u8Position == GPIO_HIGH )
		{
			GPIOB_ODR = (GPIOB_ODR & 0x00FF ) | (     Copy_u8Value ) ;
		}

		break;
	case GPIOC:

		if      ( Copy_u8Position == GPIO_LOW  ){
			GPIOC_ODR = (GPIOC_ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ;
		}
		else if ( Copy_u8Position == GPIO_HIGH ){
			GPIOC_ODR = (GPIOC_ODR & 0x00FF ) | (     Copy_u8Value ) ;
		}

		break;
	default :break;

	}

}

/* -------------------------------------------------------------------- */

u16 GPIO_u16GetPortValue( u8 Copy_u8Port , u8 Copy_u8Position ){

	u16 LOC_u16Result = 0;

	switch( Copy_u8Port ){

	case GPIOA:

		LOC_u16Result = GPIOA_IDR;
		if      ( Copy_u8Position == GPIO_LOW  )
		{
			LOC_u16Result &= 0x00FF ;
		}
		else if ( Copy_u8Position == GPIO_HIGH )
		{
			LOC_u16Result &= 0xFF00 ;
		}

		break;
	case GPIOB:

		LOC_u16Result = GPIOB_IDR;
		if      ( Copy_u8Position == GPIO_LOW  )
		{
			LOC_u16Result &= 0x00FF ;
		}
		else if ( Copy_u8Position == GPIO_HIGH )
		{
			LOC_u16Result &= 0xFF00 ;
		}

		break;
	case GPIOC:

		LOC_u16Result = GPIOC_IDR;
		if      ( Copy_u8Position == GPIO_LOW  )
		{
			LOC_u16Result &= 0x00FF ;
		}
		else if ( Copy_u8Position == GPIO_HIGH )
		{
			LOC_u16Result &= 0xFF00 ;
		}

		break;

	}

	return LOC_u16Result ;

}


/* -------------------------------------------------------------------- */
