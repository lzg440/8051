#include <REG51.H>
void sendbyte(char A);
void send(char A[]);


void main()
{
SCON  = 0x50;		        /* SCON: mode 1, 8-bit UART, enable rcvr      */
TMOD = 0x20;               /* TMOD: timer 1, mode 2, 8-bit reload        */
TH1   = 0xfd;                /* TH1:  reload value for 1200 baud @ 16MHz   */
TR1   = 1;                  /* TR1:  timer 1 run                          */
TI    = 0;  
 
  send("ATD 9999999999;");// write your mobile number 

  sendbyte(0x0d);
  sendbyte(0x0A);
 
 while(1);
 }

void sendbyte(char A)
{
 SBUF=A;
 while(TI==0);
 TI=0;	
}


void send(char A[])
{
int i;
for(i=0;A[i]!=0;i++)
	{
	 sendbyte(A[i]);
	}
}
