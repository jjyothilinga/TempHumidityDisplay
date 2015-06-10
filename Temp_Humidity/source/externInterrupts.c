#include "board.h"
#include "portb.h"
#include "typedefs.h"

BOOL resetSwState;

void extInterruptInit (void)
{
	OpenPORTB( PORTB_CHANGE_INT_ON & PORTB_PULLUPS_ON 
				& PORTB_INT_PRIO_HIGH ); // PortB 'change on interrupt' is enabled

	INTCONbits.RBIF = 0; // clear interrupt flag
	TRISB = 0XFF;		// Port B as input
	resetSwState = 0;

}

#pragma code 
#pragma interrupt extInterruptHandler
void extInterruptHandler (void)
{
	UINT8 read;
	
	if (resetSwState)
		resetSwState = 0;
	else
		resetSwState = 1;

	read = PORTB;		//End the mismatch condition
	
	Delay10us(1); 		//Give 1 Tcy delay 
	
	INTCONbits.RBIF = 0; // clear interrupt flag 
}