#include<lpc21xx.h>
#include "header.h"
u8 flag_rx;
CAN1 r;
int main()
{
	volatile u8 LEFT=0;
	volatile u8 RIGHT=0;

	CAN1_init();
	CAN1_rx_config();
	uart0_init(9600);
	IODIR0=0XFF;
	IOSET0=0XFF;
	uart0_tx_string("In node B\r\n");
	while(1){
		if(flag_rx)
		{
			flag_rx=0;
			uart0_tx_string("isr executed\r\n");
			switch(r.byteA&0xff)
			{
				case 0x50: IOCLR0|=16|8; break;
				case 0x51: IOSET0|=16|8; break;
				case 0x52: RIGHT=0; LEFT=1; break;
				case 0x53: LEFT=0; break;
				case 0x54: RIGHT=1;LEFT=0; break;
				case 0x55: RIGHT=0; break;
	
			}
		}
		if(LEFT)
		{
		   IOCLR0|=4;
		   delay_ms(100);
		   IOSET0|=4;
		   delay_ms(100);
		}
		if(RIGHT)
		{
		  IOCLR0|=32;
		  delay_ms(100);
		  IOSET0|=32;
		  delay_ms(100);
		}
		
	}

}
