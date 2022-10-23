/*
 * main.c
 *
 *  Created on: Oct 23, 2022
 *      Author: Mahmoud
 */


#include <util/delay.h>

#include "services/STD_TYPES.h"
#include "services/BIT_MATH.h"

#include "MCAL/EXTI/EXT_interface.h"
#include "MCAL/DIO/DIO_interface.h"

#include "HAL/LCD/LCD_interface.h"
#include "HAL/Switch/SW_interface.h"



int main(void)
{
	LCD_voidInit();
	SW_Type S1 ={ DIO_PortD , PIN2 , SW_Input_Pullup};
	SW_Type S2 ={ DIO_PortD , PIN3 , SW_Input_Pullup};
	SW_Type S3 ={ DIO_PortB , PIN2 , SW_Input_Pullup};
	SW_voidInit(S1);
	SW_voidInit(S2);
	SW_voidInit(S3);

	EXT_voidEnable_EXT_0 ( Falling_Edge );
	EXT_voidEnable_EXT_1 ( Falling_Edge );
	EXT_voidEnable_EXT_2 ( Falling_Edge );

	GEI_voidEnable();


	while(1);
	return 0;
}


ISR(EXT_INT0)
{
	LCD_voidClear();
	LCD_voidgoto(1,0);
	LCD_voidSendStr((u8 *)"I am EXTI 0");
	_delay_ms(500);
}

ISR(EXT_INT1)
{
	LCD_voidClear();
	LCD_voidgoto(1,1);
	LCD_voidSendStr((u8 *)"I am EXTI 1");
	_delay_ms(500);
}

ISR(EXT_INT2)
{
	LCD_voidClear();
	LCD_voidgoto(1,2);
	LCD_voidSendStr((u8 *)"I am EXTI 2");
	_delay_ms(500);
}





