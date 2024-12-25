#include <reg51.h>
#include "header.h"

sbit CLK=P1^0;
sbit DOUT=P1^1;
sbit DIN=P1^2;
sbit CS=P1^3;

u16 adc_read_LDR()
{
	u16 TEMP=0x0;
	s8 i;
	
CS=0;

	CLK=0;		DIN=1;		CLK=1;
	CLK=0;		DIN=1;		CLK=1;
	CLK=0;		DIN=1;		CLK=1;
	CLK=0;		DIN=1;		CLK=1; //Channel 2
	CLK=0;		DIN=0;		CLK=1; //Channel 2
	CLK=0;		DIN=1;		CLK=1;
	CLK=0;		DIN=1;		CLK=1;
	
	for(i=11;i>=0;i--)
	{
		CLK=0;
		
		if(DOUT==1)
		TEMP|=(1<<i);
	
		CLK=1;
	}
	
CS=1;

return TEMP;	
	
}