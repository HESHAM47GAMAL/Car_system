/* main.c
 *
 *  Created on: Mar 7, 2024
 *      Author: moham
 *      Author: Mohamed
 */

#include "SERVICE/COMMON_MACROS.h"
#include "SERVICE/STD_TYPES.h"

#include "Application/Application.h"
#include "HAL/BUTTON/BUTTON_interface.h"
#include "HAL/LED/LED_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"

void A_APPLICATION_VOID_CCS_CHANGE(void);









int main()
{


	init();
	A_APPLICATION_VOID_LCD_STATICS();
	while(1)
	{
		A_APPLICATION_VOID_ACCELERATE();
		A_APPLICATION_VOID_BRAKES();
		A_APPLICATION_VOID_CCS_CHANGE();
		A_APPLICATION_VOID_MAIN_GEARBOX_CHANGE();



	}

}

