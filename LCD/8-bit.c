		#include<reg51.h>
		sbit rs=P1^0;
		sbit rw=P1^1;
		sbit en=P1^2;
		void delay(int a)
		{
		    int i,j;
			for(i=0;i<a;i++)
			{
			   for(j=0;j<1275;j++);
			}
		}
		void cmd(unsigned char b)
		{
		   P2=b;
		   en=1;
		   rs=0;
		   rw=0;
		   delay(100);
		   en=0;
		}
		void data1(unsigned char c)
		{
		   P2=c;   
		   en=1;
		   rs=1;
		   rw=0;
		   delay(100);
		   en=0;
		}
		void data2(unsigned char *lcdstr)
		{
		   while(*lcdstr)
		   {
		      data1(*lcdstr++);
		   }
		}
		void main()
		{		  
		   cmd(0x38);
		   delay(100);
		   cmd(0x0e);
		   delay(100)		   cmd(0x80);
		   delay(100);
		   cmd(0x01);
		   delay(100);
		   data2("vasoya nikhil");
		   delay(100);
		   cmd(0xc0);
		   delay(100);
		   data2("5TH EC");
		   delay(100);
		   while(1);
	    
		}