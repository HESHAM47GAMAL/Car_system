/*
 * Application.h
 *
 *  Created on: Mar 7, 2024
 *      Author: moham
 */

#ifndef APPLICATION_APPLICATION_H_
#define APPLICATION_APPLICATION_H_

/*--------------------------------------------------------------------------------------------*/
/*   HASH DEFINES   */
/*--------------------------------------------------------------------------------------------*/

#define ACL_BTN_PORT         PORTD_ID
#define ACL_BTN_PIN          PIN7_ID

#define BRK_BTN_PORT         PORTD_ID
#define BRK_BTN_PIN          PIN3_ID

#define ACCS_BTN_PORT        PORTD_ID
#define ACCS_BTN_PIN         PIN5_ID

#define GBX_BTN_PORT         PORTD_ID
#define GBX_BTN_PIN          PIN6_ID

#define BLU_LED_PORT         PORTA_ID
#define BLU_LED_PIN          PIN5_ID

#define RED_LED_PORT         PORTB_ID
#define RED_LED_PIN          PIN7_ID

#define GRN_LED_PORT         PORTA_ID
#define GRN_LED_PIN          PIN4_ID

#define YLW_LED_PORT         PORTA_ID
#define YLW_LED_PIN          PIN6_ID





#define BTN_Pressed_State           LOGIC_LOW
#define BTN_Released_State          LOGIC_HIGH

#define YES_Condition               LOGIC_HIGH
#define NO_Condition                LOGIC_LOW




/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/

void init(void);
void A_APPLICATION_VOID_LCD_STATICS(void);


uint8 A_APPLICATION_UINT8_BTN_CHECK(uint8, uint8);
void A_APPLICATION_VOID_BTN_TGL_ACTION(uint8, uint8);

void A_APPLICATION_VOID_BRAKE(uint8);
void A_APPLICATION_VOID_ACCS(void);
void A_APPLICATION_VOID_ACCS_TGL(uint8,uint8);
void A_APPLICATION_VOID_BTN_ACTION(void);
void A_APPLICATION_VOID_BUZZER_BEEP_ACL(uint8, uint8);
void A_APPLICATION_VOID_BUZZER_BEEP_BRK(uint8, uint8);
void A_APPLICATION_VOID_BUZZER_BEEP_ACCS(uint8, uint8);
void A_APPLICATION_VOID_BUZZER_BEEP_GEAR(uint8, uint8);
void A_APPLICATION_VOID_MAIN_GEARBOX_CHANGE(void);
void A_APPLICATION_VOID_BRAKE_ON(void);
void A_APPLICATION_VOID_BRAKE_OFF(void);
void A_APPLICATION_VOID_LCD_DISTANCE_SHOW(void);
void A_APPLICATION_VOID_LCD_DISTANCE_ERASE(void);
void A_APPLICATION_VOID_ACCS_DISTANCE_READ(void);


void A_APPLICATION_VOID_ACCS_LCD(void);





#endif /* APPLICATION_APPLICATION_H_ */
