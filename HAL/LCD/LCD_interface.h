/*
 * LCD_interface.h
 *
 *  Created on: Oct 16, 2022
 *      Author: Mahmoud
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



void LCD_voidInit(void);
void LCD_voidSendChar(u8 COPY_u8Data);
void LCD_voidSendCommand(u8 COPY_u8Command);
void LCD_voidSendStr(u8 * COPY_u8Ptr);
void LCD_voidClear(void);
void LCD_voidSendNumber(u32 COPY_u32Number );
void LCD_voidgoto(u8 COPY_u8Row , u8 COPY_u8Col);



#endif /* LCD_INTERFACE_H_ */
