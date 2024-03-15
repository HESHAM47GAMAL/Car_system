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

#include "../MCAL/EXT_INT/EXT_INT_interface.h"
#include "Application.h"

enum GEARBOX_STATE {
	E_PLACEHOLDER,
	E_GEARBOX_NEUTRAL,
	E_GEARBOX_DRIVE,
	E_GEARBOX_REVERSE
};
enum ACCS_STATE {
	E_ACCS_OFF,
	E_ACCS_ON

};
enum CAR_STATE {
	E_CAR_IS_STOPPED,
	E_CAR_IS_ACCELERATING,
	E_CAR_IS_BRAKING
};

/*--------------------------------------------------------------------------------------------*/
/*   						GLOBAL VARIABLES												  */
/*--------------------------------------------------------------------------------------------*/

uint8 ACCS_CURRENT_STATE = E_ACCS_OFF;
uint8 GEARBOX_CURRENT_STATE = E_GEARBOX_NEUTRAL;
uint8 CAR_CURRENT_STATE = E_CAR_IS_STOPPED;

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

	/*enable global interrupt manually*/
	SET_BIT(SREG,7);






}
/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR ACCELERATION,
 * THIS FUNCTION MAKES THE CAR ACCELERATE .
--------------------------------------------------------------------------------------------*/

void A_APPLICATION_VOID_ACCELERATE(uint8 STATE){
	LED_OnOffPositiveLogic(BLU_LED_PORT,BLU_LED_PIN,STATE);
	A_APPLICATION_VOID_BUZZER_BEEP_ACL(ACL_BTN_PORT,ACL_BTN_PIN);

}


/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR ACCELERATION,
 * THIS FUNCTION MAKES THE CAR BRAKE INTERRUPT .
--------------------------------------------------------------------------------------------*/

void A_APPLICATION_VOID_BRAKE_ON(void){
	LED_OnOffPositiveLogic(RED_LED_PORT,RED_LED_PIN,LOGIC_HIGH);
	A_APPLICATION_VOID_BUZZER_BEEP_BRK(BRK_BTN_PORT,BRK_BTN_PIN);
}
/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR ACCELERATION,
 * THIS FUNCTION MAKES THE CAR BRAKE INTERRUPT .
--------------------------------------------------------------------------------------------*/

void A_APPLICATION_VOID_BRAKE_OFF(void){
	LED_OnOffPositiveLogic(RED_LED_PORT,RED_LED_PIN,LOGIC_LOW);
	A_APPLICATION_VOID_BUZZER_BEEP_BRK(BRK_BTN_PORT,BRK_BTN_PIN);
}
/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR ACCELERATION,
 * THIS FUNCTION MAKES THE CAR ACCELERATE .
--------------------------------------------------------------------------------------------*/

void A_APPLICATION_VOID_ACCS(void){
	A_APPLICATION_VOID_ACCS_TGL(ACCS_BTN_PORT,ACCS_BTN_PIN);

}

/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR BOTTON CHECK,
 * THIS FUNCTION CHECKS WHETER A PUSH BUTTON IS PRESSED OR NO, HAS 2 ARGUMENTS, BTN PORT AND BTN PIN .
 * RETURNS 1 IF PRESSED, 0 WHEN RELEASED		  */
/*--------------------------------------------------------------------------------------------*/


uint8 A_APPLICATION_UINT8_BTN_CHECK(uint8 BTN_PORT, uint8 BTN_PIN){
	uint8 TEMP = 0;
	TEMP = BUTTON_GetValue(BTN_PORT,BTN_PIN);
	uint8 static BTN_STATE = BTN_Pressed_State;
	if (TEMP == BTN_Pressed_State) {

		if (BTN_STATE == BTN_Pressed_State) {
			//do true here
			BTN_STATE = BTN_Released_State;

			return 1;
		}
	}
	else{
		//do false here
		BTN_STATE = BTN_Pressed_State;

		return 0;
	}
}





/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR BUTTON TOGGLE ACTION,
 * THIS FUNCTION TAKES ACTION OF A TOGGLE WHEN A PUSH BUTTON IS PRESSED, ACCEPTS THE BUTTON PORT AND PIN .		  */
/*--------------------------------------------------------------------------------------------*/


void A_APPLICATION_VOID_BTN_TGL_ACTION(uint8 BTN_PORT, uint8 BTN_PIN){
	uint8  static BTN_LAST_STATE = 0;
	uint8  static BTN_STATE = 0;
	BTN_STATE = BUTTON_GetValue(BTN_PORT,BTN_PIN);
	if (BTN_STATE != BTN_LAST_STATE) {

		if (BTN_STATE == BTN_Pressed_State) {
			//do true here



		}
	}BTN_LAST_STATE = BTN_STATE;

}

