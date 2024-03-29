 /******************************************************************************
 *
 * Module: Application
 *
 * File Name: Application_private.h
 *
 * Description: contain function Prototype for static functions
 * 
 * Author: Hesham Shehata
 *
 *******************************************************************************/

/**************************                   INCLUDES                   **************************/
#include "../SERVICE/STD_TYPES.h"

/**************************                   Function Prototype                   **************************/


/*
*   @brief : this function used to handle All action may happen In N GearBox mode
*   @args  void
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
static void Hanndle_GrearBox_N_State(void);


/*
*   @brief : this function used to handle All action may happen In R GearBox mode
*   @args  void
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
static void Hanndle_GrearBox_R_State(void);


/*
*   @brief : this function used to handle Adaptive Cruise control sysytem will all condition available in statemachine 
*   @args  void
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
static void Hanndle_GrearBox_D_State(void);



/*
*   @brief : this function used to initialize what will be displayed in DashBoard(LCD) 
*   @args  void
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
// static void DashBoard_Init(void);


/*
*   @brief : this function used to get update of Buttons 
*   @args  void
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
static void Buttons_Update(void);


/*
*   @brief : this function used to to Update only state of GearBox in DashBoard
*   @arg1  GearBox_state : state of GearBox that will be updated in Dashboard
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
// static void DashBoard_Update_GearBox_state(uint8 GearBox_state);


/*
*   @brief : this function used to to Update only state of Adaptive Cruise Control System in DashBoard
*   @args  void
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
// static void DashBoard_Update_ACCS_State(uint8 ACCS_state);


/*
*   @brief : this function used to Show only "Distance : " in LCD
*   @args  void
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
// static void DashBoard_DistanceShow(void); 


/*
*   @brief : this function used to hide all data in last row by display white space "                  "
*   @args  void
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
// static void DashBoard_DistanceHide(void);



/*
*   @brief : this function is program that will be called (ISR) when Braking Button pressed 
*   @args  void
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
static void Braking_Button_Handling(void);


/*
*   @brief : this function is used to set buzzer high and initialize timeout period 
*   @args  void
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
static void Buzzer_NotifySound(void);

/*
*   @brief : this function is program that will be called (ISR) when Timeout happen as turn buzzer off
*   @args  void
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
void Buzzer_timeOutOff(void);




/*
*   @brief : this function used to get last value from Potentiometer and Display it
*   @args  void
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
static void ACCS_CatchDistance(void);


static void ACCS_DicisionTake(void);

/*  This only function used with brake ISR that to make push to it in stack and when same ISR happen make context switch and return to function */
/*  Try to Ask Eng Mohamed Helmy    */

void tessst (void);




/*  For Small LCD */
static void DashBoard_Init_small(void);
static void DashBoard_Update_GearBox_state_small(uint8 GearBox_state);
static void DashBoard_Update_ACCS_State_small(uint8 ACCS_state);
static void DashBoard_DistanceShow_small(void);
static void DashBoard_DistanceHide_small(void);
static void DashBoard_UpdateSpeed(void);
