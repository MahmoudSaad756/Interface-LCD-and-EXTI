/*
 * EXT_private.h
 *
 *  Created on: Oct 23, 2022
 *      Author: Mahmoud
 */

#ifndef EXT_PRIVATE_H_
#define EXT_PRIVATE_H_



#define MCUCR   *((volatile u8 *)0x55)
#define MCUCSR  *((volatile u8 *)0x54)
#define GICR    *((volatile u8 *)0x5B)
#define GIFR    *((volatile u8 *)0x5A)
#define SREG    *((volatile u8 *)0x5F)




#endif /* EXT_PRIVATE_H_ */
