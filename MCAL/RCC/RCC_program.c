/*
 * 								    RCC_program.c
 *
 *  Author  : Rashad
 *  Date    : 7	OCT 2023
 *  Layer   : MCAL
 *
 */ 


/* include Libraries  */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../RCC/RCC_config.h"
#include "../RCC/RCC_interface.h"
#include "../RCC/RCC_private.h"
   
 
/* ------------------------------------------------ */

void RCC_voidInitSysClock(void)
{

	#if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		SET_BIT(RCC_CR,16);			/* Enable HSE with no bypass */
		CLR_BIT(RCC_CR,18);

		SET_BIT(RCC_CFGR,0);		/* 01: HSE selected as system clock*/
		CLR_BIT(RCC_CFGR,1);

	#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
		SET_BIT(RCC_CR,16);			/* Enable HSE  bypass */
		SET_BIT(RCC_CR,18);

		SET_BIT(RCC_CFGR,0);		/* 01: HSE selected as system clock*/
		CLR_BIT(RCC_CFGR,1);

	#elif   RCC_CLOCK_TYPE == RCC_HSI
		SET_BIT(RCC_CR,0);			/* Enable HSI + Trimming = 0 */

		CLR_BIT(RCC_CFGR,0);		/* 00: HSI selected as system clock*/
		CLR_BIT(RCC_CFGR,1);
		while(GET_BIT(RCC_CFGR,1)== 0 );


	#elif   RCC_CLOCK_TYPE == RCC_PLL

		CLR_BIT(RCC_CFGR,0);		/*  10: PLL selected as system clock*/
		SET_BIT(RCC_CFGR,1);

		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			CLR_BIT( RCC_CFGR , 16 );		/* 0: HSI oscillator clock / 2 selected*/

		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
			SET_BIT(RCC_CR,16);			/* Enable HSE */
			SET_BIT( RCC_CFGR , 16 );		/* 1: HSE oscillator clock  selected*/
			SET_BIT( RCC_CFGR , 17 );			/* HSE Is Not Divided */

		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
			SET_BIT(RCC_CR,16);					/* Enable HSE */
			SET_BIT( RCC_CFGR , 16 );			/* 1: HSE oscillator clock  selected*/
			CLR_BIT( RCC_CFGR , 17 );			/* HSE Is Not Divided */
		#endif
		SET_BIT(RCC_CR,24);			/* Enable PLL */

		/* Choosing The Multiplication Factor For PLL */
		#if ( CLOCK_FACTOR >= NO_CLOCK_FACTOR ) && ( CLOCK_FACTOR <= PLL_CLOCK_MULTIPLE_BY_16)

		RCC_CFGR &= ~( ( 0b1111 )     << 18 ) ;
		RCC_CFGR |=  ( CLOCK_FACTOR ) << 18   ;

		#elif ( CLOCK_FACTOR > PLL_CLOCK_MULTIPLE_BY_16 ) || ( CLOCK_FACTOR < NO_CLOCK_FACTOR )
			#warning "Wrong Multiplication Factor"
		#endif

	#else
		#error("You chosed Wrong Clock type")
	#endif


	/* For Clock Security System */
		#if CLOCK_SECURITY_SYSTEM == ENABLE_CLOCK_SECURITY_SYSTEM

			SET_BIT( RCC_CR , 19 );

		#elif CLOCK_SECURITY_SYSTEM == DISABLE_CLOCK_SECURITY_SYSTEM

			CLR_BIT( RCC_CR , 19 );

		#else

			#warning " Wrong Clock Security System Configuration Choice "

		#endif
}



/* ------------------------------------------------ */

