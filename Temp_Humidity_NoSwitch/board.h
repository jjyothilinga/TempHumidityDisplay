#ifndef DEVICE_H
#define DEVICE_H

/*
*------------------------------------------------------------------------------
* device.h
*
* Include file for port pin assignments
*

*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* File				: device.h
*------------------------------------------------------------------------------
*

*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/
#ifdef __18F4520
#include <p18f4520.h>
#elif __18F4620
#include <p18f4620.h>
#endif
#include <delays.h>
#include <timers.h>
#include "typedefs.h"
#include "config.h"
#include "communication.h"



/*
*------------------------------------------------------------------------------
* Hardware Port Allocation
*------------------------------------------------------------------------------
*/

// TX enable
#define 	TX_EN 							PORTEbits.RE2
#define 	TX_EN_DIRECTION					TRISEbits.TRISE2


// Display Data port
#define		DISPLAY_PORT				PORTD	//LATD	 				// 7seg display data (DB0-DB7)
#define 	DISPLAY_PORT_DIRECTION		TRISD


// Display digit select lines
#define		DIGIT_SEL_A					PORTBbits.RB0 			// demux digit sel A
#define		DIGIT_SEL_A_DIRECTION		TRISBbits.TRISB0
#define		DIGIT_SEL_B					PORTBbits.RB1			// demux digit sel B
#define		DIGIT_SEL_B_DIRECTION		TRISBbits.TRISB1
#define		DIGIT_SEL_C					PORTBbits.RB2			// demux digit sel C
#define		DIGIT_SEL_C_DIRECTION		TRISBbits.TRISB2
#define		DIGIT_SEL_D					PORTBbits.RB3			
#define		DIGIT_SEL_D_DIRECTION		TRISBbits.TRISB3
#define		DIGIT_SEL_E					PORTBbits.RB4			
#define		DIGIT_SEL_E_DIRECTION		TRISBbits.TRISB4
#define		DIGIT_SEL_F					PORTBbits.RB5			
#define		DIGIT_SEL_F_DIRECTION		TRISBbits.TRISB5
		

// Temperature Transducer (ANALOG INPUT)
#define 	TEMP_ANALOG_INPUT 				 PORTAbits.RA0
#define 	TEMP_ANALOG_INPUT_DIRECTION      TRISAbits.TRISA0

// Humidity Transducer (ANALOG INPUT)
#define 	HUM_ANALOG_INPUT 				 PORTAbits.RA1
#define 	HUM_ANALOG_INPUT_DIRECTION       TRISAbits.TRISA1

// Red and Green lamps
#define 	GREEN_LAMP					PORTBbits.RB6
#define 	GREEN_LAMP_DIRECTION		TRISBbits.TRISB6
#define 	RED_LAMP					PORTBbits.RB7
#define 	RED_LAMP_DIRECTION			TRISBbits.TRISB7


//Heart Beat
#define 	HEART_BEAT					PORTAbits.RA3
#define 	HEART_BEAT_DIRECTION		TRISAbits.TRISA3


//Reset Switch
#define 	RESET_SWITCH				PORTAbits.RA4
#define 	RESET_SWITCH_DIRECTION		TRISAbits.TRISA4

	
/*
*------------------------------------------------------------------------------
* Public Defines
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Macros
*------------------------------------------------------------------------------
*/

#define DEVICE_ID			(0x01)


//#define SYSTEM_CLOCK			(20000000UL)	// Hz		// 20MHz external crystal  used

#define SYSTEM_CLOCK			(40000000UL)	// Hz		// 10MHz external crystal x4 PLL

#define PERIPHERA_CLOCK			(SYSTEM_CLOCK / 4)UL

#define PERIPHERA_CLOCK_PERIOD 	(1 / PERIPHERA_CLOCK)UL



// Direction controle bit is processor specific ,
#define PORT_OUT				(BOOL)(0)
#define PORT_IN					(0XFF)

