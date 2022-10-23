/*
 * EXT_interface.h
 *
 *  Created on: Oct 23, 2022
 *      Author: Mahmoud
 */

#ifndef EXT_INTERFACE_H_
#define EXT_INTERFACE_H_

#define EXT_INT0  __vector_1
#define EXT_INT1  __vector_2
#define EXT_INT2  __vector_3


#define ISR(INT_VEC)  void INT_VEC(void) __attribute__((signal));\
void INT_VEC(void)



#define Low_level     0
#define Any_change    1
#define Falling_Edge  2
#define Rising_Edge   3


void GEI_voidEnable (void);
void GEI_voidDisable(void);

void EXT_voidEnable_EXT_0 ( u8 COPY_u8Mode );
void EXT_voidEnable_EXT_1 ( u8 COPY_u8Mode );
void EXT_voidEnable_EXT_2 ( u8 COPY_u8Mode );

void EXT_voidDisable_EXT_0(void);
void EXT_voidDisable_EXT_1(void);
void EXT_voidDisable_EXT_2(void);

void EXT_voidCLRFlag_EXT_0(void);
void EXT_voidCLRFlag_EXT_1(void);
void EXT_voidCLRFlag_EXT_2(void);


/*
 * to write isr for any interrupt  use
 * ISR(param)
 * {
 *
 * }
 * param = EXT_INT0 if you will use EXT 0
 * param = EXT_INT1 if you will use EXT 1
 * param = EXT_INT2 if you will use EXT 2
 */


#endif /* EXT_INTERFACE_H_ */
