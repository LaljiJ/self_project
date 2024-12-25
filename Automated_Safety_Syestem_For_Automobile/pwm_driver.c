
#include <reg51.h>
#include "header.h"

extern s8 pwm;
sbit led1=P2^0;
u32 temp2;

void Timer0_Handler(void) interrupt 1
{
TR0=0;
	if(led1==1)
	{
		led1=0;
		temp2=255-pwm;
		TH0=0xFF-(temp2>>8)&0xFF;
		TL0=0xFF-temp2&0xFF;
	}
	else
	{
		led1=1;
		temp2=pwm;
		TH0=0xFF-(temp2>>8)&0xFF;
		TL0=0xFF-temp2&0xFF;
	}

TR0=0;
TR0=1;
	
}


void en_timer0_interrupt()
{
	pwm=0;
	
	TMOD|=0x1;
	TH0=0;
	TL0=0;
	ET0=EA=1;
	TR0=1;
}



