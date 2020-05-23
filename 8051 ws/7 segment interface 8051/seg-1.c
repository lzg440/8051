#include<reg51.h>
unsigned char z;
unsigned int j;
unsigned char num1[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0xff,0x6f};
void main()
{
	  while(1)
	  {
		 for(z=0;z<10;z++)
		 {
		    P1=0x01;
		    P3=num1[z];
			for(j=1;j<20000;j++);
		 }
	  }
}