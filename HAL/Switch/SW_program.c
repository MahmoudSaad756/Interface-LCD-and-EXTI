#include "../../services/STD_TYPES.h"
#include "../../services/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "SW_interface.h"
#include "SW_private.h"

void SW_voidInit	( SW_Type Copy_SWConfig)
{
	DIO_voidSetPinDirection( Copy_SWConfig.Port , Copy_SWConfig.Pin , Input );

	if( Copy_SWConfig.SW_Conection == SW_Input_Pullup)
	{
		DIO_voidSetPinDirection(Copy_SWConfig.Port , Copy_SWConfig.Pin , Input_Pullup);
	}

}

u8 SW_u8IsPressed ( SW_Type Copy_SWConfig)
{
   return	DIO_u8GetPinValue(Copy_SWConfig.Port , Copy_SWConfig.Pin ) ;
}
