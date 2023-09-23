

#ifndef GIE_H_
#define GIE_H_


#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "avr/io.h"
#include <util/delay.h>

//SREG register
#define SREG_I      7

void GIE_Enable (void);
void GIE_Disable(void);

#endif /* GIE_H_ */
