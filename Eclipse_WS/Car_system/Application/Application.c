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
	E_GEARBOX_REVERSE
};
enum CCS_STATE {
	E_CCS_OFF,
	E_CCS_ON

};


/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR INITIALIZE FUNCITON,
 * THIS FUNCTION INITIALIZED WHAT NEEDED TO BE INITIALIZED THROUGHOUT THE WHOLE SYSTEM .	  */
/*--------------------------------------------------------------------------------------------*/

void init(void){
	GPIO_SetPinDirection(RED_LED_PORT,RED_LED_PIN,OUTPUT_PIN);
	GPIO_SetPinDirection(GRN_LED_PORT,GRN_LED_PIN,OUTPUT_PIN);
	GPIO_SetPinDirection(BLU_LED_PORT,BLU_LED_PIN,OUTPUT_PIN);
	GPIO_SetPinDirection(YLW_LED_PORT,YLW_LED_PIN,OUTPUT_PIN);

	BUTTON_Init(ACL_BTN_PORT,ACL_BTN_PIN, INPUT_PIN);
	BUTTON_Init(GBX_BTN_PORT,GBX_BTN_PIN, INPUT_PIN);
	BUTTON_Init(ACCS_BTN_PORT,ACCS_BTN_PIN, INPUT_PIN);
	BUTTON_Init(BRK_BTN_PORT,BRK_BTN_PIN, INPUT_PIN);

	LCD_init();


}


/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR ACCELERATION PRESSED,
 * THIS FUNCTION LIGHTS UP THE BLUE LED ON THE ACCELERATION BUTTON PRESS .					  */
/*--------------------------------------------------------------------------------------------*/


