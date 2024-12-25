#include "header.h"


/*---------------------- 1ms Delay ------------------*/
void delay_ms(s16 ms)
{
	
	u8 i;	
		for(;ms>0;ms--)
		{
				for(i=250;i>0;i--);
				for(i=247;i>0;i--);
		}
		
}