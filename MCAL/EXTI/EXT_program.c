/*
 * EXT_program.c
 *
 *  Created on: Oct 23, 2022
 *      Author: Mahmoud
 */

#include "../../services/STD_TYPES.h"
#include "../../services/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "EXT_interface.h"
#include "EXT_private.h"



void GEI_voidEnable (void)
{
	SET_BIT(SREG ,7);

}
void GEI_voidDisable(void)
{
	CLR_BIT(SREG,7);
}


void EXT_voidEnable_EXT_0 ( u8 COPY_u8Mode )
{
	SET_BIT(GICR,6);
	switch( COPY_u8Mode )
	{
		case Low_level   : CLR_BIT(MCUCR ,0); CLR_BIT(MCUCR ,1); break;
		case Any_change  : SET_BIT(MCUCR ,0); CLR_BIT(MCUCR ,1); break;
		case Falling_Edge: CLR_BIT(MCUCR ,0); SET_BIT(MCUCR ,1); break;
		case Rising_Edge : SET_BIT(MCUCR ,0); SET_BIT(MCUCR ,1); break;

	}

}
void EXT_voidEnable_EXT_1 ( u8 COPY_u8Mode )
{
	SET_BIT(GICR , 7);
	switch( COPY_u8Mode )
	{
		case Low_level   : CLR_BIT(MCUCR , 2); CLR_BIT(MCUCR , 3); break;
		case Any_change  : SET_BIT(MCUCR , 2); CLR_BIT(MCUCR , 3); break;
		case Falling_Edge: CLR_BIT(MCUCR , 2); SET_BIT(MCUCR , 3); break;
		case Rising_Edge : SET_BIT(MCUCR , 2); SET_BIT(MCUCR , 3); break;

	}

}
void EXT_voidEnable_EXT_2 ( u8 COPY_u8Mode )
{
	SET_BIT(GICR , 5);
	switch( COPY_u8Mode )
	{
		case Falling_Edge: CLR_BIT(MCUCSR , 6);  break;
		case Rising_Edge : SET_BIT(MCUCSR , 6);  break;

		default : break;
	}

}

void EXT_voidDisable_EXT_0(void)
{
	CLR_BIT(GICR,6);
}
void EXT_voidDisable_EXT_1(void)
{
	CLR_BIT(GICR,7);
}
void EXT_voidDisable_EXT_2(void)
{
	CLR_BIT(GICR,5);
}

void EXT_voidCLRFlag_EXT_0(void)
{
	SET_BIT(GIFR , 6);
}
void EXT_voidCLRFlag_EXT_1(void)
{
	SET_BIT(GIFR , 7);
}
void EXT_voidCLRFlag_EXT_2(void)
{
	SET_BIT(GIFR , 5);
}





