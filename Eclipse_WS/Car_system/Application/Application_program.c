/******************************************************************************
 *
 * Module: Application
 *
 * File Name: Application_program.c
 *
 * Description: source file for implementation for all functionality for Application Specefic
 *
 * Author: Hesham Shehata
 *
 *******************************************************************************/



/**************************                   INCLUDES                   **************************/

#include "Application_interface.h"
#include "Application_private.h"






/**************************                   Type Declaration                    **************************/
enum GearBox_State {N_GearBox,D_GearBox,R_GearBox , GearBox_Return_to_N};
enum ACCS_State {ACCS_Disable,ACCS_Enable};


/**************************                   Global variable                   **************************/

uint8 GearBoX_Current_State = N_GearBox;

void App_Init(void)
{
    /*  Intialize LCD   */
    LCD_init();

    /* Initialize Button Accelerate & ACCS & GearBox    */
    BUTTON_Init(Accelerate_BTN_PORT,Accelerate_BTN_PIN,INPUT_PIN);
    BUTTON_Init(ACCS_BTN_PORT,ACCS_BTN_PIN,INPUT_PIN);
    BUTTON_Init(GearBox_BTN_PORT,GearBox_BTN_PIN,INPUT_PIN);

    /*  Initialize Braking Button with EXT_INT 1    */
    INT1_init(FALLING_EDGE_TRIGGER,INPUT_PIN);

    /*  Initialize LEDS(BLUE,Red,Green,Yellow) all os them connected positive logic */
    LED_Init(Blue_LED_PORT,BLUE_LED_PIN);
    LED_Init(Red_LED_PORT,Red_LED_PIN);
    LED_Init(Green_LED_PORT,Green_LED_PIN);
    LED_Init(Yellow_LED_PORT,Yellow_LED_PIN);

    /*  Turn Of all of this led  */
    LED_OnOffPositiveLogic(Blue_LED_PORT,BLUE_LED_PIN, LED_OFF);
    LED_OnOffPositiveLogic(Red_LED_PORT,Red_LED_PIN, LED_OFF);
    LED_OnOffPositiveLogic(Green_LED_PORT,Green_LED_PIN, LED_OFF);
    LED_OnOffPositiveLogic(Yellow_LED_PORT,Yellow_LED_PIN, LED_OFF);


    /*  Intialize Bash Board for Car*/
    DashBoard_Init();
}



static void DashBoard_Init(void)
{
    /*  Display GearBox Current state  */
    LCD_MoveCursor(0,0);
    LCD_DisplayString((const uint8 * )"GearBox(N,D,R) : N");

    LCD_MoveCursor(1,0);
    LCD_DisplayString((const uint8 * )"Speed : 0");

    LCD_MoveCursor(2,0);
    LCD_DisplayString((const uint8 * )"ACCS(ON,OFF) : OFF");

    /*  To display Distance */
    // LCD_MoveCursor(3,0);
    // LCD_DisplayString((const uint8 * )"Distnace : 0");
}



void StateMachineUpdate(void)
{
    Buttons_Update();
}


void Test_B(void)
{
    uint8 ACCS_State_bTN = BUTTON_GetValue(ACCS_BTN_PORT,ACCS_BTN_PIN);
    static uint8 ACCS_BTN_IsPressed = LOGIC_LOW ;
    if(ACCS_State_bTN == LOGIC_LOW)
    {
        if(ACCS_BTN_IsPressed == LOGIC_LOW)
        {
            LED_Toggle(Green_LED_PORT,Green_LED_PIN);
            ACCS_BTN_IsPressed = LOGIC_HIGH ;
        }
    }
    else
    {
        ACCS_BTN_IsPressed = LOGIC_LOW ;
    }

}



static void Hanndle_GrearBox_N_State(void)
{
    if(GearBoX_Current_State == N_GearBox)
    {
        
    }
}

static void Buttons_Update(void)
{   

    /*  This variable used to carry if button is still pressed after last pressed as any action taken once with first step and if still press nothing happen    */
    static uint8 GearBox_IsStillPressed = NO_Condition;
    /*  Take current state for button  to check if still pressed*/
    uint8 GearBox_BTN_State = BUTTON_GetValue(GearBox_BTN_PORT,GearBox_BTN_PIN);
    
    if(GearBox_BTN_State == BTN_Pressed_State)
    {
        /*  This condition placed here to take action for button press only when pressed and if still pressed Do nothing    */
        if(GearBox_IsStillPressed == NO_Condition)
        {

            GearBox_IsStillPressed = YES_Condition ;
            GearBoX_Current_State ++ ;
            if(GearBoX_Current_State == GearBox_Return_to_N  )
            {
                GearBoX_Current_State = N_GearBox ;
                
            }
            /*  call function to update gearbox state in Dashboard*/
            DashBoard_Update_GearBox_state(GearBoX_Current_State);
        }
    }
    else
    {
        /*  Enter this state when Button released*/
        GearBox_IsStillPressed = NO_Condition ;
    }
  




    /*  This variable used to carry if button is still pressed after last pressed as any action taken once with first step and if still press nothing happen    */
    static uint8 ACCS_IsStillPressed = NO_Condition;
    /*  Take current state for button  to check if still pressed*/
    uint8 ACCS_BTN_State = BUTTON_GetValue(ACCS_BTN_PORT,ACCS_BTN_PIN);
    
    if(ACCS_BTN_State == BTN_Pressed_State)
    {
        /*  This condition placed here to take action for button press only when pressed and if still pressed Do nothing    */
        if(ACCS_IsStillPressed == NO_Condition)
        {

          
        }
    }
    else
    {
        /*  Enter this state when Button released*/
        ACCS_IsStillPressed = NO_Condition ;
    }

}


static void DashBoard_Update_GearBox_state(uint8 GearBox_state)
{
    /*  Array carry All Characters For GearBox as make display easier using index*/
    uint8 GearBox_Characyer [] = {'N','D','R'};
    /*  Go to index that display current GearBox state*/
    LCD_MoveCursor(0,17);
    /*  Edit it state with new state given to function*/
    LCD_DisplayCharacter(GearBox_Characyer[GearBox_state]);
}