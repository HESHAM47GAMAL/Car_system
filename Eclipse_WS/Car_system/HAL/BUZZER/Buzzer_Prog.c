/*
 * Buzzer_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "Buzzer_Config.h"
#include "Buzzer_Interface.h"

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Buzzer_Void_BuzzerInit(void)
{
	GPIO_SetPinDirection(BUZZER_PORT,BUZZER_PIN, OUTPUT_PIN);
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Buzzer_Void_BuzzerOn(void)
{

	GPIO_WritePin(BUZZER_PORT,BUZZER_PIN,LOGIC_HIGH);
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Buzzer_Void_BuzzerOff(void)
{
	GPIO_WritePin(BUZZER_PORT,BUZZER_PIN,LOGIC_LOW);
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Buzzer_Void_BuzzerTog(void)
{
	GPIO_TogglePin(BUZZER_PORT,BUZZER_PIN);
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Buzzer_Void_BuzzerOnce(void)
{
	GPIO_WritePin(BUZZER_PORT,BUZZER_PIN,LOGIC_HIGH);
	_delay_ms(BUZZER_ON_TIME);
	GPIO_WritePin(BUZZER_PORT,BUZZER_PIN,LOGIC_LOW);

}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Buzzer_Void_BuzzerTwice(void)
{
	GPIO_WritePin(BUZZER_PORT,BUZZER_PIN,LOGIC_HIGH);
	_delay_ms(BUZZER_ON_TIME);
	GPIO_WritePin(BUZZER_PORT,BUZZER_PIN,LOGIC_LOW);
	_delay_ms(BUZZER_OFF_TIME);
	GPIO_WritePin(BUZZER_PORT,BUZZER_PIN,LOGIC_HIGH);
	_delay_ms(BUZZER_ON_TIME);
	GPIO_WritePin(BUZZER_PORT,BUZZER_PIN,LOGIC_LOW);
}
