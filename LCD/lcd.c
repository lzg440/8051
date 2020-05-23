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
		   
		   delay(50);
		   en=0;
		}
		void data1(unsigned char c)
		{
		   P2=c;   
		   en=1;
		   rs=1;
		   rw=0;
		   
		   delay(50);
		   en=0;
		}
		void main()
		{
		while(1)
		{
		 
		   cmd(0x38);
		   delay(50);
		   cmd(0x0e);
		   delay(50);
		   cmd(0x01);
		   delay(50);
		   cmd(0x80);
		   delay(50);
		   data1('N');
		   delay(50);
			data1('I');
		   delay(50);
			data1('K');
		   delay(50);
			data1('H');
		   delay(50);
			data1('I');
		   delay(50);
		   data1('L');
		   delay(50);
		      data1('V');
		   delay(50);
		    data1('A');
		   delay(50);
		    data1('S');
		   delay(50);
		    data1('O');
		   delay(50);
		    data1('Y');
		   delay(50);
		    data1('A');
		   delay(50);
	    }
		}