#define OFF_FOREVER				(BOOL)(0)
#define LOOP_FOREVER			(BOOL)(1)

#define SWITCH_OFF				(BOOL)(0)
#define SWITCH_ON				(BOOL)(1)


#define DISPLAY_DISABLE			(BOOL)(1)
#define DISPLAY_ENABLE			(BOOL)(0)
void EnableInterrupts(void);

/*
#ifdef __74LS374__
#undef DISPLAY_DISABLE
#undef DISPLAY_ENABLE

#define DISPLAY_DISABLE			(BOOL)(0)
#define DISPLAY_ENABLE			(BOOL)(1)

#endif 			//__74LS374__
*/


#define GetSystemClock()		(SYSTEM_CLOCK)      // Hz
#define GetInstructionClock()	(GetSystemClock()/4)
#define GetPeripheralClock()	GetInstructionClock()


#define BUZZER_ON()			BUZ_OP = SWITCH_ON;
#define BUZZER_OFF()		BUZ_OP = SWITCH_OFF;

// Disable global interrupt bit.
#define ENTER_CRITICAL_SECTION()	INTCONbits.GIE = 0;

// Enable global interrupt bit.
#define EXIT_CRITICAL_SECTION()		INTCONbits.GIE = 1;

#define ENABLE_GLOBAL_INT()			EXIT_CRITICAL_SECTION()


#define DISABLE_ADC_INTERRUPT()		PIE1bits.ADIE = 0
#define ENABLE_ADC_INTERRUPT()		PIE1bits.ADIE = 1

#define DISABLE_INT0_INTERRUPT()	INTCONbits.INT0IE = 0
#define ENABLE_INT0_INTERRUPT()		INTCONbits.INT0IE = 1
#define CLEAR_INTO_INTERRUPT()		INTCONbits.INT0IF = 0


#define DISABLE_TMR0_INTERRUPT()	INTCONbits.TMR0IE = 0
#define ENABLE_TMR0_INTERRUPT()		INTCONbits.TMR0IE = 1

#define DISABLE_TMR1_INTERRUPT()	PIE1bits.TMR1IE = 0
#define ENABLE_TMR1_INTERRUPT()		PIE1bits.TMR1IE = 1


#define DISABLE_UART_TX_INTERRUPT()	PIE1bits.TXIE = 0
#define ENABLE_UART_TX_INTERRUPT()	PIE1bits.TXIE = 1

#define DISABLE_UART_RX_INTERRUPT()	PIE1bits.RCIE = 0
#define ENABLE_UART_RX_INTERRUPT()	PIE1bits.RCIE = 1


#define HOLD_ATKBD_CLOCK()		    ATKBD_CLK_DIR= PORT_OUT;\
									ATKBD_CLK = 0;

#define RELEASE_ATKBD_CLOCK()	  	ATKBD_CLK_DIR = PORT_IN;\
									ATKBD_CLK = 1;

#define SET_INT0_FALLING_EDGE_TRIGGER()	INTCON2bits.INTEDG0 = 0

#define	ATKBD_INTERRUPT_EDGE	INTCON2.INTEDG0		

#define ENB_485_TX()	TX_EN = 1;
#define ENB_485_RX()	TX_EN = 0;

#define Delay10us(us)		Delay10TCYx(((GetInstructionClock()/1000000)*(us)))
#define DelayMs(ms)												\
	do																\
	{																\
		unsigned int _iTemp = (ms); 								\
		while(_iTemp--)												\
			Delay1KTCYx((GetInstructionClock()+999999)/1000000);	\
	} while(0)

/*
*------------------------------------------------------------------------------
* Public Data Types
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Variables (extern)
*------------------------------------------------------------------------------
*/


/*
*------------------------------------------------------------------------------
* Public Constants (extern)
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Function Prototypes (extern)
*------------------------------------------------------------------------------
*/

extern void BRD_init(void);

#endif
/*
*  End of device.h
*/