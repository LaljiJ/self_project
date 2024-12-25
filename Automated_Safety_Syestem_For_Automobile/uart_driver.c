#include <reg51.h>
#include "header.h"



/*-------------------- UART INITIALIZE -------------------*/
void uart_init(u16 BAUD)
{
	
		TMOD|=0x20;
		SCON|=0x50;
		switch(BAUD)
		{
			case 4800:	TH1=250;
									break;
			case 7200:	TH1=252;
									break;
			case 9600:	TH1=253;
									break;
			case 14400:	TH1=254;
									break;
			case 28800: 	TH1=255;
									break;	
			case 57600:	TH1=255;PCON=0x80;
									break;
		}

		TR1=1;

}



/*-------------------- UART TRANSMIT 1 Bit by Bit -------------------*/
void uart_tx(u8 CH)
{
	
	SBUF=CH;
	while(TI==0);
	TI=0;
	
}



/*-------------------- UART RECIVED 1 Bit by Bit -------------------*/
u8 uart_rx()
{
	
	while(RI==0);
	RI=0;
	
return SBUF;	

}





