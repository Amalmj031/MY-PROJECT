
#include<lpc21xx.h>
#include"header.h"

#define sw1 ((IOPIN0>>2)&1)
#define sw2 ((IOPIN0>>3)&1)
#define sw3 ((IOPIN0>>4)&1)
#define sw4 ((IOPIN0>>5)&1)

CAN1 v1;
int flag_HL;
int flag_LI;
int flag_RI;


int main()
{
	CAN1_init();
	uart0_init(9600);
	v1.rtr=0;
	v1.dlc=1;
	v1.byteA=0;
	v1.byteB=0;
	v1.ff=0;
	
	while(1)
	{
		if(sw1==0) //wait for switch press
		{
			while(sw1==0); //wait for release
			delay_ms(20); //switch bounce back
			flag_HL^=1;
			v1.id=0x150;
			uart0_tx_string("HL ON/OFF\r\n");
			if(flag_HL)
				v1.byteA=0x50;
			else
				v1.byteA=0x51;
			CAN1_tx(v1);
		}
		if(sw2==0)
		{
			while(sw2==0);
			delay_ms(20);
			flag_LI^=1;
			v1.id=0x151;
			uart0_tx_string("L indi ON/OFF\r\n");
			if(flag_LI)
				v1.byteA=0x52;
			else
				v1.byteA=0x53;
			CAN1_tx(v1);
		}
		if(sw3==0)
		{
			while(sw3==0);
			delay_ms(20);
			flag_RI^=1;
			v1.id=0x152;
			uart0_tx_string("R indi ON/OFF\r\n");
			if(flag_RI)
				v1.byteA=0x54;
			else
				v1.byteA=0x55;
			CAN1_tx(v1);
		}
	
	}
}
