#include <reg51.h>
#include <intrins.h>
#include "header.h"

sfr16 DPTR=0x82;
 
sbit trig=P2^4;
sbit echo=P2^5;

u16 range=0;
s8 i=10;

void send_pulse() 
{
	
 TH0=0x00;TL0=0x00; 
 trig=1;
i--; i--; i--; i--; i--; 
i--; i--; i--; i--; i--;
	trig=0;
}


u8 ultrasonic()
{
 u8 get;
 send_pulse();
 
	while(!echo);
 while(echo);
 
	DPH=TH0;
 DPL=TL0;
 TH0=TL0=0xff;
 if(DPTR<38000)
 get=DPTR/59;
 else
 get=0;
 
 return get;
}




void get_range()
{
 TMOD=0x01;
 TH0=TL0=0;
 TR0=1;
 lcd_string("DIS");
 P3|=(1<<2);

		lcd_cmd(0x1);
		range=ultrasonic();
		lcd_integer(range);

}