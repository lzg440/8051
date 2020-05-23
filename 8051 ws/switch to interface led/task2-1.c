#include<reg51.h>
sbit sw=P2^0;
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
  while(1)
  { 
     
	    while(sw==0);
	    while(sw==1)
		{
          shift_right();
		  delay(20);
		}
		while(sw==0);
	    while(sw==1)
		{
		    shift_left();
		    delay(20);
		}
		while(sw==0);
	    while(sw==1)
		 {
		     shift_rightfull();
			 delay(20);
		 }
		 while(sw==0);
	     while(sw==1)
		 {
			shift_leftfull();
			delay(20);
		 }

  }
}		
void delay(unsigned int time)
{
   int i,j;
   for(i=0;i<time;i++)
   {
       for(j=0;j<1275;j++);
	   if(sw==0)
	   { 
	      break;
	   }
	   else;
   }

}
void shift_right()
{
      int n;
	  for(n=0;n<9;n++)
	  {
	    	P1=a[n];
	  }		delay(20);
}
void shift_left()
{
      int c;
	  for(c=0;c<9;c++)
	  {
	     
	      P1=b[c];
		  delay(20);
   	  }
}
void shift_rightfull()
{
   	 int d;
	 for(d=0;d<9;d++)
	 {
	     
	     P1=e[d];
		 delay(20);
	 }
}
void shift_leftfull()
{
   	 int g;
	 for(g=0;g<9;g++)
	 {
	     
	     P1=f[g];
		 delay(20);
	 }
}

