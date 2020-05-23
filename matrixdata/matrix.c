#include <reg51.h>

int a[5]={0x01,0x02,0x04,0x08,0x10};
int b[5]={0x00,0xfd,0xfb,0xf7,0xe0};

void delay(unsigned int time)
{
   int i,j;
   for(i=0;i<time;i++)
   {
       for(j=0;j<1275;j++);
   }
}
void main()
{
    int i,j;
	P1=0xff;
	P2=0x00;
	while(1)
	{
	   for(i=0;i<5;i++)
	   {
	     P2=a[i];
		 P1=b[i];
		 delay(1);
		 P1=0xff;
	     P0=0x00;
	   }

	}
}
