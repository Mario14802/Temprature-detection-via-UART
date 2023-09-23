

#ifndef USART_H_
#define USART_H_

#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "../DIO/DIO.h"
#include <avr/io.h>

#define RXC    7
#define TXC    6
#define UDRE   5
#define FE     4
#define DOR    3
#define PE     2
#define U2X    1
#define MPCM   0



#define RXCIE  7
#define TXCIE  6
#define UDRIE  5
#define RXEN   4
#define TXEN   3
#define UCSZ2  2
#define RXB8   1
#define TXB8   0



#define URSEL  7
#define UMSEL  6
#define UPM1   5
#define UPM0   4
#define USBS   3
#define UCZ1   2
#define UCSZ0  1
#define UCPOL  0


void USART_Init(void);
void USART_SendData(u8 u8Data_Copy);
u8   USART_ReceiveData(void);
void USART_SendString(u8* pu8Data_Copy);
void USART_ReceiveString(u8* pu8Data_Copy);




#endif /* USART_H_ */







