
#include "GIE.h"

void GIE_Enable (void){
	//SET bit 7 in SREG
	SET_BIT(SREG  ,  SREG_I );

}
void GIE_Disable(void){

	//CLEAR_BIT bit 7 in SREG
	CLEAR_BIT(SREG  ,  SREG_I );

}
