

#ifndef SW_INTERFACE_H
#define SW_INTERFACE_H


#define SW_Input_floating  0
#define SW_Input_Pullup    1
#define Is_Pressed    	   0


typedef struct {
	u8 Port;
	u8 Pin;
	u8 SW_Conection;
}SW_Type;

void SW_voidInit	( SW_Type Copy_SWConfig);
u8 SW_u8IsPressed ( SW_Type Copy_SWConfig);


#endif



