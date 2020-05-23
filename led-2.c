	#include<reg51.h>
	sbit sw1=P1^0;
	sbit sw2=P1^1;
	sbit sw3=P1^2;
	sbit sw4=P1^3;
	sbit sw5=P1^4;
	sbit sw6=P1^5;
	sbit sw7=P1^6;
	sbit sw8=P1^7;
	sbit led1=P2^0;
	sbit led2=P2^1;
	sbit led3=P2^2;
	sbit led4=P2^3;
	sbit led5=P2^4;
	sbit led6=P2^5;
	sbit led7=P2^6;
	sbit led8=P2^7;
     void main()
	{
	   P1=0Xff;
	   P2=0X00;
	   while(1)
	   {
	    int j;
	      P2=0xff;
		  for(j=0;j<2000;j++);
		  P2=0x00;
		}
	   //if(sw1==0)
	   //{   led1=1;
	   //}
	   //else if(sw2==0)
	  /* { 
	   		led2=1;
	   }
	   else if(sw3==0)
	   { 
	   	led3=1;
	   }
	   else if(sw4==0)
	   { 
	    led4=1;
	   }
	   else if(sw5==0)
	   { 
	   led5=1;
	   }
	   else if(sw6==0)
	   { 
	   led6=1;
	   }
	   else if(sw7==0)
	   { 
	   led7=1;
	   }
	   else if(sw8==0)
	   { 
	   led8=1;
	   }
	   else
	   {
	    P2=0x00;
	   }*/
	}


	   