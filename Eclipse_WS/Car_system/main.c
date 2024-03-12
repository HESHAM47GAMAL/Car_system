/*
 * main.c
 *
 *  Created on: Mar 7, 2024
 *      Author: moham
 */


#include "Application/Application_interface.h"
uint8 Adc_value_pure = 0;
int main()
{
	/*	Make Initialize for Every thing*/
	App_Init();
	
	while(1)
	{
		StateMachineUpdate();
		// LCD_MoveCursor(3,0);
		// Adc_value_pure = ADC_ReadChannelSingleConvertion(ADC_Channel_0);
		// LCD_intToString(Adc_value_pure);
		// LCD_DisplayCharacter('8');
	}



}
