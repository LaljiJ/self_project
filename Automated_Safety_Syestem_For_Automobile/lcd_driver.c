#include <reg51.h>
#include "header.h"

sbit RS=P3^4;
sbit RW=P3^5;
sbit EN=P3^6;


/*-------------------- WRITE COMMAND ON LCD -------------------*/
void lcd_cmd(u8 CMD)
{

P0=CMD;
	RS=0;
	RW=0;
	EN=1;
		delay_ms(5);
	EN=0;

}


/*-------------------- INITIALIZE LCD -------------------*/
void lcd_init()
{
	
	lcd_cmd(0x2);
	lcd_cmd(0x38);
	lcd_cmd(0xE);
	lcd_cmd(0x6);
	lcd_cmd(0x1);

}



/*-------------------- WRITE DATA ON LCD -------------------*/
void lcd_data(u8 CH)
{

P0=CH;
	RS=1;
	RW=0;
	EN=1;
		delay_ms(5);
	EN=0;
	
}

/******************** write string on LCD ********************/
void lcd_string(char *STRING)
{
	while(*STRING)
	{
			lcd_data(*STRING);
			STRING++;
	}

}


/******************* integer print on LCD *******************/
void lcd_integer(s16 NUM)
{
	s16 SUM=0,COUNT=0;
	s8 BUF[10],i;
	
if(NUM<0)
{
	lcd_data('-');
	NUM=-NUM;
}

if(NUM==0)
{
	lcd_data('0');
	return;
}
		
		while(NUM)
		{
			COUNT++;
			SUM=SUM*10+NUM%10;
			NUM=NUM/10;
		}
		
	for(i=0;COUNT;SUM=SUM/10,i++)
	{
		
		BUF[i]=(SUM%10)+48;	
		COUNT=COUNT-1;
	}
	
BUF[i]='\0';

lcd_string(BUF);
	
}


/********************* float valu printf on LCD *********************/
//void lcd_float(float FLOAT)
//{
//	
//	s16 INT=FLOAT;
//	
//	lcd_integer(INT);
//	lcd_data('.');
//	INT=((FLOAT-INT)*100);
//	
//	if(INT<0)
//	lcd_integer(-INT);
//	else
//	lcd_integer(INT);
//}

