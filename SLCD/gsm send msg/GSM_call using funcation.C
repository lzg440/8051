#include <REG51.H>
void sendbyte(char A);
void main()
{
SCON  = 0x50;		        /* SCON: mode 1, 8-bit UART, enable rcvr      */
TMOD = 0x20;               /* TMOD: timer 1, mode 2, 8-bit reload        */
TH1   = 0xfd;                /* TH1:  reload value for 1200 baud @ 16MHz   */
TR1   = 1;                  /* TR1:  timer 1 run                          */
TI    = 0;  
 
  sendbyte('A');
  sendbyte('T');
  sendbyte('D');

  sendbyte('9');// write your mobile number only one digit
  sendbyte('7');
  sendbyte('2');
  sendbyte('7');
  sendbyte('2');
  sendbyte('5');
  sendbyte('2');
  sendbyte('5');
  sendbyte('0');
  sendbyte('6s');
  sendbyte(';');

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








