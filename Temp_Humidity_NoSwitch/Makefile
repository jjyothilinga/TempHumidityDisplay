# MPLAB IDE generated this makefile for use with GNU make.
# Project: Temp_Hum.mcp
# Date: Mon Oct 28 11:26:39 2013

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

Temp_Hum.cof : adc_ide.o app.o board.o communication.o digitdisplay.o heartBeat.o interruptvector.o main.o timer.o uart_driver.o externInterrupts.o
	$(LD) /p18F4520 /l"C:\Program Files (x86)\Microchip\mplabc18\v3.46\lib" "18f4520.lkr" "adc_ide.o" "app.o" "board.o" "communication.o" "digitdisplay.o" "heartBeat.o" "interruptvector.o" "main.o" "timer.o" "uart_driver.o" "externInterrupts.o" /u_CRUNTIME /u_DEBUG /z__MPLAB_BUILD=1 /z__MPLAB_DEBUG=1 /o"Temp_Hum.cof" /M"Temp_Hum.map" /W

adc_ide.o : adc_ide.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h communication.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/adc.h adc_ide.h adc_ide.c typedefs.h board.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f4520.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h config.h
	$(CC) -p=18F4520 "adc_ide.c" -fo="adc_ide.o" -D__DEBUG

app.o : app.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h communication.h app.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/eep.h digitdisplay.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/adc.h adc_ide.h app.c board.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f4520.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h typedefs.h config.h exterInterrupts.h
	$(CC) -p=18F4520 "app.c" -fo="app.o" -D__DEBUG

board.o : board.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h communication.h board.c board.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f4520.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h typedefs.h config.h
	$(CC) -p=18F4520 "board.c" -fo="board.o" -D__DEBUG

communication.o : communication.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h communication.h uart_driver.h timer.h communication.c config.h board.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f4520.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h typedefs.h
	$(CC) -p=18F4520 "communication.c" -fo="communication.o" -D__DEBUG

digitdisplay.o : digitdisplay.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h communication.h digitdisplay.h digitdisplay.c config.h typedefs.h board.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f4520.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h
	$(CC) -p=18F4520 "digitdisplay.c" -fo="digitdisplay.o" -D__DEBUG

heartBeat.o : heartBeat.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h communication.h heartBeat.c typedefs.h heartbeat.h board.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f4520.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h config.h
	$(CC) -p=18F4520 "heartBeat.c" -fo="heartBeat.o" -D__DEBUG

interruptvector.o : interruptvector.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h communication.h timer.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/adc.h adc_ide.h uart_driver.h interruptvector.c board.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f4520.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h typedefs.h config.h exterInterrupts.h
	$(CC) -p=18F4520 "interruptvector.c" -fo="interruptvector.o" -D__DEBUG

main.o : main.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/string.h communication.h timer.h digitdisplay.h app.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/adc.h adc_ide.h main.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f4520.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/stddef.h board.h typedefs.h config.h heartbeat.h exterInterrupts.h
	$(CC) -p=18F4520 "main.c" -fo="main.o" -D__DEBUG

timer.o : timer.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h communication.h timer.h timer.c board.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f4520.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h typedefs.h config.h
	$(CC) -p=18F4520 "timer.c" -fo="timer.o" -D__DEBUG

uart_driver.o : uart_driver.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h communication.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/string.h uart_driver.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/usart.h uart_driver.c board.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f4520.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h typedefs.h config.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/stddef.h
	$(CC) -p=18F4520 "uart_driver.c" -fo="uart_driver.o" -D__DEBUG

externInterrupts.o : externInterrupts.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h communication.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/portb.h externInterrupts.c board.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f4520.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h typedefs.h config.h
	$(CC) -p=18F4520 "externInterrupts.c" -fo="externInterrupts.o" -D__DEBUG

clean : 
	$(RM) "adc_ide.o" "app.o" "board.o" "communication.o" "digitdisplay.o" "heartBeat.o" "interruptvector.o" "main.o" "timer.o" "uart_driver.o" "externInterrupts.o" "Temp_Hum.cof" "Temp_Hum.hex"

