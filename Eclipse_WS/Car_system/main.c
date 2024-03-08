/*
 * main.c
 *
 *  Created on: Mar 7, 2024
 *      Author: moham
 */


#include "Application/Application.h"

int main()
{
	/*	Make Initialize for Every thing*/
	App_Init();
	
	while(1)
	{
		StateMachineUpdate();
	}



}
