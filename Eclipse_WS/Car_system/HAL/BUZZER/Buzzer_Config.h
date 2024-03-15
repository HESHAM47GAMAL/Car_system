/*
 * Buzzer_Config.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_BUZZER_BUZZER_CONFIG_H_
#define HAL_BUZZER_BUZZER_CONFIG_H_

/*--------------------------------------------------------------------------------------------*/
/*   SELECT MICROCONTROLERS PINS   */
/*--------------------------------------------------------------------------------------------*/
#define BUZZER_PORT            PORTC_ID
#define BUZZER_PIN			   PIN6_ID

/*--------------------------------------------------------------------------------------------*/
/*   SELECT LED BUZZER ON TIME IN MILLI SECONDS   */
/*--------------------------------------------------------------------------------------------*/
#define BUZZER_ON_TIME         500

/*--------------------------------------------------------------------------------------------*/
/*   SELECT LED BUZZER OFF TIME IN MILLI SECONDS   */
/*--------------------------------------------------------------------------------------------*/
#define BUZZER_OFF_TIME        60

#endif /* HAL_BUZZER_BUZZER_CONFIG_H_ */