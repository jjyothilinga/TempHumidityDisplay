#include "app.h" 
#include "eep.h"
#include "typedefs.h"
#include "digitdisplay.h"
#include "adc_ide.h"
#include "config.h"


#define EEPROM_ADDRESS ( 0 )   // EEPROM address is defined to store the max and min values of Temp and Hum

void conversion ( UINT16 );	   // converts BCD to ASCII
void countsToTempHum ( void);  // Used to scale temp and Hum
void read_eeprom ( void );


typedef struct _App
{
	UINT16 temparature;
	UINT16 humidity;

	UINT8 currentItem;
	UINT8 buffer[NO_OF_DIGITS];
	UINT8 bufferIndex;
	UINT8 txBuffer[NO_OF_DIGITS];




	UINT16 tempHighLimit;
	UINT16 tempLowLimit;
	UINT16 humHighLimit;
	UINT16 humLowLimit;	
	BOOL setAlarm;
	UINT16 limitBuffer[4];

	UINT8 count;



}APP;

#pragma idata APP_DATA
APP app = {0};
#pragma idata

void app_init( void )
{
	app.currentItem = 0;
	read_eeprom( ); 			// Read high and low limits of temp and humidity from eeprom	
}



void app_task( void )
{
	UINT8 i;
	for (i = 0; i < 6; i++)
	{
		app.buffer[i] = 0X3F;
	}
		
				
	app.humidity = ADC_getResult(HUM_CHN);

#ifndef __ADC_COUNT_DISPLAY__
	countsToTempHum( );		// Converts ADC counts to Scaled Temparature
#endif	//__ADC_COUNT_DISPLAY



	conversion(app.humidity); 


	app.currentItem++;		// Incrementing nextItem in order to display temp
	app.temparature = ADC_getResult(TEMP_CHN);

#ifndef __ADC_COUNT_DISPLAY__
	countsToTempHum( );		// Converts ADC counts to Scaled Humidity
#endif	//__ADC_COUNT_DISPLAY

	conversion(app.temparature);

	app.currentItem = 0;
	
	

	DigitDisplay_updateBufferBinary(app.buffer);

	if ( app.count > 15 )
	{
		switch (RESET_SWITCH)
		{
			case 1:	if ((app.temparature < app.tempLowLimit)
						 || (app.temparature > app.tempHighLimit)) // check for high and low limits of temparature
						app.setAlarm = 1;
			
					else if ((app.humidity < app.humLowLimit)
							 || (app.humidity > app.humHighLimit))		// check for high and low limits of humidity
						app.setAlarm = 1;
			
					else 
						app.setAlarm = 0;
				
					switch (app.setAlarm)
					{
						case 0: GREEN_LAMP = 1;
								RED_LAMP = 0;
								break;
						case 1:	RED_LAMP = 1;  
								GREEN_LAMP = 0;
								break;
						default:break;
					}
			
					break;
			case 0:	{ 
						GREEN_LAMP = 0;
						RED_LAMP = 0;
					}		
					break;
			default:
			break;
		}
	}
	
					
	else 
	{
		app.count++;
	}
}

// Function to unpack the temperature and humidity

void conversion( UINT16 data )
{
	
	if (app.currentItem == 0)
		app.bufferIndex = 0;
	else if (app.currentItem == 1)
		app.bufferIndex = 3;						// To fill up buffer with the value of temparature
	
	do
	{
		app.buffer[app.bufferIndex] = data % 10;
		
		switch( app.buffer[app.bufferIndex] )					// Assigning segment value to the buffer
		{
			case 0: app.buffer[app.bufferIndex] = 0x3F;
					app.txBuffer[app.bufferIndex] = '0';
					break;
			case 1: app.buffer[app.bufferIndex] = 0x06;
					app.txBuffer[app.bufferIndex] = '1';
					break;
			case 2: app.buffer[app.bufferIndex] = 0x5B;
					app.txBuffer[app.bufferIndex] = '2';
					break;
			case 3: app.buffer[app.bufferIndex] = 0x4F;
					app.txBuffer[app.bufferIndex] = '3';
					break;
			case 4: app.buffer[app.bufferIndex] = 0x66;
					app.txBuffer[app.bufferIndex] = '4';
					break;
			case 5: app.buffer[app.bufferIndex] = 0x6D;
					app.txBuffer[app.bufferIndex] = '5';
					break;
			case 6: app.buffer[app.bufferIndex] = 0x7D;
					app.txBuffer[app.bufferIndex] = '6';
					break;
			case 7: app.buffer[app.bufferIndex] = 0x07;
					app.txBuffer[app.bufferIndex] = '7';
					break;
			case 8: app.buffer[app.bufferIndex] = 0x7F;
					app.txBuffer[app.bufferIndex] = '8';
					break;
			case 9: app.buffer[app.bufferIndex] = 0x6F;
					app.txBuffer[app.bufferIndex] = '9';
					break;
			default: break;
		}
	
	app.bufferIndex++;
 
	}while (( data /= 10) > 0);
	
	app.buffer[1] |= 0X80;				// To display dot in Humidity
	app.buffer[4] |= 0X80;				// To display dot in Temperature
}


