
#include "USART.h"
#define F_CPU 8000000UL
void USART_Init(void){
	//set baudrate 9600
	UBRRL = 51 ;
	UBRRH = 0 ;

//frame formal
	SET_BIT (UCSRC , URSEL);

	// 1- word size = 8 bit
	SET_BIT (UCSRC , UCSZ0);
	SET_BIT (UCSRC , UCSZ1);
	CLEAR_BIT (UCSRB , UCSZ2);

	//2- disable parity
	CLEAR_BIT (UCSRC , UPM0);
	CLEAR_BIT (UCSRC , UPM1);

	//3- stop bit = 1
	CLEAR_BIT (UCSRC , USBS);



	/*u8 u8ucsrcValue=0;
	SET_BIT( u8ucsrcValue , 7 ); //1000 0000
	SET_BIT( u8ucsrcValue , UCSZ1 ); //1000 0100
	SET_BIT( u8ucsrcValue , UCSZ0 ); //1000 0110

	UCSRC = u8ucsrcValue;*/

	SET_BIT(UCSRB,TXEN);
	/*SET_BIT(UCSRB,RXEN);*/
}
void USART_SendData(u8 u8Data_Copy){

	while ( GET_BIT( UCSRA , UDRE ) == 0 );
	UDR = u8Data_Copy;

}
u8   USART_ReceiveData(void){

	//wait for flag RXC == 0
	while ( GET_BIT( UCSRA , RXC ) == 0 );
	return UDR;



}
void USART_SendString(u8* pu8Data_Copy){
	u8 i = 0;
		while(pu8Data_Copy[i] != '\0')
		{
			USART_SendData(pu8Data_Copy[i]);
			i++;
		}

}
void USART_ReceiveString(u8* pu8Data_Copy){
	u8 i = 0;
	pu8Data_Copy[i] = USART_ReceiveData();
		while(pu8Data_Copy[i] != 0x0d)
		{
			i++;
			pu8Data_Copy[i] = USART_ReceiveData();
		}
		pu8Data_Copy[i] = '\0';


}
