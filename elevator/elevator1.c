#include<reg51.h>
sbit m0=P3^0;
sbit m1=P3^1;
sbit m2=P3^2;
sbit m3=P3^3;
sbit m4=P3^4;
sbit m5=P3^5;
sbit m6=P3^6;
sbit m7=P3^7;


sbit sm0=P1^0;
sbit sm1=P1^1;
sbit sm2=P1^2;
sbit sm3=P1^3;
sbit sm4=P1^4;
sbit sm5=P1^5;
sbit sm6=P1^6;
sbit sm7=P1^7;

void delay()
{
	unsigned int k,l;
	for(k=0;k<60000;k++);
	for(l=0;l<60000;l++);
}



void main()
{
	unsigned char i;
	P0=0x00;
	P2=0xff;
	m0=1;
	while(1)
	{
	if(sm0==0)
	{
		 if(i==1)
		 {
		 	m1=0;
			m0=1;
		}
		if(i==2)
		{
			m2=0;
			m1=1;
			delay();
			m1=0;
			m0=0;
		}
		if(i==3)
		{
			m3=0;
			m2=1;
			delay();
			m2=0;
			m1=1;
			delay();
			m1=0;
			m0=1;
		}

	    if(i==4)
		{	m4=0;
			m3=1;
			delay();
			m3=0;
			m2=1;
			delay();
			m2=0;
			m1=1;
			delay();
			m1=0;
			m0=1;
		}
		if(i==5)
		{	
			m5=0;
			m4=1;
			delay();
			m4=0;
			m3=1;
			delay();
			m3=0;
			m2=1;
			delay();
			m2=0;
			m1=1;
			delay();
			m1=0;
			m0=1;
		}
		if(i==6)
		{	m6=0;
			m5=1;
			delay();
			m5=0;
			m4=1;
			delay();
			m4=0;
			m3=1;
			delay();
			m3=0;
			m2=1;
			delay();
			m2=0;
			m1=1;
			delay();
			m1=0;
			m0=1;
		}
		if(i==7)
		{	
			m7=0;
			m6=1;
			delay();
			m6=0;
			m5=1;
			delay();
			m5=0;
			m4=1;
			delay();
			m4=0;
			m3=1;
			delay();
			m3=0;
			m2=1;
			delay();
			m2=0;
			m1=1;
			delay();
			m1=0;
			m0=1;
		}
		 i=0;

	}
	if(sm1==0)
		{	
			if(i==0)
			{
				m0=0;
				m1=1;
			}
			if(i==2)
			{
				m2=0;
				m1=1;
			}
			if(i==3)
			{
				m3=0;
				m2=1;
				delay();
				m2=0;
				m1=1;
			}

			if(i==4)
			{
			m4=0;
			m3=1;
			delay();
			m3=0;
			m2=1;
			delay();
			m2=0;
			m1=1;
			
		}
		if(i==5)
		{	
			m5=0;
			m4=1;
			delay();
			m4=0;
			m3=1;
			delay();
			m3=0;
			m2=1;
			delay();
			m2=0;
			m1=1;
		
		}
		if(i==6)
		{	m6=0;
			m5=1;
			delay();
			m5=0;
			m4=1;
			delay();
			m4=0;
			m3=1;
			delay();
			m3=0;
			m2=1;
			delay();
			m2=0;
			m1=1;
			
		}
		if(i==7)
		{	
			m7=0;
			m6=1;
			delay();
			m6=0;
			m5=1;
			delay();
			m5=0;
			m4=1;
			delay();
			m4=0;
			m3=1;
			delay();
			m3=0;
			m2=1;
			delay();
			m2=0;
			m1=1;
			
		}
		
			i=1;
		}
	if(sm2==0)
		{	
			if(i==0)
			{
				
				m0=0; 
				m1=1;
				delay();
				m1=0;
				m2=1;
			}

			if(i==1)
			{
				m1=0;
				m2=1;
			}
			if(i==3)
			{
				m3=0;
				m2=1;
			}
			if(i==4)
		{	m4=0;
			m3=1;
			delay();
			m3=0;
			m2=1;
			
		}
		if(i==5)
		{	
			m5=0;
			m4=1;
			delay();
			m4=0;
			m3=1;
			delay();
			m3=0;
			m2=1;
			
		}
		if(i==6)
		{	m6=0;
			m5=1;
			delay();
			m5=0;
			m4=1;
			delay();
			m4=0;
			m3=1;
			delay();
			m3=0;
			m2=1;
		}
		if(i==7)
		{	
			m7=0;
			m6=1;
			delay();
			m6=0;
			m5=1;
			delay();
			m5=0;
			m4=1;
			delay();
			m4=0;
			m3=1;
			delay();
			m3=0;
			m2=1;
		
		}
			i=2;
		}
	if(sm3==0)
		{
			if(i==0)
			{
				m0=0;
				m1=1;
				delay();
				m1=0;
				m2=1;
				delay();
				m2=0;
				m3=1;
			}
			if(i==1)
			{
				m1=0;
				m2=1;
				delay();
				m2=0;
				m3=1;
			}
			 if(i==2)
			 {
			 	m2=0;
				m3=1;
			}
			if(i==4)
		{	m4=0;
			m3=1;
			
		}
		if(i==5)
		{	
			m5=0;
			m4=1;
			delay();
			m4=0;
			m3=1;
		
		}
		if(i==6)
		{	m6=0;
			m5=1;
			delay();
			m5=0;
			m4=1;
			delay();
			m4=0;
			m3=1;
		
		}
		if(i==7)
		{	
			m7=0;
			m6=1;
			delay();
			m6=0;
			m5=1;
			delay();
			m5=0;
			m4=1;
			delay();
			m4=0;
			m3=1;
		
		}
			i=3;
		}


	if(sm4==0)
	{
			
		if(i==0)
		{
			m0=0;
			m1=1;delay();
			m1=0;
			m2=1;delay();
			m2=0;
			m3=1;delay();
			m3=0;
			m4=1;
		}

		 if(i==1)
		 {	m1=0;
		 	m2=1;
			delay();
			m2=0;
			m3=1;delay();
			m3=0;
			m4=1;
		 
		}
		if(i==2)
		{
			m2=0;
			m3=1;delay();
			m3=0;
			m4=1;
		}
		if(i==3)
		{	m3=0;
			m4=1;
			
		}

	    if(i==5)
		{	
			m5=0;
			m4=1;
		
		}
		if(i==6)
		{	
			m6=0;
			m5=1;
			delay();
			m5=0;
			m4=1;
			
		}
		if(i==7)
		{	m7=0;
			m6=1;
			delay();
			m6=0;
			m5=1;
			delay();
			m5=0;
			m4=1;
			
		}
		
		 i=4;

	}

	if(sm5==0)
	{
			
		if(i==0)
		{
			m0=0;
			m1=1;delay();
			m1=0;
			m2=1;delay();
			m2=0;
			m3=1;delay();
			m3=0;
			m4=1;delay();
			m4=0;
			m5=1;
		}

		 if(i==1)
		 {	m1=0;
		 	m2=1;
			delay();
			m2=0;
			m3=1;delay();
			m3=0;
			m4=1;delay();
			m4=0;
			m5=1;
		 
		}
		if(i==2)
		{
			m2=0;
			m3=1;delay();
			m3=0;
			m4=1;delay();
			m4=0;
			m5=1;
		}
		if(i==3)
		{	m3=0;
			m4=1;delay();
			m4=0;
			m5=1;
			
		}

	    if(i==4)
		{	
			m4=0;
			m5=1;
		
		}
		if(i==6)
		{	
			m6=0;
			m5=1;
						
		}
		if(i==7)
		{	
			m7=0;
			m6=1;delay();
			m6=0;
			m5=1;
						
		}
		
		 i=5;

	}


		if(sm6==0)
	{
			
		if(i==0)
		{
			m0=0;
			m1=1;delay();
			m1=0;
			m2=1;delay();
			m2=0;
			m3=1;delay();
			m3=0;
			m4=1;delay();
			m4=0;
			m5=1;delay();
			m5=0;
			m6=1;

		}

		 if(i==1)
		 {	m1=0;
		 	m2=1;
			delay();
			m2=0;
			m3=1;delay();
			m3=0;
			m4=1;delay();
			m4=0;
		    m5=1;delay();
			m5=0;
			m6=1;
		 
		}
		if(i==2)
		{
			m2=0;
			m3=1;delay();
			m3=0;
			m4=1;delay();
			m4=0;
			m5=1;delay();
			m5=0;
			m6=1;
		}
		if(i==3)
		{	m3=0;
			m4=1;delay();
			m4=0;
	        m5=1;delay();
			m5=0;
			m6=1;			
			
		}

	    if(i==4)
		{	
			m4=0;
			m5=1;delay();
			m5=0;
			m6=1;
		
		}
		if(i==5)
		{	
			m5=0;
			m6=1;
						
		}
		if(i==7)
		{	
			m7=0;
			m6=1;					
		}
		
		 i=6;

	}

	

			if(sm7==0)
	{
			
		if(i==0)
		{
			m0=0;
			m1=1;delay();
			m1=0;
			m2=1;delay();
			m2=0;
			m3=1;delay();
			m3=0;
			m4=1;delay();
			m4=0;
			m5=1;delay();
			m5=0;
			m6=1;delay();
			m6=0;
			m7=1;

		}

		 if(i==1)
		 {	m1=0;
		 	m2=1;
			delay();
			m2=0;
			m3=1;delay();
			m3=0;
			m4=1;delay();
			m4=0;
		    m5=1;delay();
			m5=0;
			m6=1;delay();
			m6=0;
			m7=1;
		 
		}
		if(i==2)
		{
			m2=0;
			m3=1;delay();
			m3=0;
			m4=1;delay();
			m4=0;
			m5=1;delay();
			m5=0;
			m6=1;delay();
			m6=0;
			m7=1;
		}
		if(i==3)
		{	m3=0;
			m4=1;delay();
			m4=0;
	        m5=1;delay();
			m5=0;
			m6=1;delay();
			m6=0;
			m7=1;			
			
		}

	    if(i==4)
		{	
			m4=0;
			m5=1;delay();
			m5=0;
			m6=1;delay();
			m6=0;
			m7=1;
		
		}
		if(i==5)
		{	
			m5=0;
			m6=1;delay();
			m6=0;
			m7=1;
						
		}
		if(i==6)
		{	
			m6=0;
			m7=1;					
		}
		
		 i=7;

	}

	 }

			


}