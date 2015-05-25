#include "adc_ide.h"

#define SAMPLE_COUNT	32

typedef struct _ADC
{
	UINT8 conversion;
	UINT8 sampleCount;
	UINT16 partialResult[MAX_ANCH];
	UINT16 result[MAX_ANCH];
	UINT8 currentChannel;
}ADC;

ADC adc = {0};




/*---------------------------------------------------------
				ADC - 1 & 2
---------------------------------------------------------*/

void ADC_init( void )
{
	OpenADC(ADC_FOSC_32 & ADC_RIGHT_JUST & ADC_2_TAD,	 //open adc with required 
			ADC_CH0 & ADC_INT_ON & ADC_REF_VDD_VSS,	 //configuration 
			ADC_2ANA); 	


	PIE1bits.ADIE = 1;		//Enable adc interrupt
	IPR1bits.ADIP = 1;		//set adc interrupt as high priority
	ConvertADC();
}

void ADC_task(void)
{

	DISABLE_ADC_INTERRUPT();	//entering critical section for adc
	if( adc.conversion == 1 )	//check for completion
	{

		adc.sampleCount++;		//count no. of samples collected
		adc.partialResult[adc.currentChannel] += ReadADC();	//accumulate samples

		if( adc.sampleCount >= SAMPLE_COUNT ) 
		{
			adc.result[adc.currentChannel] = (adc.partialResult[adc.currentChannel]>>5);//average sample data
			adc.partialResult[adc.currentChannel] = 0;		//reset partial result
			adc.sampleCount = 0;			//reset sample count
			adc.currentChannel++;

			if (adc.currentChannel >= MAX_ANCH)
				adc.currentChannel = 0;				// set channel to ADC-CH0
			
			switch(adc.currentChannel)
			{
				case 0: SetChanADC(ANCH0);
				break;

				case 1: SetChanADC(ANCH1);
				break;

				default:
				break;
			}
		}
		ConvertADC();			//start conversion
		adc.conversion = 0;	//indicate in conversion status

		 
	}
	ENABLE_ADC_INTERRUPT();
}


UINT16 ADC_getResult(ANCH ch)
{
	UINT16 result;
	DISABLE_ADC_INTERRUPT();	//entering critical section for adc
	result = adc.result[ch];
	ENABLE_ADC_INTERRUPT();
	return result;
}


#pragma interrupt ADC_interrupt
void ADC_interrupt(void)
{
	adc.conversion = 1;	//clear conversion flag to indicate completion
	PIR1bits.ADIF = 0;	//clear conversion completion flag in PIR register
}


			
