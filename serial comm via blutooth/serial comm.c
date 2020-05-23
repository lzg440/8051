#include <reg51.h>
#include"uart.h"
sbit relay1=P0^0;
sbit relay2=P0^1;
sbit relay3=P0^2;
sbit relay4=P0^3;
sbit relay5=P0^4;
sbit relay6=P0^5;
sbit relay7=P0^6;
sbit relay8=P0^7;

void delay(unsigned  int time)
{
     unsigned int i,j;
	 for(i=0;i<time;i++)
	 	for(j=0;j<1275;j++);
}
void main ()
{	
/*	Initialize Serial Port
	Mode 1 
	9600 baud rate generated using Timer 1 @ 11.0592 MHz 
	
	Here we are using 3 pin serial connection
	Rx, Tx, Gnd.
	
	Rx = P3.0
	Tx = P3.1
	
	The connection to the other serial port are 
	Rx  --> Tx
	Tx  --> Rx
	Gnd --> Gnd
	
*/	
unsigned int a;
relay1=0;
relay2=0;
relay3=0;
relay4=0;
relay5=0;
relay6=0;
relay7=0;
relay8=0;
uart_ins();
	while(1) 		
	{
	  a=uart_receive();
	  if (a=='U')
	  {
	  relay1=1;
	  relay7=1;
	  }
	  else if (a=='u')
	  {
	  relay1=0;
	  relay7=0;
	  }
	  else if (a=='D')
	  {
	  relay2=1;
	  relay8=1;
	  }
	  else if (a=='d')
	  {
	  relay2=0;
	  relay8=0;
	  }
	  else if (a=='R')
	  {
	  relay2=1;
	  relay7=1;
	  }
	  else if (a=='r')
	  {
	  relay2=0;
	  relay7=0;
	  }
	  else if(a=='L')
	  {
	  relay1=1;
	  relay8=1;
	  }
      else if(a=='l')
	  {
	  relay1=0;
	  relay8=0;
	  }
	  else if(a=='W')
	  {
	  relay3=1;
	  }
	  else if(a=='w')
	  {
	  relay3=0;
	  }
	  else if(a=='X')
	  {
	  relay4=1;
	  }
	  else if(a=='x')
	  {
	  relay4=0;
	  }
	  else if(a=='Y')
	  {
	  relay5=1;
	  }
	  else if(a=='y')
	  {
	  relay5=0;
	  }
	  else if(a=='Z')
	  {
	  relay6=1;
	  }
	  else if(a=='z')
	  {
	  relay6=0;
	  }
	  else if(a=='n')
	  {
	  	relay1=0;
	 	relay2=0;
		relay3=0;
		relay4=0;
		relay5=0;
		relay6=0;
		relay7=0;
		relay8=0;
	  }
	  else if (a=='0')	//all for sharp turn only
	  {
	  relay1=1;
	  delay(250);
	  relay7=1;
	  }
	  else if (a=='4')
	  {	 
	  relay7=1;
	  delay(250);
	  relay1=1;
	  }
	  else if (a=='2')
	  {
	  relay2=1;
	  delay(250);
	  relay8=1;
	  }
	  else if (a=='4')
	  {
	  relay8=1;
	  delay(250);
	  relay2=1;
	  }
	 
//	uart_sends("B.H.Gardi");
//	uart_send(0x0d);	
	}
}
