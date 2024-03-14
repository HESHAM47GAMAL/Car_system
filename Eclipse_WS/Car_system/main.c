/* main.c
 *
 *  Created on: Mar 7, 2024

 *      Author: Mohamed USF
 */

#include "SERVICE/COMMON_MACROS.h"
#include "SERVICE/STD_TYPES.h"

#include "Application/Application.h"
#include "HAL/BUTTON/BUTTON_interface.h"
#include "HAL/LED/LED_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "HAL/BUZZER/Buzzer_Interface.h"











int main()
{


	init();
	A_APPLICATION_VOID_LCD_STATICS();
	H_Buzzer_Void_BuzzerInit();
	while(1)
	{
		 A_APPLICATION_VOID_BTN_ACTION();
		 A_APPLICATION_VOID_MAIN_GEARBOX_CHANGE();

	}

}
