#include<reg51.h>

sfr ldata=0xa0;

sbit rs=P2^0; 
sbit rw=P2^1;
sbit e=P2^2; 

void delay(unsigned char time)
{
    unsigned int i,j;
	for(j=0;j<time;j++)
	{
	   for(i=0;i<1275;i++);
	}
} 
void  cmd(unsigned char val)
{
      rs=0;
	  rw=0;
	  e=1;
	  delay(1);
	  e=0;
	  
}
void  data(unsigned char val)
{
      rs=1;
	  rw=0;
	  e=1;
	  delay(1);
	  e=0;
	  
}
void data1(unsigned char *lcdstr)
{
   while(*lcdstr)
   {
		 data(*lcdstr++);
   }
}		
void main()
{
    cmd(0x38);
	delay(250);
	cmd(0x0e);
	delay(250);
	cmd(0x01);
	delay(250);
	cmd(0x06);
	delay(250);
	cmd(0x84);
	delay(250);
	data1("vasoya nikhil");
	delay(250);
	cmd(0xc0);
	delay(250);
	data1("6th 10EC23");
	delay(250);
}