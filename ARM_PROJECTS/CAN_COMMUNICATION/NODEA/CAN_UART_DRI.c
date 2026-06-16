#include<lpc21xx.h>
#include "header.h"
void uart0_init(unsigned int baud)
{
 int pclk,res;
 int a[]={15,60,30,15,0};
 pclk=a[VPBDIV]*1000000;
 res=pclk/(16*baud);
 PINSEL0=0X5;
 U0LCR=0X83;
 U0DLL=res&0xff;
 U0DLM=(res>>8)&0xff;
 U0LCR=0X03;
}

void uart0_tx(unsigned char data)
{
 U0THR=data;
 while(((U0LSR>>5)&1)==0);
}

unsigned char uart0_rx(void)
{
 while((U0LSR&1)==0);
 return U0RBR;
}

void uart0_tx_string(const char *str)
{
 while(*str)
 	uart0_tx(*str++);
}

void uart0_integer(int num)
{
 int r=num%10;
 if(num>9)
 	uart0_integer(num/10);
 uart0_tx(r+48);
}
