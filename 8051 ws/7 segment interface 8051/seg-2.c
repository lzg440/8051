#include<reg51.h>
unsigned char num[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0xff,0x6f};
sbit s1=P3^0;
sbit s2=P3^1;
sbit s3=P3^2;
sbit s4=P3^3;
unsigned char z,x,y,w,i;
unsigned int j;
void main()
{
  while(1)
  {	 
	  for(w=0;w<10;w++)
	  {   
			for(x=0;x<10;x++)
			{
				for(y=0;y<10;y++)
				{
				     for(z=0;z<10;z++)
				       {	   
							  P3=0xff;
				              P1=num[z];
							  s1=0;
							  for(j=1;j<6000;j++);
							  P3=0xff;
				              P1=num[y];
							  s2=0;
							  for(j=1;j<300;j++);
					   	      P3=0xff;
				              P1=num[x];
							  s3=0;
							  for(j=1;j<300;j++);
							  P3=0xff;
				              P1=num[w];
							  s4=0;
							  for(j=1;j<300;j++);
						}
				}
			}
	   }
	}
}