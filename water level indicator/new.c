#include<reg51.h>

sbit motor_left1=P0^0;
sbit motor_left2=P0^1;
sbit motor_right1=P0^2;
sbit motor_right2=P0^3;

sbit leval4=P2^4;
sbit leval3=P2^5;
sbit leval2=P2^6;
sbit leval1=P2^7;
	    
sbit input4=P1^0;
sbit input3=P1^1;
sbit input2=P1^2;
sbit input1=P1^3;

sbit buzzer=P2^3;

unsigned char x=0;
 void main()
 {
       	P1=0x0f ;
		P2=0x00;
		P3=0xff;
		P0=0x00;

	while(1)
		{
	if((P1&0x0f)==0x07)
		{
			buzzer=1;
	    leval4=0;
		leval3=1;
		leval2=1;
	    leval1=1;
	    motor_left1=0;
	    motor_left2=0;
	    motor_right1=0;
	    motor_right2=0;
	    }

	if((P1&0x0f)==0x03)
	    {
			buzzer=1;
	    leval4=0;
	    leval3=0;
		leval2=1;
	    leval1=1;

	    motor_left1=0;
	    motor_left2=0;
	    motor_right1=0;
	    motor_right2=0;						 

	    }				 

	if((P1&0x0f)==0x01)
		{
			buzzer=0;
		leval4=0;
	    leval3=0;
	    leval2=0;
	    leval1=1;
	    
		if(x==1)
		{
		motor_left1=0;
	    motor_left2=1;
	    motor_right1=0;
	    motor_right2=1;
		x=0;
		}

		}
	if((P1&0x0f)==0x00)
		{
		buzzer=1;
		leval4=0;
	    leval3=0;
	    leval2=0;
		leval1=0;
		x=1;
	   motor_left1=1;
	   motor_left2=0;
	   motor_right1=1;
	   motor_right2=0;

		}

	if((P1&0x0f)==0x0f)
		{
		 motor_left1=0;
	     motor_left2=0;
	     motor_right1=0;
	     motor_right2=0;

		leval1=1;
	    leval2=1;
	    leval3=1;
	    leval4=1;
	 
	 	}


	 }
   }
  