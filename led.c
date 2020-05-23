	#include<reg51.h>
	sbit sw1=P1^0;
	sbit sw2=P1^1;
	sbit sw3=P1^2;
	sbit sw4=P1^3;
	sbit sw5=P1^4;
	sbit sw6=P1^5;
	sbit sw7=P1^6;
	sbit sw8=P1^7;
     void main()
	{
	   P1=0Xff;
	   if(sw1==1)
	   {   P2^0==1;
	   }
	   else if(sw2==1)
	   { 
	   P2^1==1;
	   }
	   else if(sw3==1)
	   { 
	   P2^2==1;
	   }
	   else if(sw4==1)
	   { 
	   P2^3==1;
	   }
	   else if(sw5==1)
	   { 
	   P2^4==1;
	   }
	   else if(sw6==1)
	   { 
	   P2^5==1;
	   }
	   else if(sw7==1)
	   { 
	   P2^6==1;
	   }
	   else if(sw8==1)
	   { 
	   P2^7==1;
	   }
	   else
	   {
	     P2=0x00;
	   }
	}


	   
	
