/*
 * Application.c
 *
 *  Created on: Mar 7, 2024
 *      Author: Mohammad Usf
 */
#include "../SERVICE/COMMON_MACROS.h"
#include "../SERVICE/STD_TYPES.h"

#include "../HAL/BUTTON/BUTTON_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/BUZZER/Buzzer_Interface.h"
#include "Application.h"

enum GEARBOX_STATE {
	E_PLACEHOLDER,
	E_GEARBOX_NEUTRAL,
	E_GEARBX_DRIVE,
	E_GEARBOX_BRAKE
};
enum CCS_STATE {
	E_CCS_OFF,
	E_CCS_ON

};




void init(void){
	GPIO_SetPinDirection(RED_LED_PORT,RED_LED_PIN,OUTPUT_PIN);
	GPIO_SetPinDirection(GRN_LED_PORT,GRN_LED_PIN,OUTPUT_PIN);
	GPIO_SetPinDirection(BLU_LED_PORT,BLU_LED_PIN,OUTPUT_PIN);
	GPIO_SetPinDirection(YLW_LED_PORT,YLW_LED_PIN,OUTPUT_PIN);

	BUTTON_Init(ACL_BTN_PORT,ACL_BTN_PIN, INPUT_PIN);
	BUTTON_Init(GBX_BTN_PORT,GBX_BTN_PIN, INPUT_PIN);
	BUTTON_Init(CCS_BTN_PORT,CCS_BTN_PIN, INPUT_PIN);
	BUTTON_Init(BRK_BTN_PORT,BRK_BTN_PIN, INPUT_PIN);

	LCD_init();


}





void A_APPLICATION_VOID_ACCELERATE(void){
	uint8 temp;
	temp = BUTTON_GetValue(ACL_BTN_PORT,ACL_BTN_PIN);
	switch (temp) {
				case BTN_Pressed_State:
					LED_OnOffPositiveLogic(BLU_LED_PORT,BLU_LED_PIN,LOGIC_HIGH);

					break;
				case BTN_Released_State:
					LED_OnOffPositiveLogic(BLU_LED_PORT,BLU_LED_PIN,LOGIC_LOW);

					break;
				default:
					LED_OnOffPositiveLogic(BLU_LED_PORT,BLU_LED_PIN,LOGIC_LOW);
					break;
			}


}

void A_APPLICATION_VOID_BRAKES(void){
	uint8 temp;
	temp = BUTTON_GetValue(BRK_BTN_PORT,BRK_BTN_PIN);
	switch (temp) {
				case BTN_Pressed_State:
					LED_OnOffPositiveLogic(RED_LED_PORT,RED_LED_PIN,LOGIC_HIGH);
					break;
				case BTN_Released_State:
					LED_OnOffPositiveLogic(RED_LED_PORT,RED_LED_PIN,LOGIC_LOW);

					break;
				default:
					LED_OnOffPositiveLogic(RED_LED_PORT,RED_LED_PIN,LOGIC_LOW);
					break;
			}


}

void A_APPLICATION_VOID_CCS(void){
	uint8 temp = BUTTON_GetValue(CCS_BTN_PORT,CCS_BTN_PIN);
	static uint8 state = LOGIC_LOW;
	if (temp == BTN_Pressed_State) {
		if (state == BTN_Pressed_State) {
			GPIO_TogglePin(GRN_LED_PORT,GRN_LED_PIN);
			state = BTN_Released_State;
		}
	}
	else
	{
		state = BTN_Pressed_State;
	}
}


void A_APPLICATION_VOID_LCD_STATICS(void){
	LCD_MoveCursor(0,0);
	LCD_DisplayString((uint8*)"ACCS :");

	LCD_MoveCursor(1,0);
	LCD_DisplayString((uint8*)"Gear (R,N,D) :  ");


}



void A_APPLICATION_VOID_MAIN_GEARBOX_CHANGE(void){
	uint8 TEMP;
	TEMP = BUTTON_GetValue(GBX_BTN_PORT,GBX_BTN_PIN);
	uint8 static STATE = E_GEARBOX_NEUTRAL;
	uint8 static BTN_STATE = BTN_Pressed_State;
	if (TEMP == BTN_Pressed_State) {

		if (BTN_STATE == BTN_Pressed_State) {
			BTN_STATE = BTN_Released_State;
			if (STATE < 4) {
				STATE++;

			}else {
				STATE = E_GEARBOX_NEUTRAL;
			}
		}
	}
	else{
		BTN_STATE = BTN_Pressed_State;
		//reserved
	}
	switch (STATE) {
	case E_GEARBOX_NEUTRAL:
		LCD_MoveCursor(1,15);
		LCD_DisplayString((uint8*)" N");


		break;
	case E_GEARBX_DRIVE:

		LCD_MoveCursor(1,15);
		LCD_DisplayString((uint8*)" D");

		break;
	case E_GEARBOX_BRAKE:
		LCD_MoveCursor(1,15);
		LCD_DisplayString((uint8*)" R");

		break;
	default: STATE = E_GEARBOX_NEUTRAL;
	break;

		}
}
	void A_APPLICATION_VOID_CCS_CHANGE(void)
	{
		uint8 TEMP;
		TEMP = BUTTON_GetValue(CCS_BTN_PORT,CCS_BTN_PIN);
		uint8 static STATE2 = E_CCS_OFF;
		uint8 static BTN_STATE = BTN_Pressed_State;
		if (TEMP == BTN_Pressed_State) {

			if (BTN_STATE == BTN_Pressed_State) {
				BTN_STATE = BTN_Released_State;
				if (STATE2 < 2) {
					STATE2++;

				}else {
					STATE2 = E_CCS_OFF;
				}
			}
		}
		else{
			BTN_STATE = BTN_Pressed_State;
			//reserved
		}
		switch (STATE2) {
		case E_CCS_OFF:
			LCD_MoveCursor(0,7);
			LCD_DisplayString((uint8*)"OFF");
			break;
		case E_CCS_ON:
			LCD_MoveCursor(0,7);
			LCD_DisplayString((uint8*)"ON ");
			break;
		default: STATE2 = E_CCS_OFF;
		break;
	}

	}

	void A_APPLICATION_VOID_BUZZER_BEEP(void)
	{
		uint8 TEMP;
		TEMP = BUTTON_GetValue(ACL_BTN_PORT,ACL_BTN_PIN);
		//uint8 static STATE3 = E_CCS_OFF;
		uint8 static BTN_STATE = BTN_Pressed_State;
		if (TEMP == BTN_Pressed_State) {

			if (BTN_STATE == BTN_Pressed_State) {
				BTN_STATE = BTN_Released_State;
				H_Buzzer_Void_BuzzerOnce();

			}
		}
		else{
			BTN_STATE = BTN_Pressed_State;
			//reserved
		}

	}