/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR ACCS TOGGLE ONLY + ITS LED,
 * THIS FUNCTION TOGGLES LED OF ACCS AND ITS BUZZER .		  */
/*--------------------------------------------------------------------------------------------*/


void A_APPLICATION_VOID_ACCS_TGL(uint8 BTN_PORT, uint8 BTN_PIN){
	uint8 static BTN_LAST_STATE = 0;
	uint8 static BTN_STATE = 0;
	BTN_STATE = BUTTON_GetValue(BTN_PORT,BTN_PIN);
	if (BTN_STATE != BTN_LAST_STATE) {

		if (BTN_STATE == BTN_Pressed_State) {
			//do true here
			if (!(GEARBOX_CURRENT_STATE == E_GEARBOX_REVERSE)) {
				LED_Toggle(GRN_LED_PORT,GRN_LED_PIN);
				A_APPLICATION_VOID_BUZZER_BEEP_ACCS(ACCS_BTN_PORT,ACCS_BTN_PIN);
				ACCS_CURRENT_STATE = E_ACCS_ON;
			}


		}
		else
		{
			A_APPLICATION_VOID_BUZZER_BEEP_ACCS(ACCS_BTN_PORT,ACCS_BTN_PIN);
			ACCS_CURRENT_STATE = E_ACCS_OFF;

		}
	}BTN_LAST_STATE = BTN_STATE;

}


/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR BUTTON ACTIONS,
 * THIS FUNCTION CHECKS ALL 4 PUSH BUTTONS AND THEN PERFORMS THEIR ACTIONS .							  */
/*--------------------------------------------------------------------------------------------*/

void A_APPLICATION_VOID_BTN_ACTION(void){
	//check for acceleration press
	if (A_APPLICATION_UINT8_BTN_CHECK(ACL_BTN_PORT,ACL_BTN_PIN)) {
		A_APPLICATION_VOID_ACCELERATE(ON);
		CAR_CURRENT_STATE = E_CAR_IS_ACCELERATING;


	} else {
		A_APPLICATION_VOID_ACCELERATE(OFF);
	}
	//check for brake press
	if (A_APPLICATION_UINT8_BTN_CHECK(BRK_BTN_PORT,BRK_BTN_PIN)) {
		INT1_init(RISING_EDGE_TRIGGER,INPUT_PIN);
		INT1_SetCallBack(A_APPLICATION_VOID_BRAKE_OFF);


	} else {
		INT1_init(FALLING_EDGE_TRIGGER,INPUT_PIN);
		INT1_SetCallBack(A_APPLICATION_VOID_BRAKE_ON);
		CAR_CURRENT_STATE = E_CAR_IS_BRAKING;


	}
	//check for accs press
	if (A_APPLICATION_UINT8_BTN_CHECK(ACCS_BTN_PORT,ACCS_BTN_PIN)) {
		A_APPLICATION_VOID_ACCS_TGL(ACCS_BTN_PORT,ACCS_BTN_PIN);
		A_APPLICATION_VOID_ACCS_LCD();

	}else {
		A_APPLICATION_VOID_ACCS_TGL(ACCS_BTN_PORT,ACCS_BTN_PIN);
	}
	//check for gear press
	if (A_APPLICATION_UINT8_BTN_CHECK(GBX_BTN_PORT,GBX_BTN_PIN)) {
		void A_APPLICATION_VOID_MAIN_GEARBOX_CHANGE();
	}else {
		//
	}
}

/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR BUZZER BEEP,
 * THIS FUNCTION MAKES THE BUZZER BEEPS ONE FOR EVERY PUSH BUTTON PRESS.
 * THIS FUNCTION ACCEPTS TWO ARGUMENT, THE PORT OF THE BUTTON AND THE PIN OF THE BUTTON */
/*--------------------------------------------------------------------------------------------*/
void A_APPLICATION_VOID_BUZZER_BEEP_ACL(uint8 BTN_PORT, uint8 BTN_PIN)
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
	else {
		BTN_STATE = BTN_Pressed_State;
	}



}
void A_APPLICATION_VOID_BUZZER_BEEP_BRK(uint8 BTN_PORT, uint8 BTN_PIN)
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
	else {
		BTN_STATE = BTN_Pressed_State;
	}



}
void A_APPLICATION_VOID_BUZZER_BEEP_ACCS(uint8 BTN_PORT, uint8 BTN_PIN)
{
	uint8 TEMP;
	TEMP = BUTTON_GetValue(BTN_PORT,BTN_PIN);
	uint8 static BTN_STATE = BTN_Pressed_State;
	if (TEMP == BTN_Pressed_State) {

		if (BTN_STATE == BTN_Pressed_State) {
			BTN_STATE = BTN_Released_State;
			LCD_MoveCursor(0,0);
			LCD_DisplayString((uint8*)"ACCS : ON ");
			H_Buzzer_Void_BuzzerOnce();
		}
	}
	else {
		BTN_STATE = BTN_Pressed_State;
	}
}

