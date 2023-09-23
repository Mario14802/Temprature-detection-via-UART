#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MCAL/USART/USART.h"
#include "MCAL/ADC/ADC.h"
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

#define F_CPU 8000000UL
//transmitter
int main(void)
{
	USART_Init();
	GIE_Enable();
	ADC_Init();
	
	while (1)
	{
		u8 adc_read;
	
		u16 data=ADC_Read (0b11100000);
		adc_read=((data/256));
		
		USART_SendData(adc_read);
	}
}

