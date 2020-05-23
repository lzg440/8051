#include <REG51.H>
void sendbyte(char A);
void send(char A[]);
void delay_ms(int itime);


void main()
{
SCON  = 0x50;		        /* SCON: mode 1, 8-bit UART, enable rcvr      */
TMOD = 0x20;               /* TMOD: timer 1, mode 2, 8-bit reload        */
TH1   = 0xfd;                /* TH1:  reload value for 1200 baud @ 16MHz   */
TR1   = 1;                  /* TR1:  timer 1 run                          */
TI    = 0;  
RI =0;

while(RI==0);

send("ATH");
sendbyte(0x0D);
sendbyte(0x0A);


delay_ms(50);

 
  send("AT+CMGS=");
  sendbyte(0x22);
 send("9999999999;");// write your mobile number 
  sendbyte(0x22);

  sendbyte(0x0D);
  sendbyte(0x0A);

  send("HELLO HOW ARE YOU? ");// write message.
  sendbyte(0x1A);
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


void delay_ms(int itime)
{
 int i,j;
 for(i=0;i<itime;i++)
 for(j=0;j<1275;j++);
}