void A_APPLICATION_VOID_ACCELERATE(void){
	uint8 TEMP;
	TEMP = BUTTON_GetValue(ACL_BTN_PORT,ACL_BTN_PIN);
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
	switch (TEMP) {
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
/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR BRAKES PRESSED,
 * THIS FUNCTION LIGHTS UP THE RED LED ON BRAKE PUSH BUTTON PRESS .							  */
/*--------------------------------------------------------------------------------------------*/
void A_APPLICATION_VOID_BRAKES(void){
	uint8 TEMP;
	TEMP = BUTTON_GetValue(BRK_BTN_PORT,BRK_BTN_PIN);
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
	switch (TEMP) {
				case BTN_Pressed_State:
					LED_OnOffPositiveLogic(RED_LED_PORT,RED_LED_PIN,LOGIC_HIGH);
					A_APPLICATION_VOID_BUZZER_BEEP(BRK_BTN_PORT,BRK_BTN_PIN);
					break;
				case BTN_Released_State:
					LED_OnOffPositiveLogic(RED_LED_PORT,RED_LED_PIN,LOGIC_LOW);
					A_APPLICATION_VOID_BUZZER_BEEP(BRK_BTN_PORT,BRK_BTN_PIN);
					break;
				default:
					LED_OnOffPositiveLogic(RED_LED_PORT,RED_LED_PIN,LOGIC_LOW);
					break;
			}


}

/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR TOGGLE BASICALLY,
 * THIS FUNCTION TOGGLES THE ACCS ON AND OFF WITH ITS OWN LED .							  */
/*--------------------------------------------------------------------------------------------*/

//void A_APPLICATION_VOID_CCS(void){

//	uint8 temp = BUTTON_GetValue(CCS_BTN_PORT,CCS_BTN_PIN);
//	static uint8 state = LOGIC_LOW;
//	if (temp == BTN_Pressed_State) {
//		if (state == BTN_Pressed_State) {
//			GPIO_TogglePin(GRN_LED_PORT,GRN_LED_PIN);
//			state = BTN_Released_State;
//		}
//	}
//	else
//	{
//		state = BTN_Pressed_State;
//	}
//}




/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR LCD STATICS,
 * THIS FUNCTION DISPLAYS THE STATIC (NON-CHANGING STUFF) DISPLAYED ON THE LCD SCREEN .							  */
/*--------------------------------------------------------------------------------------------*/

void A_APPLICATION_VOID_LCD_STATICS(void){
	LCD_MoveCursor(0,0);
	LCD_DisplayString((uint8*)"ACCS : OFF");

	LCD_MoveCursor(1,0);
	LCD_DisplayString((uint8*)"Gear (R,N,D) :  ");

	LCD_MoveCursor(2,0);
	LCD_DisplayString((uint8*)"Speed : ");




}
/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR LCD DISTANCE DISPLAY ONLY,
 * SINCE THIS FUNCTION IS NEEDED ONLY IN DRIVE AND IN REVERSE, NOT NEEDED IN NEUTRAL.		 */
/*--------------------------------------------------------------------------------------------*/
void A_APPLICATION_VOID_LCD_DISTANCE(void){
	LCD_MoveCursor(3,0);
	LCD_DisplayString((uint8*)"Distance : ");

}

/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR HEARBOX CHANGE,
 * THIS FUNCTION CHANGES THE GEAR ON EACH BUTTON PRESS OR TOGGLE .							  */
/*--------------------------------------------------------------------------------------------*/

void A_APPLICATION_VOID_MAIN_GEARBOX_CHANGE(void){
	uint8 TEMP;
	TEMP = BUTTON_GetValue(GBX_BTN_PORT,GBX_BTN_PIN);
	uint8 static STATE = E_GEARBOX_NEUTRAL;
	uint8 static BTN_STATE = BTN_Pressed_State;
	if (TEMP == BTN_Pressed_State) {

		if (BTN_STATE == BTN_Pressed_State) {
			BTN_STATE = BTN_Released_State;
			A_APPLICATION_VOID_BUZZER_BEEP(GBX_BTN_PORT,GBX_BTN_PIN);

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
		A_APPLICATION_VOID_ACCELERATE();
		A_APPLICATION_VOID_BRAKES();
		A_APPLICATION_VOID_ACCS_CHANGE();

		LCD_MoveCursor(1,15);
		LCD_DisplayString((uint8*)" N");
		A_APPLICATION_VOID_BUZZER_BEEP(GBX_BTN_PORT,GBX_BTN_PIN);
		LCD_MoveCursor(3,0);
		LCD_DisplayString((uint8*)"          ");



		break;
	case E_GEARBX_DRIVE:
		A_APPLICATION_VOID_ACCELERATE();
		A_APPLICATION_VOID_BRAKES();
		A_APPLICATION_VOID_ACCS_CHANGE();

		LCD_MoveCursor(1,15);
		LCD_DisplayString((uint8*)" D");
		A_APPLICATION_VOID_LCD_DISTANCE();
		A_APPLICATION_VOID_BUZZER_BEEP(GBX_BTN_PORT,GBX_BTN_PIN);
		break;
	case E_GEARBOX_REVERSE:
		A_APPLICATION_VOID_ACCELERATE();
		A_APPLICATION_VOID_BRAKES();


		LCD_MoveCursor(1,15);
		LCD_DisplayString((uint8*)" R");
		A_APPLICATION_VOID_LCD_DISTANCE();
		A_APPLICATION_VOID_BUZZER_BEEP(GBX_BTN_PORT,GBX_BTN_PIN);

		break;
	default: STATE = E_GEARBOX_NEUTRAL;
	break;

		}
}

/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR ACCS CHANGE,
 * THIS FUNCTION TOGGLES THE ACCS ON AND OFF WITH ITS OWN LED .							  */
/*--------------------------------------------------------------------------------------------*/
	void A_APPLICATION_VOID_ACCS_CHANGE(void)
	{
		uint8 TEMP;
		TEMP = BUTTON_GetValue(ACCS_BTN_PORT,ACCS_BTN_PIN);
		uint8 static STATE2 = E_CCS_OFF;
		uint8 static BTN_STATE = BTN_Pressed_State;
		if (TEMP == BTN_Pressed_State) {

			if (BTN_STATE == BTN_Pressed_State) {
				A_APPLICATION_VOID_BUZZER_BEEP(ACCS_BTN_PORT,ACCS_BTN_PIN);
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
/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR BUZZER BEEP,
 * THIS FUNCTION MAKES THE BUZZER BEEPS ONE FOR EVERY PUSH BUTTON PRESS.
 * THIS FUNCTION ACCEPTS TWO ARGUMENT, THE PORT OF THE BUTTON AND THE PIN OF THE BUTTON */
/*--------------------------------------------------------------------------------------------*/
	void A_APPLICATION_VOID_BUZZER_BEEP(uint8 BTN_PORT, uint8 BTN_PIN)
	{
		uint8 TEMP;
		TEMP = BUTTON_GetValue(BTN_PORT,BTN_PIN);
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





