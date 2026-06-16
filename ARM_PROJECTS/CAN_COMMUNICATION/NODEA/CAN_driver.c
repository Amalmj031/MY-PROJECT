#include<lpc21xx.h>
#include"header.h"
void CAN1_init(void)
{
	VPBDIV=1;
	PINSEL1|=0x40000;	//pin set for p0.25
	C1MOD=1;   //reset mode
	AFMR=1;	   //ignore all incoming frame
	C1BTR=0X001C001D;  //set baud rate
	C1MOD=0;
}
#define TCS ((C1GSR>>3)&1)
void CAN1_tx(CAN1 v)
{
 C1TID1=v.id;
 C1TFI1=v.dlc<<16;	//set dlc,rtr,ff
 if(v.rtr==0){	//if data-frame
 	C1TDA1=v.byteA;
	C1TDB1=v.byteB;
	}
 else
 	C1TFI1=1<<30; //rtr=1 remote frame

 C1CMR=0X21; //select txbuf1 & start tx
 while(TCS==0);
}

#define RBS (C1GSR&1)
void CAN1_rx(CAN1 *ptr)
{
 while(RBS==0);	//waiting to receive data
 ptr->id=C1RID;
 ptr->dlc=(C1RFS>>16)&0XF;
 ptr->rtr=(C1RFS>>30)&1;
 if(ptr->rtr==0){//if itis data frame
  ptr->byteA=C1RDA;
  ptr->byteB=C1RDB;
 }
 C1CMR=(1<<2);//release rx buffer

}
