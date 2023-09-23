#include <avr/io.h>
#include "MCAL/USART/USART.h"
#include "HAL/CLCD/CLCD.h"
#include "MCAL/ADC/ADC.h"
#include "STD_TYPES.h"
#include "util/delay.h"


void void_Alarm(u16 data );
void Void_ButtonConditions(void);

#define F_CPU 8000000UL
u8 x=50;
u8 temp =0;
u16 var=0;

//Reciever
int main(void)
{
	//UART
	USART_Init();
	//ADC
//	ADC_Init();
	//LCD
	CLCD_Void_InitPins();
	CLCD_voidInit();
	//BUTTON
	CLCDxBUTTONS();
    Void_InitButtonPins();
	//INT
	GIE_Enable ();
	
	u8 recieved;
	
	while (1)
	{
	Void_ButtonConditions();
	recieved=USART_ReceiveData();
	 var=(u16)recieved;
	CLCD_voidSendString("   T=");
	CLCD_VoidWriteNumber(var);
	_delay_ms(1000);
	CLCD_voidLCDClear();
	void_Alarm(var);
	}
}

void Void_ButtonConditions(void)
{
	if(DIO_GetPinValue(DIO_PORTC,DIO_PIN0) == 0)
	{

		x++;
		CLCD_voidSendString(" inc lim:");
		CLCD_VoidWriteNumber(x);
		_delay_ms(3000);
		CLCD_voidLCDClear();

	}

	if(DIO_GetPinValue(DIO_PORTC,DIO_PIN1) == 0)
	{
		x--;
		CLCD_voidSendString(" dec lim:");
		CLCD_VoidWriteNumber(x);
		_delay_ms(3000);
		CLCD_voidLCDClear();
	}

	if(DIO_GetPinValue(DIO_PORTC,DIO_PIN2) == 0)
	{
		CLCD_voidSendString(" limit:");
		CLCD_VoidWriteNumber(x);
		_delay_ms(3000);
		CLCD_voidLCDClear();


	}
	if(DIO_GetPinValue(DIO_PORTC,DIO_PIN3) == 0)
	{

		CLCD_voidSendString(" Sent:");
		CLCD_VoidWriteNumber(x);
		_delay_ms(4000);
		CLCD_voidLCDClear();
		temp = x ;
	}

}

void void_Alarm(u16 data)
{
	u16 limit;
	DIO_SetPinDirection (DIO_PORTD , DIO_PIN4 , DIO_OUTPUT);
	DIO_SetPinDirection (DIO_PORTD , DIO_PIN5 , DIO_OUTPUT);
	if (temp!=0)
	{
	limit = ( (temp>=x) ? (temp):(x) );
		if ((data)>=limit)
		{
			DIO_SetPinValue(DIO_PORTD , DIO_PIN4 , DIO_HIGH);
			DIO_SetPinValue(DIO_PORTD , DIO_PIN5 , DIO_HIGH);
			CLCD_voidSendString(" ALARM!!");
			_delay_ms(500);
			data=0;
			
		}
		else if ((data) <limit)
		{
			DIO_SetPinValue(DIO_PORTD , DIO_PIN4, DIO_LOW);
			DIO_SetPinValue(DIO_PORTD , DIO_PIN5, DIO_LOW);
		}
		
		else
			{
			CLCD_voidSendString(" ADC reading:");
			CLCD_VoidWriteNumber(data);
			_delay_ms(1000);
			CLCD_voidLCDClear();
			}
	}

}
