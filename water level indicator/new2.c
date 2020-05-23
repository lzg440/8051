#include<reg51.h>
#include <string.h>

sbit limitup=P1^4;
sbit limitdown=P1^5;

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

unsigned char x=0,y=0;


void sendbyte(char A)
{
   SBUF=A;
   while(TI==0);
   TI=0;	
}
void send(char *A)
{
	int i;
	for(i=0;A[i]!=0;i++)
	{
	 sendbyte(A[i]);
	}
}
void smssendlevel3()
{
                unsigned int i;
                for(i=0;i<50000;i++);
				send("AT+CMGS=");
			    sendbyte(0x22);
			 	send("9099230210");
				sendbyte (0x22);
				sendbyte (0x0d);
				sendbyte (0x0a);
				for(i=0;i<50000;i++);
		    	send("dam water level 3");
				sendbyte(0x1a);
}
void smssendlevel4()
{
                unsigned int i;
                for(i=0;i<50000;i++);
				send("AT+CMGS=");
			    sendbyte(0x22);
			 	send("9099230210");
				sendbyte (0x22);
				sendbyte (0x0d);
				sendbyte (0x0a);
				for(i=0;i<50000;i++);
		    	send("dam gate open");
				sendbyte(0x1a);
}

 void main()
 {
 		char flag;
		
       	P1=0xff;
		P2=0x00;
	//	P3=0xff;
		P0=0x00;
		SCON  = 0x50;		        /* SCON: mode 1, 8-bit UART, enable rcvr      */
	    TMOD = 0x20;               /* TMOD: timer 1, mode 2, 8-bit reload        */
		TH1   = -3;                /* TH1:  reload value for 1200 baud @ 16MHz   */
		TR1   = 1;                  /* TR1:  timer 1 run                          */
		TI    = 0;
		RI=0;  

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
			flag=1;
		    y=0;
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
			if(flag==1)
			{
				buzzer=0;
		    }
			leval4=0;
	    	leval3=0;
	    	leval2=0;
	    	leval1=1;
			if(y==0)
			{
		   		smssendlevel3();
		   		y=1;
			}
		

		 if(x==1)
		 {
           motor_left1=0;
	       motor_left2=1;
	       motor_right1=0;
	       motor_right2=1;
	       x=0;
		   if(y==0)
		   {
		     smssendlevel3();
			 y=1;
		   }
		   while(limitdown==1);
		   motor_left1=0;
	       motor_left2=0;
	       motor_right1=0;
	       motor_right2=0;
		 }

	    }
	if((P1&0x0f)==0x00)
		{
		buzzer=1;
		flag=0;
		leval4=0;
	    leval3=0;
	    leval2=0;
		leval1=0;
		x=1;
		y=0;
	    if(y==0)
		{
		    smssendlevel4();
			y=1;
		}
	    motor_left1=1;
	    motor_left2=0;
	    motor_right1=1;
	    motor_right2=0;
	    while(limitup==1);
	    motor_left1=0;
	    motor_left2=0;
	    motor_right1=0;
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
           buzzer=1;
	    }
     }
   }
  