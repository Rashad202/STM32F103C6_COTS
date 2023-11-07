 /*
 *							     NCIC_program.c
 *
 *  Author  : Rashad
 *  Date    : 13 OCT 2023
 *  Layer   : MCAL
 *
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
#include "../SCB_interface.h"


/* -------------------------------------------------------------------- */

void NVIC_voidSetPriority(s8 Copy_s8INTID , u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority )
{
	u8 NVIC_MAX_Group_Priority;
	    u8 NVIC_MAX_Sub_Priority;

	    #if (PRIORITY_GROUPING == NVIC_16GROUP_0SUB)
	        NVIC_MAX_Group_Priority = 15;
	        NVIC_MAX_Sub_Priority = NONE;
	    #elif (PRIORITY_GROUPING == NVIC_8GROUP_2SUB)
	        NVIC_MAX_Group_Priority = 7;
	        NVIC_MAX_Sub_Priority = 1;
	    #elif (PRIORITY_GROUPING == NVIC_4GROUP_4SUB)
	        NVIC_MAX_Group_Priority = 3;
	        NVIC_MAX_Sub_Priority = 3;
	    #elif (PRIORITY_GROUPING == NVIC_2GROUP_8SUB)
	        NVIC_MAX_Group_Priority = 1;
	        NVIC_MAX_Sub_Priority = 7;
	    #elif (PRIORITY_GROUPING == NVIC_0GROUP_16SUB)
	        NVIC_MAX_Group_Priority = NONE;
	        NVIC_MAX_Sub_Priority = 15;
	    #else
	        #error "Invalid PRIORITY_GROUPING value. Please choose from _16GROUP_SUB0, _8GROUP_SUB2, _4GROUP_SUB4, _2GROUP_SUB8, or _0GROUP_SUB16."
	    #endif

	    if (Copy_u8GroupPriority > NVIC_MAX_Group_Priority || Copy_u8SubPriority > NVIC_MAX_Sub_Priority)
	    {
	    		//ERORR
	    }

	    if (Copy_s8INTID > NUMBER_OF_INTERRUPTS)
	    {
    		//ERORR
	    }

	    /* Configure the priority grouping for the Nested Vectored Interrupt Controller (NVIC) */
	    SCB_SetPriorityGrouping(PRIORITY_GROUPING);

	    /* Calculate the Priority value will be added to the IPRx */
	    u8 Local_Priority = (Copy_u8SubPriority | (Copy_u8GroupPriority << (PRIORITY_GROUPING - NVIC_16GROUP_0SUB) / 0x100));

	    /* Calculate the register index (IPRx) and bit position within the register */

	    /* Divide by 4 to get the register index */
	    u32 RegisterIndex = Copy_s8INTID / 4;
	    /* Multiply by 8 to get the bit position */
	    u32 BitPosition = (Copy_s8INTID % 4) * 8;

	    /* Read the current value of the IPR register */
	    u32 RegValue = NVIC_IPR_BASE_ADDRESS[RegisterIndex];

	    /* Clear the bits that control the priority for the given interrupt */
	    RegValue &= ~(0xFF << BitPosition);

	    /* Set the priority in the appropriate IPRx register */
	    RegValue |= (Local_Priority << BitPosition);

	    /* Write the modified value back to the IPR register */
	    NVIC_IPR_BASE_ADDRESS[RegisterIndex] = (RegValue << 4);
	
}

/* -------------------------------------------------------------------- */
void NVIC_u8GetPriority        (u8 Copy_s8INTID , u8 *Copy_Priority )
{

	if (Copy_s8INTID > NUMBER_OF_INTERRUPTS) /**< Check if IRQn is within valid range */
	    {
			//ERORR
		}

	    /**< Calculate the register index (IPRx) and bit position within the register */
	 	 /* Divide by 4 to get the register index */
		u8 RegisterIndex = Copy_s8INTID / 4;
		/* Remainder of 4 to get the bit index */
		u8 BitIndex = (Copy_s8INTID % 4);
		/* Multiply by 8 to get the bit position */
		u8 BitPosition = (Copy_s8INTID % 4) * 8;

	    /* Pointer arithmetic to access the IPRx register */
	    u8 *PriorityRegister = (u8 *)&NVIC_IPR_BASE_ADDRESS[RegisterIndex];

	    /* Extract the priority from the IPRx register */
	    *Copy_Priority = (PriorityRegister[BitIndex] >> (BitPosition)) & 0xFF;
}

/* -------------------------------------------------------------------- */


void NVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber < 32)
	    {
	        NVIC_ISER0 = (1 << Copy_u8IntNumber);
	    }
	    else if (Copy_u8IntNumber < 64)
	    {
	        NVIC_ISER1 = (1 << (Copy_u8IntNumber - 32));
	    }
	    else if (Copy_u8IntNumber < 96)
	    {
	        NVIC_ISER2 = (1 << (Copy_u8IntNumber - 64));
	    }
	    else
	    {
	        //ERORR
	    }
}

/* -------------------------------------------------------------------- */

void NVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber < 32)
		    {
		        NVIC_ISPR0 = (1 << Copy_u8IntNumber);
		    }
		    else if (Copy_u8IntNumber < 64)
		    {
		        NVIC_ISPR1 = (1 << (Copy_u8IntNumber - 32));
		    }
		    else if (Copy_u8IntNumber < 96)
		    {
		        NVIC_ISPR2 = (1 << (Copy_u8IntNumber - 64));
		    }
		    else
		    {
		        //ERROR
		    }
	
}

/* -------------------------------------------------------------------- */

void NVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber < 32)
	    {
	        NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	    }
	    else if (Copy_u8IntNumber < 64)
	    {
	        NVIC_ISPR1 = (1 << (Copy_u8IntNumber - 32));
	    }
	    else if (Copy_u8IntNumber < 96)
	    {
	        NVIC_ISPR2 = (1 << (Copy_u8IntNumber - 64));
	    }
	    else
	    {
	    	//ERORR
	    }
	
	
}

/* -------------------------------------------------------------------- */

void NVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber < 32)
	    {
	        NVIC_ICPR0 = (1U << Copy_u8IntNumber);
	    }
	    else if (Copy_u8IntNumber < 64)
	    {
	        NVIC_ICPR1 = (1U << (Copy_u8IntNumber - 32));
	    }
	    else if (Copy_u8IntNumber < 96)
	    {
	        NVIC_ICPR2 = (1U << (Copy_u8IntNumber - 64));
	    }
	
}


/* -------------------------------------------------------------------- */

u8 NVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 u8State;
		if(Copy_u8IntNumber<32){
			u8State=GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
			return u8State;			/*return Active Flage state  */
		}
		else if(Copy_u8IntNumber<64)
		{
			Copy_u8IntNumber-=32;
			u8State=GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
			return u8State;			/*return Active Flage state  */
		}
		else if(Copy_u8IntNumber<96)
		{
			Copy_u8IntNumber-=64;
			u8State=GET_BIT(NVIC_IABR2,Copy_u8IntNumber);
			return u8State;			/*return Active Flage state  */
		}
		else
		{
			return 0;
		}
	
}