void countsToTempHum(void)
{
	INT32 result = 0;
	
	switch ( app.currentItem )
	{
	case 0:	if( app.humidity < 215 )		
				app.humidity = 0;
			else
			{
				result = ((INT32)(app.humidity-215)) * 1173;
				app.humidity = (result)>> 10;
			}
			break;

	case 1: 
			if(	app.temparature< 215)
				app.temparature = 0;
			else
			{
				result = ((INT32)(app.temparature-215)) * 1173;
		
				app.temparature = result >> 10;
			}
			break;
	default: break;
	}
}



UINT8 APP_comCallBack( UINT8 *rxPacket, UINT8* txCode, UINT8** txPacket)
{

	UINT8 i;
	UINT8 address;

	UINT8 rxCode = rxPacket[0];
	UINT8 length = 0;

	switch( rxCode )
	{
		case CMD_GET_STATUS:
			length = NO_OF_DIGITS;
			*txCode = CMD_GET_STATUS;
			*txPacket = app.txBuffer;
	 
			break;


		case CMD_SET_LIMIT:
			address = EEPROM_ADDRESS;
			for ( i = 0; i < 8; i++ )
			{
				Write_b_eep (address, rxPacket[i+1]);
				Busy_eep();
				address++;
			}
			Busy_eep();
			read_eeprom( );
			length = 0;
			*txCode = CMD_SET_LIMIT;
	 
			break;
		case CMD_GET_LIMIT:
			app.limitBuffer[0] = app.tempHighLimit;
			app.limitBuffer[1] = app.tempLowLimit;
			app.limitBuffer[2] = app.humHighLimit;
			app.limitBuffer[3] = app.humLowLimit;

			length = 8;
			*txCode = CMD_GET_LIMIT;
			*txPacket = (UINT8*)app.limitBuffer;
	 
			break;

		default:
			length = 0;
			*txCode = COM_RESP_INVALID_CMD;
			break;
	}

	return length;

}


void read_eeprom( void )
{
	app.tempHighLimit = Read_b_eep (EEPROM_ADDRESS);  	//Reads eeprom data: higher byte of Higher limit of Temp 
	Busy_eep();
	app.tempHighLimit <<= 8;
	app.tempHighLimit |= Read_b_eep (EEPROM_ADDRESS+1);
	Busy_eep();
	app.tempLowLimit = Read_b_eep (EEPROM_ADDRESS+2);	//Reads eeprom data: Lower limit of Temp 
	Busy_eep();
	app.tempLowLimit <<= 8;
 	app.tempLowLimit |= Read_b_eep (EEPROM_ADDRESS+3);
	Busy_eep();

	app.humHighLimit = Read_b_eep (EEPROM_ADDRESS+4); 	//Reads eeprom data: Higher limit of Humidity 
	Busy_eep();
	app.humHighLimit <<= 8;
	app.humHighLimit |= Read_b_eep (EEPROM_ADDRESS+5);
	Busy_eep();
	app.humLowLimit = Read_b_eep (EEPROM_ADDRESS+6);	//Reads eeprom data: Lower limit of Humidity 
	Busy_eep();
	app.humLowLimit <<= 8;
	app.humLowLimit |= Read_b_eep (EEPROM_ADDRESS+7);
	Busy_eep();
}


