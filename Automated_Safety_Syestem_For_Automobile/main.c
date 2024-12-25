#include "header.h"
s8 pwm;

void main()
{

	
	lcd_init();
	en_timer0_interrupt();

	while(1)
	{
//		lcd_cmd(0x1);
//		temp=adc_read_LDR();
//		lcd_integer(temp);
//		pwm=temp*0.062;
//		
//		delay_ms(500);
		
		get_range();
		
	}	
	
	
	
}