#include "board.h"
#include "timer.h"
#include "adc_ide.h"
#include "uart_driver.h"
#include "exterInterrupts.h"

/*
 * For PIC18xxxx devices, the low interrupt vector is found at 000000018h.
 * Change the default code section to the absolute code section named
 * low_vector located at address 0x18.
 */


#pragma code high_vector = 0x08
void high_interrupt (void)
{
	/*
   	* Inline assembly that will jump to the ISR.
   	*/

	if(INTCONbits.TMR0IF == 1)
	{
  		_asm GOTO TMR0_ISR _endasm
	}

	if(PIR1bits.TMR1IF == 1)
	{
		_asm GOTO TMR1_ISR _endasm
	}

	if(PIR1bits.ADIF == 1)
	{
		_asm GOTO ADC_interrupt _endasm
	}


	if(PIR1bits.RCIF == 1)
	{
		_asm GOTO UartReceiveHandler _endasm
	}
/*	
	if(INTCONbits.RBIF == 1)
	{
		_asm goto extInterruptHandler _endasm
	}
*/
}
/*
#pragma code low_vector=0x18
void low_interrupt (void)
{
	if(PIR1bits.TMR1IF == 1)
	{
		_asm GOTO timer1ISR _endasm
	}
}
*/
/*
*------------------------------------------------------------------------------
* void EnableInterrupts(void)

* Summary	: Enable interrupts and related priorities
*
* Input		: None
*
* Output	: None
*
*------------------------------------------------------------------------------
*/
void EnableInterrupts(void)
{
	// Enable interrupt priority
  	RCONbits.IPEN = 1;
 	// Enable all high priority interrupts
  	INTCONbits.GIEH = 1;
}