#ifndef __ADC__
#define __ADC__

#include "typedefs.h"
#include "board.h"
#include "adc.h"


typedef enum 
{
	ANCH0 = ADC_CH0,   
	ANCH1 = ADC_CH1,
	MAX_ANCH = 2
}ANCH;

void ADC_init(void);
void ADC_task(void);
UINT16 ADC_getResult(ANCH ch);
void ADC_interrupt(void);

#endif	//__ADC__