void A_APPLICATION_VOID_ACCS_LCD(void)
{
	uint8 TEMP;
	TEMP = GPIO_ReadPin(GRN_LED_PORT,GRN_LED_PIN);
	uint8 static BTN_STATE = BTN_Pressed_State;
	if (TEMP == BTN_Pressed_State) {

		if (BTN_STATE == BTN_Pressed_State) {
			BTN_STATE = BTN_Released_State;
			LCD_MoveCursor(0,0);
			LCD_DisplayString((uint8*)"ACCS : OFF ");
			ACCS_CURRENT_STATE = E_ACCS_OFF;
		}
	}
	else {
		BTN_STATE = BTN_Pressed_State;
		LCD_MoveCursor(0,0);
		LCD_DisplayString((uint8*)"ACCS : ON");
		ACCS_CURRENT_STATE = E_ACCS_ON;
	}


}

void A_APPLICATION_VOID_BUZZER_BEEP_GEAR(uint8 BTN_PORT, uint8 BTN_PIN)
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
	else {
		BTN_STATE = BTN_Pressed_State;
	}



}


/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR LCD STATICS,
 * THIS FUNCTION DISPLAYS THE STATIC (NON-CHANGING STUFF) DISPLAYED ON THE LCD SCREEN .		  */
/*--------------------------------------------------------------------------------------------*/

void A_APPLICATION_VOID_LCD_STATICS(void){
	LCD_MoveCursor(0,0);
	LCD_DisplayString((uint8*)"ACCS : OFF");

	LCD_MoveCursor(1,0);
	LCD_DisplayString((uint8*)"Gear (R,N,D) : N");

	LCD_MoveCursor(2,0);
	LCD_DisplayString((uint8*)"Distance : ");

}

/*--------------------------------------------------------------------------------------------*/
/*   						FUNCTION BODY FOR HEARBOX CHANGE,
 * THIS FUNCTION CHANGES THE GEAR ON EACH BUTTON PRESS OR TOGGLE .							  */
/*--------------------------------------------------------------------------------------------*/

void A_APPLICATION_VOID_MAIN_GEARBOX_CHANGE(void){
	// calling main BTN action function here
	A_APPLICATION_VOID_BTN_ACTION();
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
		//if (A_APPLICATION_UINT8_BTN_CHECK(BRK_BTN_PORT,BRK_BTN_PIN))
		if (!GPIO_ReadPin(BRK_BTN_PORT,BRK_BTN_PIN)&&(!GPIO_ReadPin(GBX_BTN_PORT,GBX_BTN_PIN))){
			A_APPLICATION_VOID_ACCS();

			LCD_MoveCursor(1,15);
			LCD_DisplayString((uint8*)"N");
			A_APPLICATION_VOID_BUZZER_BEEP_GEAR(GBX_BTN_PORT,GBX_BTN_PIN);
			GEARBOX_CURRENT_STATE = E_GEARBOX_NEUTRAL;
			CAR_CURRENT_STATE = E_CAR_IS_STOPPED;

		}



		break;
	case E_GEARBOX_DRIVE:
		if (!GPIO_ReadPin(BRK_BTN_PORT,BRK_BTN_PIN)&&(!GPIO_ReadPin(GBX_BTN_PORT,GBX_BTN_PIN))) {

			LCD_MoveCursor(1,15);
			LCD_DisplayString((uint8*)"D");

			A_APPLICATION_VOID_BUZZER_BEEP_GEAR(GBX_BTN_PORT,GBX_BTN_PIN);
			GEARBOX_CURRENT_STATE = E_GEARBOX_DRIVE;
		}
		break;
	case E_GEARBOX_REVERSE:
		if (!GPIO_ReadPin(BRK_BTN_PORT,BRK_BTN_PIN)&&(!GPIO_ReadPin(GBX_BTN_PORT,GBX_BTN_PIN))) {


			LCD_MoveCursor(1,15);
			LCD_DisplayString((uint8*)"R");

			LCD_MoveCursor(0,0);
			LCD_DisplayString((uint8*)"ACCS : OFF");
			GEARBOX_CURRENT_STATE = E_GEARBOX_REVERSE;

			GPIO_WritePin(GRN_LED_PORT,GRN_LED_PIN,LOGIC_LOW);


			A_APPLICATION_VOID_BUZZER_BEEP_GEAR(GBX_BTN_PORT,GBX_BTN_PIN);
		}
		break;
	default: STATE = E_GEARBOX_NEUTRAL;
	break;

	}
}



