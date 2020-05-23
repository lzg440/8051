#include<reg51.h>  

/*led*/
sbit m0=P0^0;
sbit m1=P0^1;
sbit m2=P0^2;

/*limit swich*/
sbit l1=P2^3;
sbit l2=P2^4;
sbit l3=P2^5;

sbit motor1=P0^6;
sbit motor2=P0^7;

/*pushbutton*/
sbit sm0=P2^0;
sbit sm1=P2^1;
sbit sm2=P2^2;

void motor_fw()
{
   motor1=1;
   motor2=0;
}
void motor_re()
{
   motor1=0;
   motor2=1;
}
void motor_off()
{
   motor1=0;
   motor2=0;
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
		 if(i==0)
		 {
		 	m1=0;
			m0=1;
			m2=0;
			motor_off();
		 }
		 if(i==1)
		 {
			m2=0;
			m1=0;
			m0=1;
			while(l1==1)
			{
				motor_re();
			}
			motor_off();

		 }
		 if(i==2)
		 {
			m0=1;
			m2=0;
			m1=0;
			while(l1==1)
			{
				 motor_re();
			}
			motor_off();
		 }
	 i=0;
	 }
     if(sm1==0)
	 {	
			if(i==0)
			{
				m0=0;
				m1=1;
				m2=0;
				while(l2==1)
				{
				   motor_fw();
				}
				motor_off();
			}
			if(i==1)
			{
				m2=0;
				m1=1;
				m0=0;
	     		while(l2==1)
				{
				   motor_fw();
				}
				motor_off();
			}
			if(i==2)
			{
				m2=0;
			    m1=1;
				m0=0;
				while(l2==1)
				{
				   motor_re();
				}
				motor_off();
     	    }
	 i=1;
     }
	 if(sm2==0)
	 {	
			if(i==0)
			{
			  m0=0; 
			  m2=1;
			  m1=0;
			  while(l3==1)
			  {
				   motor_fw();
			  }
			  motor_off();
			}
			if(i==1)
			{
				m1=0;
				m2=1;
				m0=0;
				while(l3==1)
				{
				   motor_fw();
				}
				motor_off();
            }
			if(i==2)
			{
				m2=1;
				m0=0;
				m1=0;
				motor_off();
		    }
	 i=2;
	 }
	 
}

}


			


