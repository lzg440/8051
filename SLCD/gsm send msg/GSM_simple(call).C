#include <REG51.H>
void main()
{
SCON  = 0x50;		        /* SCON: mode 1, 8-bit UART, enable rcvr      */
TMOD = 0x20;               /* TMOD: timer 1, mode 2, 8-bit reload        */
TH1   = 0xfd;                /* TH1:  reload value for 1200 baud @ 16MHz   */
TR1   = 1;                  /* TR1:  timer 1 run                          */
TI    = 0;  
 SBUF='A';
 while(TI==0);
 TI=0;
 SBUF='T';
 while(TI==0);
 TI=0;
 
 SBUF='D';
 while(TI==0);
 TI=0;
 SBUF= 0x20;
 while(TI==0);
 TI=0;
 SBUF='9';    // write your mobile number digit
 while(TI==0);
 TI=0;
 SBUF='9';
 while(TI==0);
 TI=0;
 SBUF='9';
 while(TI==0);
 TI=0;
 SBUF='9';
 while(TI==0);
 TI=0;
 SBUF='9';
 while(TI==0);
 TI=0;
 SBUF='9';
 while(TI==0);
 TI=0;
 SBUF='9';
 while(TI==0);
 TI=0;
 SBUF='9';
 while(TI==0);
 TI=0;
 SBUF='9';
 while(TI==0);
 TI=0;
 SBUF='9';
 while(TI==0);
 TI=0;
 SBUF=';';
 while(TI==0);
 TI=0;
 SBUF=0x0D;
 while(TI==0);
 TI=0;
 SBUF=0x0A;
 while(TI==0);
 TI=0;
 while(1);
 }








