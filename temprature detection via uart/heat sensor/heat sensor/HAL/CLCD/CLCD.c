

#include "CLCD.h"

void CLCD_voidSendCommand(u8 Copy_u8Command){

	/*Write command steps */

	/*Step 1 : Reset (RS&RW)pins */
	/*set RS pin to LOW for command*/
	DIO_SetPinValue(CLCD_CTRL_PORT ,CLCD_RS_PIN, DIO_LOW);
	/*set RW pin to LOW for write*/
	DIO_SetPinValue(CLCD_CTRL_PORT ,CLCD_RW_PIN, DIO_LOW);

	/*Step 2 : Send command through data port */
	/*set  command at 8 pins */
	DIO_SetPortValue (CLCD_DATA_PORT,Copy_u8Command);

	/*Step 3 : Set the (E) pin for a period defined in datasheet ( 2ms is working) then reset it*/
	/*set  Enable Pulse */
	DIO_SetPinValue(CLCD_CTRL_PORT ,CLCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT ,CLCD_E_PIN, DIO_LOW);

}


void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*Set RS pin to high for data*/
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_HIGH);

	/*Set RW pin to low for write*/
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_LOW);

	/*Set Data to data pins*/
	DIO_SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*Send enable pulse*/
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_LOW);
}


void CLCD_voidInit(void)
{
	/*Wait for more than 30 ms*/
	_delay_ms(40);

	/*Function set command: 2 lines(N = 1), 5*8 Font size (F = 0 )*/
	CLCD_voidSendCommand(0b00111000);

	/*Display on off control: display enable, disable cursor, no blink cursor*/
	CLCD_voidSendCommand(0b00001100);

	/*Clear display*/
	CLCD_voidSendCommand(0b00000001);

}


void CLCD_voidSendString(const char* Copy_pcString)
{     u8 Local_u8Counter=0;
	while  ( Copy_pcString[Local_u8Counter] != '\0' ){
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter ++;
	}
}



void CLCD_voidLCDClear(void)
{
	CLCD_voidSendCommand(0X01);
}


void CLCD_VoidWriteNumber(u16 udata)
{
	u16 digit1 = udata / 10; // Tens digit
	u16 digit2 = udata % 10; // Units digit

	// Convert digits to ASCII characters
	u8 char1 = '0' + digit1;
	u8 char2 = '0' + digit2;

	// Send the characters to the LCD
	CLCD_voidSendData(char1);
	CLCD_voidSendData(char2);

}



void CLCD_Void_InitPins(void)
{
	/*LCD Data  pins direction*/
	DIO_SetPortDirection(DIO_PORTA,DIO_OUTPUT);
	/*LCD Control  pins direction*/
	DIO_SetPinDirection(DIO_PORTB,CLCD_E_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,CLCD_RS_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,CLCD_RW_PIN,DIO_OUTPUT);
}
void CLCDxBUTTONS(void)
{
	CLCD_voidSendString(" LIMIT:50 ");
	_delay_ms(3000);
	CLCD_voidLCDClear();
	CLCD_voidSendString(" PressButton 1");
	_delay_ms(3000);
	CLCD_voidLCDClear();
	CLCD_voidSendString(" to inc");
	_delay_ms(3000);
	CLCD_voidLCDClear();
	CLCD_voidSendString(" PressButton 2");
	_delay_ms(3000);
	CLCD_voidLCDClear();
	CLCD_voidSendString(" to dec");
	_delay_ms(3000);
	CLCD_voidLCDClear();
	CLCD_voidSendString(" PressButton 3 ");
	_delay_ms(3000);
	CLCD_voidLCDClear();
	CLCD_voidSendString(" toShowLimit");
	_delay_ms(3000);
	CLCD_voidLCDClear();
	CLCD_voidSendString(" PressButton 4");
	_delay_ms(3000);
	CLCD_voidLCDClear();
	CLCD_voidSendString(" toSendlimit");
	_delay_ms(3000);
	CLCD_voidLCDClear();
}


void Void_InitButtonPins(void)
{
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN0, DIO_INPUT);
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN1, DIO_INPUT);
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN2, DIO_INPUT);
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN3, DIO_INPUT);

	DIO_SetPinValue(DIO_PORTC,DIO_PIN0, DIO_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN1, DIO_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN2, DIO_HIGH);
	DIO_SetPinValue(DIO_PORTC,DIO_PIN3, DIO_HIGH);
}

