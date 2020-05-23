#include<reg51.h>
sfr led=0x90;
sbit sw=P2^2;
void increment();
void delay(unsigned int time);
void main()
{
   led=0x00;
   while(1)
   {
     if(sw==0)
     {
        increment();
		delay(20);
     }
     else;
   }
}
void increment()
{
    
	
       led++;
	   
}  
void delay(unsigned int time)
 {
     int i,j;
     for(i=0;i<time;i++)
     {
       for(j=0;j<1275;j++);
     }
}
	   
