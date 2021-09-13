/*
 * mian.c
 *
 *  Created on: ???/???/????
 *      Author: Algo
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"




int main()
{
  /*Clock System initialization*/
	MRCC_voidInitializeClockSystem();
	MRCC_voidEnablePeripheralClock(RCC_APB2,2);

 /*SET GPIO MODE*/
 for(u8 Local_u8Counter = 0; Local_u8Counter<=7;Local_u8Counter++)
 {
	 MGPIO_voidSetPinMode(GPIOA,Local_u8Counter,OUTPUT_2MHZ_PP);
 }

 /*Systick initialization*/
  MSYSTICK_voidInit();


while(1){


	for(u8 i=0;i<=7;i++)
	{
	         	MGPIO_voidSetPinValue(GPIOA , i , HIGH);
				MSYSTICK_SetBusyWait(100000);
				MGPIO_voidSetPinValue(GPIOA , i , LOW);

	}

	for(s8 i=7;i>=0;--i)
		{
		         	MGPIO_voidSetPinValue(GPIOA , i , HIGH);
					MSYSTICK_SetBusyWait(100000);
					MGPIO_voidSetPinValue(GPIOA , i , LOW);

		}

}






return 0;
}