void RCC_voidPrescaler(u8 u8Bus_Id,u8 u8Prescaler_Id)
{
	if(u8Bus_Id==AHB_BUS)
		{
		 switch(u8Prescaler_Id){
			case SYSCLK_DIV2:
			RCC_CFGR|=SYSCLK_DIV2<<START_HPRB;
			break;
			case SYSCLK_DIV4:
			RCC_CFGR|=SYSCLK_DIV4<<START_HPRB;
			break;

			case SYSCLK_DIV8:
			RCC_CFGR|=SYSCLK_DIV8<<START_HPRB;
			break;

			case SYSCLK_DIV16:
			RCC_CFGR|=SYSCLK_DIV16<<START_HPRB;
			break;

			case SYSCLK_DIV64:
			RCC_CFGR|=SYSCLK_DIV64<<START_HPRB;
			break;

			case SYSCLK_DIV128:
			RCC_CFGR|=SYSCLK_DIV128<<START_HPRB;
			break;

			case SYSCLK_DIV256:
			RCC_CFGR|=SYSCLK_DIV256<<START_HPRB;
			break;
			case SYSCLK_DIV512:
			RCC_CFGR|=SYSCLK_DIV512<<START_HPRB;
			break;

			default:
			break;

		 	}
		}
	else if(u8Bus_Id==APB1_BUS)
		{
			{
			 switch(u8Prescaler_Id){
				case HCLK_DIV0:
				RCC_CFGR|=HCLK_DIV0<<START_PPRE1;
				break;
				case HCLK_DIV2:
				RCC_CFGR|=HCLK_DIV2<<START_PPRE1;
				break;
				case HCLK_DIV4:
				RCC_CFGR|=HCLK_DIV4<<START_PPRE1;
				break;

				case HCLK_DIV8:
				RCC_CFGR|=HCLK_DIV8<<START_PPRE1;
				break;

				case HCLK_DIV16:
				RCC_CFGR|=HCLK_DIV16<<START_PPRE1;
				break;

				default:
				break;

			}

		}

		}
	else if(u8Bus_Id==APB2_BUS)
		{
			{
			 switch(u8Prescaler_Id)
			 {
				case HCLK_DIV0:
				RCC_CFGR|=HCLK_DIV0<<START_PPRE2;
				break;
				case HCLK_DIV2:
				RCC_CFGR|=HCLK_DIV2<<START_PPRE2;
				break;
				case HCLK_DIV4:
				RCC_CFGR|=HCLK_DIV4<<START_PPRE2;
				break;

				case HCLK_DIV8:
				RCC_CFGR|=HCLK_DIV8<<START_PPRE2;
				break;

				case HCLK_DIV16:
				RCC_CFGR|=HCLK_DIV16<<START_PPRE2;
				break;

				default:
				break;

			}

		}

		}


}

/* ------------------------------------------------ */


void RCC_voidEnablePeripheralClock( u8 Copy_u8BusId , u8 Copy_u8PeripheralId ){


		
	if (Copy_u8PeripheralId <= 31)
	{
		switch( Copy_u8BusId ){

			case AHB_BUS  : SET_BIT( RCC_AHBENR  , Copy_u8PeripheralId ); break;
			case APB1_BUS :	SET_BIT( RCC_APB1ENR , Copy_u8PeripheralId ); break;
			case APB2_BUS : SET_BIT( RCC_APB2ENR , Copy_u8PeripheralId ); break;
			//default       : /* Return Error */

		}
	}
	
	else
	{
		/* Return Error*/
	}


}

/* ------------------------------------------------ */


void RCC_voidDisablePeripheralClock( u8 Copy_u8BusId , u8 Copy_u8PeripheralId ){

		switch( Copy_u8BusId ){

			case AHB_BUS  : CLR_BIT( RCC_AHBENR  , Copy_u8PeripheralId ); break;
			case APB1_BUS :	CLR_BIT( RCC_APB1ENR , Copy_u8PeripheralId ); break;
			case APB2_BUS : CLR_BIT( RCC_APB2ENR , Copy_u8PeripheralId ); break;

		}
}

/* ------------------------------------------------ */
