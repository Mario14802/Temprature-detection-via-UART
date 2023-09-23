/*Preprocessor file guard*/
#ifndef CLCD_H
#define CLCD_H


#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"
#include <util/delay.h>

#define CLCD_DATA_PORT    DIO_PORTA
#define CLCD_CTRL_PORT    DIO_PORTB

#define CLCD_RS_PIN       DIO_PIN2
#define CLCD_RW_PIN       DIO_PIN1
#define CLCD_E_PIN        DIO_PIN0


void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidInit(void);

void CLCD_voidSendString(const char* Copy_pcString);
void CLCD_Void_InitPins(void);
void CLCD_voidLCDClear(void);
void CLCD_VoidWriteNumber(u16 udata);
void CLCDxBUTTONS(void);
void Void_InitButtonPins(void);
#endif

