
		#include<reg51.h>
		
		sbit rs=P3^2;
		sbit rw=P3^1;
		sbit en=P3^0;
		void delay(int a)
		{
		    int i,j;
			for(i=0;i<a;i++)
			{
			   for(j=0;j<1275;j++);
			}
		}
		void lcdcmd(unsigned char b)
		{
		   P1=b;
		   en=1;
		   rs=0;
		   rw=0;
		   
		   delay(50);
		   en=0;
		}
		void data1(unsigned char c)
		{
		   P1=c;   
		   en=1;
		   rs=1;
		   rw=0;
		   
		   delay(50);
		   en=0;
		}
		void data2(unsigned char *lcdstr)
		{
		   while(*lcdstr)
		   {
		      data1(*lcdstr++);
		   	}
		}
		
	    
		