#include<reg51.h>
sbit sw P1^0
void increment();
void decrement();
void shift_left();
void shift_right();
void shift_rightfull();
void shift_leftfull();
void delay(unsigned int time);
int a[8]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
int b[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
int e[8]={0x80,0xc0,0xe0,0xfe,0xf8,0xfc,0xfe,0xff};
int f[8]={0xfe,0xfc,0xf8,0xfe,0xe0,0xc0,0x80,0x00};
void main()
{
   increment();
   delay(200);
   decrement();
   delay(200);
   shift_left();
   delay(200);
   shift_right();
   delay(200);
   shift_rightfull();
   delay(200);
   shift_leftfull();
   delay(200);
}
void delay(unsigned int time)
{
   int i,j;
   for(i=0;i<time;i++)
   {
       for(j=0;j<1275;j++);
   }
}
void increment()
{
   unsigned int k;
   for(k=0;k<256;k++)
   {
         delay(20);
       	 P1=k;
   }
}
void decrement()
{
   unsigned int m;
   for(m=255;m>0;m--)
   {
         delay(20);
       	 P1=m;
   }
}
void shift_right()
{
      int n;
	  for(n=0;n<9;n++)
	  {
	        delay(200);
	    	P1=a[n];
	  }
}
void shift_left()
{
      int c;
	  for(c=0;c<9;c++)
	  {
	      delay(200);
	      P1=b[c];
   	  }
}
void shift_rightfull()
{
   	 int d;
	 for(d=0;d<9;d++)
	 {
	     delay(200);
	     P1=e[d];
	 }
}
void shift_leftfull()
{
   	 int g;
	 for(g=0;g<9;g++)
	 {
	     delay(200);
	     P1=f[g];
	 }
}
