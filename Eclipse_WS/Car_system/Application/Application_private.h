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
*   @brief : this function used to initialize what will be displayed in LCD 
*   @args  void
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
static void DashBoard_Init(void);



static void Buttons_Update(void);

/*
*   @brief : this function used to to Update only state of GearBox in DashBoard
*   @args  void
*   @return: no return
*   @synchronous / Asynchronous : Synchronous
*   @ Reentrant / Non Reentrant : Reentrant
*/
static void DashBoard_Update_GearBox_state(uint8 GearBox_state);