#include<reg51.h>

sbit sw1=P1^0;
sbit sw2=P1^1;
sbit sw3=P1^2;
sbit sw4=P1^3;
sbit sw5=P1^4;
sbit sw6=P1^5;
sbit sw7=P1^6;
sbit sw8=P1^7;

sbit led1=P3^0;
sbit led2=P3^1;
sbit led3=P3^2;
sbit led4=P3^3;
sbit led5=P3^4;
sbit led6=P3^5;
sbit led7=P3^6;
sbit led8=P3^7;

char a[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
char b[8]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};

void delay(unsigned int ms)
{
   int i,j;
   for(i=0;i<ms;i++)
   {
      for(j=0;j<1275;j++);
   }
}
void increment()
{
   char i; 
   for(i=0;i<=7;i++)
   {
       P3=a[i];
	   delay(1);
   }
}

void decrement(unsigned char m)
{
   char i; 
   for(i=0;i<=m;i++)
   {
       P3=b[i];
	   delay(100);
   }
}
  

void main()
{
  
       // static char new=0,old=0;
        P3=0x00;
		P1=0xff;
		if(sw1==0)
		{
		   decrement(0);		      
		   led8=1;
        }
		 if(sw2==0)
		{
		 // decrement(1);
		   led7=1;
		}
		 if(sw3==0)
		{
		  //decrement(2);
		}
		else if(sw4==0)
		{
		  //decrement(3);
		}
		else if(sw5==0)
		{
		 // decrement(4);
		}
		else if(sw6==0)
		{
		  //decrement(5);
		}
		else if(sw7==0)
		{
		  //decrement(6);
		}	
		else if(sw8==0)
		{
		  //decrement(7);
		}

		
	

	

     }

