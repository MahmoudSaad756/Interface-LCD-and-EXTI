/*
 * LCD_program.c
 *
 *  Created on: Oct 16, 2022
 *      Author: Mahmoud 
 */

#include <util/delay.h>

#include "../../services/STD_TYPES.h"
#include "../../services/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"


void LCD_voidInit(void)
{
	DIO_voidSetPortDirection(LCD_PORT , Output);

	_delay_ms(50);

	DIO_voidSetPinValue(LCD_PORT,LCD_RS,Low);
	_delay_us(1);

	LCD_voidSendNibble(0b0011);
	_delay_ms(5);

	LCD_voidSendNibble(0b0011);
	_delay_ms(5);

	LCD_voidSendNibble(0b0011);
	_delay_ms(5);

	LCD_voidSendNibble(0b0010);

	LCD_voidSendCommand(0b00100000);  // Function Set
	_delay_ms(1);

	LCD_voidSendCommand(0b00001100);  // Display ON/OFF
	_delay_ms(1);

	LCD_voidSendCommand(0b00000001);  // Display Clear
	_delay_ms(2);

	LCD_voidSendCommand(0b00000110);  // Display Clear
	_delay_ms(1);

}

void LCD_voidSendNibble(u8 COPY_u8Data)
{

	DIO_voidSetPinValue(LCD_PORT,LCD_RW,Low);
	_delay_ms(1);

	DIO_voidSetPinValue(LCD_PORT,LCD_D4, (COPY_u8Data) & 1   	  );
	DIO_voidSetPinValue(LCD_PORT,LCD_D5, (COPY_u8Data >> 1) & 1   );
	DIO_voidSetPinValue(LCD_PORT,LCD_D6, (COPY_u8Data >> 2) & 1   );
	DIO_voidSetPinValue(LCD_PORT,LCD_D7, (COPY_u8Data >> 3) & 1   );


	DIO_voidSetPinValue(LCD_PORT,LCD_E,High);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_PORT,LCD_E,Low);

}

void LCD_voidSendChar(u8 COPY_u8Data )
{
	DIO_voidSetPinValue(LCD_PORT,LCD_RS,High);

	_delay_ms(5);

	LCD_voidSendNibble(COPY_u8Data>>4);
	LCD_voidSendNibble(COPY_u8Data);


}
void LCD_voidSendCommand(u8 COPY_u8command)
{
	DIO_voidSetPinValue(LCD_PORT,LCD_RS,Low);

	_delay_ms(5);


	LCD_voidSendNibble(COPY_u8command>>4);
	LCD_voidSendNibble(COPY_u8command);


}

void LCD_voidSendStr(u8 * COPY_u8Ptr)
{
	u8 LOC_u8Iterator=0;

	while( COPY_u8Ptr[LOC_u8Iterator] )
	{
		LCD_voidSendChar( COPY_u8Ptr[LOC_u8Iterator] );
		LOC_u8Iterator++;
	}

}

void LCD_voidClear(void)
{

	LCD_voidSendCommand(1);

}


void LCD_voidSendNumber(u32 COPY_u32Number )
{
	if(COPY_u32Number == 0)
		LCD_voidSendChar(48);


	u32 LOC_u32Var=1;
	while(COPY_u32Number > 0)
	{
		LOC_u32Var*=10;
		LOC_u32Var+=( COPY_u32Number%10 );

		COPY_u32Number/=10;
	}

	while(LOC_u32Var > 1)
	{
		LCD_voidSendChar( LOC_u32Var % 10 + 48);
		LOC_u32Var /= 10;
	}

}

void LCD_voidgoto(u8 COPY_u8Row , u8 COPY_u8Col)
{

	if( COPY_u8Row == 1 )
	{
		LCD_voidSendCommand( COPY_u8Col + 0x80 -1 );
	}
	else if (COPY_u8Row == 2)
	{
		LCD_voidSendCommand( COPY_u8Col + 0x64 + 0x80 -1 );
	}

}



