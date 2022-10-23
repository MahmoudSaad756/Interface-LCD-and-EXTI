
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define DIO_PortA 0
#define DIO_PortB 1
#define DIO_PortC 2
#define DIO_PortD 3

#define Output  			    1
#define Input  	   	  		    0
#define Input_Pullup            2

#define High 1
#define Low  0

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7



void DIO_voidSetPortDirection(u8 COPY_u8Port , u8 COPY_u8Direction);
void DIO_voidSetPortValue    (u8 COPY_u8Port , u8 COPY_u8Value);

void DIO_voidSetPinDirection(u8 COPY_u8Port , u8 COPY_u8PinNumber , u8 COPY_u8Direction);
void DIO_voidSetPinValue    (u8 COPY_u8Port , u8 COPY_u8PinNumber , u8 COPY_u8Value);

u8 DIO_u8GetPortValue( u8 COPY_u8Port );
u8 DIO_u8GetPinValue ( u8 COPY_u8Port , u8 COPY_u8PinNumber );


#endif
