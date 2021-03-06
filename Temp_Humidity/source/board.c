
/*
*------------------------------------------------------------------------------
* device.c
*
* Board specipic drivers module(BSP)
*
*
* The copyright notice above does not evidence any
* actual or intended publication of such source code.
*
*------------------------------------------------------------------------------
*/


/*
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/


#include "board.h"
#include "config.h"
#include "typedefs.h"




/*
*------------------------------------------------------------------------------
* Private Defines
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Macros
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Data Types
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Variables
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Variables (static)
*------------------------------------------------------------------------------
*/

static BOOL ledState;

/*
*------------------------------------------------------------------------------
* Public Constants
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Constants (static)
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Function Prototypes (static)
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Functions
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* void InitializeBoard(void)

* Summary	: This function configures all i/o pin directions
*
* Input		: None
*
* Output	: None
*
*------------------------------------------------------------------------------
*/
void BRD_init(void)
{
	
	ADCON1= 0x0D;

	// Internal oscillator setup
	OSCCON |= 0X70; 		//internal oscillator 8MHz
	OSCTUNEbits.PLLEN = 1;	//PLL Enable

	TX_EN_DIRECTION = PORT_OUT;

	TEMP_ANALOG_INPUT_DIRECTION = 1;	//Set direction for analog pin

	HUM_ANALOG_INPUT_DIRECTION = 1;	//Set direction for analog pin

	
	DISPLAY_PORT_DIRECTION = 0x00;	// Segment Data port


	DIGIT_SEL_A_DIRECTION = PORT_OUT;		// Digit Selection
	
	DIGIT_SEL_B_DIRECTION = PORT_OUT;
	
	DIGIT_SEL_C_DIRECTION = PORT_OUT;
	
	DIGIT_SEL_D_DIRECTION = PORT_OUT;

	DIGIT_SEL_E_DIRECTION = PORT_OUT;

	DIGIT_SEL_F_DIRECTION = PORT_OUT;


	GREEN_LAMP_DIRECTION = PORT_OUT;
	RED_LAMP_DIRECTION	 = PORT_OUT;

	HEART_BEAT_DIRECTION = PORT_OUT;

	RESET_SWITCH_DIRECTION = 1;
	
	GREEN_LAMP = 0;				// Turn ON green lamp
	RED_LAMP = 0;				// Turn OFF red lamp
}



/*
*------------------------------------------------------------------------------
* Private Functions
*------------------------------------------------------------------------------
*/

/*
*  End of device.c
*/
