#include "../../services/STD_TYPES.h"
#include "../../services/BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"

void DIO_voidSetPortDirection(u8 COPY_u8Port, u8 COPY_u8Direction)
{

	switch (COPY_u8Port) {
	case DIO_PortA:
		if (COPY_u8Direction == Output)
			DDRA = 0xff;
		else if (COPY_u8Direction == Input)
			DDRA = 0x00;
		else if (COPY_u8Direction == Input_Pullup)
		{
			DDRA = 0x00;
			PORTA = 0xff;
		}

		break;

	case DIO_PortB:
		if (COPY_u8Direction == Output)
			DDRB = 0xff;
		else if (COPY_u8Direction == Input)
			DDRB = 0x00;
		else if (COPY_u8Direction == Input_Pullup)
		{
			DDRB = 0x00;
			PORTB = 0xff;
		}

		break;
	case DIO_PortC:
		if (COPY_u8Direction == Output)
			DDRC = 0xff;
		else if (COPY_u8Direction == Input)
			DDRC = 0x00;
		else if (COPY_u8Direction == Input_Pullup)
		{
			DDRC  = 0x00;
			PORTC = 0xff;
		}
		break;
	case DIO_PortD:
		if (COPY_u8Direction == Output)
			DDRD = 0xff;
		else if (COPY_u8Direction == Input)
			DDRD = 0x00;
		else if (COPY_u8Direction == Input_Pullup)
		{
			DDRD  = 0x00;
			PORTD = 0xff;
		}

		break;
	}

}

void DIO_voidSetPortValue(u8 COPY_u8Port, u8 COPY_u8Value)
{

	switch (COPY_u8Port) {
	case DIO_PortA:
		PORTA = COPY_u8Value;
		break;
	case DIO_PortB:
		PORTA = COPY_u8Value;
		break;
	case DIO_PortC:
		PORTA = COPY_u8Value;
		break;
	case DIO_PortD:
		PORTA = COPY_u8Value;
		break;
	}

}

void DIO_voidSetPinDirection(u8 COPY_u8Port, u8 COPY_u8PinNumber,u8 COPY_u8Direction)
{

	if (COPY_u8Direction == Output)
	{
		switch (COPY_u8Port) {
		case DIO_PortA:
			SET_BIT(DDRA, COPY_u8PinNumber);
			break;
		case DIO_PortB:
			SET_BIT(DDRB, COPY_u8PinNumber);
			break;
		case DIO_PortC:
			SET_BIT(DDRC, COPY_u8PinNumber);
			break;
		case DIO_PortD:
			SET_BIT(DDRD, COPY_u8PinNumber);
			break;
		}

	}
	else if( COPY_u8Direction == Input_Pullup )
	{
		switch (COPY_u8Port)
		{
		case DIO_PortA:
			CLR_BIT(DDRA , COPY_u8PinNumber);
			SET_BIT(PORTA, COPY_u8PinNumber);
			break;
		case DIO_PortB:
			CLR_BIT(DDRB , COPY_u8PinNumber);
			SET_BIT(PORTB, COPY_u8PinNumber);
			break;
		case DIO_PortC:
			CLR_BIT(DDRC , COPY_u8PinNumber);
			SET_BIT(PORTC, COPY_u8PinNumber);
			break;
		case DIO_PortD:
			CLR_BIT(DDRD , COPY_u8PinNumber);
			SET_BIT(PORTD, COPY_u8PinNumber);
			break;
		}
	}
	else
		{
			switch (COPY_u8Port)
			{
			case DIO_PortA:
				CLR_BIT(DDRA, COPY_u8PinNumber);
				break;
			case DIO_PortB:
				CLR_BIT(DDRB, COPY_u8PinNumber);
				break;
			case DIO_PortC:
				CLR_BIT(DDRC, COPY_u8PinNumber);
				break;
			case DIO_PortD:
				CLR_BIT(DDRD, COPY_u8PinNumber);
				break;
			}
		}

}

void DIO_voidSetPinValue(u8 COPY_u8Port, u8 COPY_u8PinNumber, u8 COPY_u8Value)
{

	if (COPY_u8Value == High) {
		switch (COPY_u8Port) {
		case DIO_PortA:
			SET_BIT(PORTA, COPY_u8PinNumber);
			break;
		case DIO_PortB:
			SET_BIT(PORTB, COPY_u8PinNumber);
			break;
		case DIO_PortC:
			SET_BIT(PORTC, COPY_u8PinNumber);
			break;
		case DIO_PortD:
			SET_BIT(PORTD, COPY_u8PinNumber);
			break;
		}

	} else {
		switch (COPY_u8Port) {
		case DIO_PortA:
			CLR_BIT(PORTA, COPY_u8PinNumber);
			break;
		case DIO_PortB:
			CLR_BIT(PORTB, COPY_u8PinNumber);
			break;
		case DIO_PortC:
			CLR_BIT(PORTC, COPY_u8PinNumber);
			break;
		case DIO_PortD:
			CLR_BIT(PORTD, COPY_u8PinNumber);
			break;
		}
	}

}

u8 DIO_u8GetPortValue(u8 COPY_u8Port)
{

	u8 LOC_u8Temp;

	switch (COPY_u8Port) {
	case DIO_PortA:
		LOC_u8Temp = PINA;
		break;
	case DIO_PortB:
		LOC_u8Temp = PINA;
		break;
	case DIO_PortC:
		LOC_u8Temp = PINA;
		break;
	case DIO_PortD:
		LOC_u8Temp = PINA;
		break;
	}
	return LOC_u8Temp;

}

u8 DIO_u8GetPinValue(u8 COPY_u8Port, u8 COPY_u8PinNumber)
{

	u8 LOC_u8Temp;

	switch (COPY_u8Port) {
	case DIO_PortA:
		LOC_u8Temp = GET_BIT(PINA, COPY_u8PinNumber);
		break;
	case DIO_PortB:
		LOC_u8Temp = GET_BIT(PINB, COPY_u8PinNumber);
		break;
	case DIO_PortC:
		LOC_u8Temp = GET_BIT(PINC, COPY_u8PinNumber);
		break;
	case DIO_PortD:
		LOC_u8Temp = GET_BIT(PIND, COPY_u8PinNumber);
		break;
	}
	return LOC_u8Temp;
}


