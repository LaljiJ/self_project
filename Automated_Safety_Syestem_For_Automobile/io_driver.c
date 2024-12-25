#include <reg51.h>
#include "header.h"



/*-------------------- IO_WRITE WRITE VALU ON PORT -------------------*/
void io_write(u8 port,u8 pin,u8 val)
{
	
		switch(port)
		{
			
			case PORT0:	if(val==1)
									P0|=(1<<pin);
									else
									P0&=~(1<<pin);
									break;
									
			case PORT1:	if(val==1)
									P1|=(1<<pin);
									else
									P1&=~(1<<pin);
									break;
									
			case PORT2:	if(val==1)
									P2|=(1<<pin);
									else
									P2&=~(1<<pin);
									break;
									
			case PORT3:	if(val==1)
									P3|=(1<<pin);
									else
									P3&=~(1<<pin);					
									break;
									
		}

}



/*-------------------- IO_READ READ VALU ON PORT -------------------*/
u8 io_read(u8 port,u8 pin)
{
u8 STATUS;
	
		switch(port)
		{
			case PORT0: STATUS= P0&(1<<pin)?1:0;
									break;
		
			case PORT1: STATUS= P1&(1<<pin)?1:0;
									break;
			
			case PORT2: STATUS= P2&(1<<pin)?1:0;
									break;
			
			case PORT3: STATUS= P3&(1<<pin)?1:0;
									break;
		}

return STATUS;


}