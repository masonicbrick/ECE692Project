#ifndef __ADC_H
#define __ADC_H	
#include "sys.h"

//Punctual atom adc collection code
void Adc_Init(void);
u16  Get_Adc(u8 ch); 
u16 Get_Adc_Average(u8 ch,u8 times);
extern float temp_avrg;
extern int shidu;
 
#endif 