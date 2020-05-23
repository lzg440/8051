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
		     unsigned char e;
			 e=b;
		     rs=0;
			 rw=0;
		     b=b&0xf0;
			 b=b>>4;
			 b=b&0x0f;
			 P1=b;
			 en=1;
			 delay(50);
			 en=0;
			 e=e&0x0f;
			 P1=e;
			 en=1;
			 delay(50);
			 en=0;
         }
		void data1(unsigned char c)
		{
		    unsigned char f;
			 f=c;
		     rs=1;
			 rw=0;
		     c=c&0xf0;
			 c=c>>4;
			 c=c&0x0f;
			 P1=c;
			 en=1;
			 delay(50);
			 en=0;
			 f=f&0x0f;
			 P1=f;
			 en=1;
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
		