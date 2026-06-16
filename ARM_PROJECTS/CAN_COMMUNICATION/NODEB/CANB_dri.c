#include<lpc21xx.h>
#include"header.h"

extern u8 flag_rx;
extern CAN1 r;
void CAN1_rx_handler (void)__irq
{
	r.id=C1RID;
	r.dlc= (C1RFS>>16)&0xf;
	r.rtr= (C1RFS>>30)&1;
	if(r.rtr==0)
	{
		r.byteA=C1RDA;
		r.byteB=C1RDB;
	}
	C1CMR=1<<2;
	flag_rx=1;
	VICVectAddr=0;
}
void CAN1_rx_config(void)
{
	VICIntSelect=0;
	VICVectCntl5=26|1<<5;
	VICVectAddr5=(u32)CAN1_rx_handler;
	VICIntEnable=1<<26;
	C1IER=1;
}
