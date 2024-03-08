/*
 * Application.h
 *
 *  Created on: Mar 7, 2024
 *      Author: moham
 */

#ifndef APPLICATION_APPLICATION_H_
#define APPLICATION_APPLICATION_H_

#include "../HAL/BUTTON/BUTTON_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/LCD/LCD_interface.h"

#include "../MCAL/EXT_INT/EXT_INT_interface.h"



#define Accelerate_BTN_PORT         PORTD_ID
#define Accelerate_BTN_PIN          PIN7_ID

#define Braking_BTN_PORT            PORTD_ID
#define Braking_BTN_PIN             PIN3_ID

#define ACCS_BTN_PORT               PORTD_ID
#define ACCS_BTN_PIN                PIN5_ID

#define GearBox_BTN_PORT            PORTD_ID
#define GearBox_BTN_PIN             PIN6_ID

#define Blue_LED_PORT               PORTA_ID
#define BLUE_LED_PIN                PIN5_ID

#define Red_LED_PORT                PORTB_ID
#define Red_LED_PIN                 PIN7_ID

#define Green_LED_PORT              PORTA_ID
#define Green_LED_PIN               PIN4_ID

#define Yellow_LED_PORT             PORTA_ID
#define Yellow_LED_PIN              PIN6_ID


/*
*   @brief : this function used to initailize what will displayed in LCD and configure Buttons and Leds 
*   @args  void
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
void App_Init(void);

/*
*   @brief : this function used to initialize what will be displayed in LCD 
*   @args  void
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
void DashBoard_Init(void);

void StateMachineUpdate(void);

void Test_B(void);


#endif /* APPLICATION_APPLICATION_H_ */
