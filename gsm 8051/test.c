#include<reg51.h>
#include <string.h>

sbit start=P1^6;
sbit stop=P1^5;

void sendbyte(char A)
{
 TI=0;
 SBUF=A;
 while(TI==0);
 TI=0;	
}


void send(char A[])
{
	int i;
	for(i=0;A[i]!=0;i++)
	{
	 sendbyte(A[i]);
	}
}

void delay()					// Delay generation using Timer 0 mode 1
{
	int i;
	for(i=0;i<4;i++)
	{
   	TH0= 0x00;  				
		TL0 = 0xFD;
		TH0 = 0x4B;
		TR0 = 1;   				// Start Timer
		while(TF0 == 0); 			// Using polling method
		TR0 = 0; 				// Stop Timer
		TF0 = 0;				 // Clear flag
	} 	
	TR0=0;			
}

void main()
{
            unsigned int  i;
            //P1=0x00;
            
			SCON  = 0x50;		        /* SCON: mode 1, 8-bit UART, enable rcvr      */
			TMOD = 0x20;               /* TMOD: timer 1, mode 2, 8-bit reload        */
			TH1   = 0xfd;                /* TH1:  reload value for 1200 baud @ 16MHz   */
			TR1   = 1;                  /* TR1:  timer 1 run                          */
			TI    = 0;
			RI=0;  
		

			//send("NIKHIL VASOYA");
			/*send("ATD 9727252506;");
			sendbyte (0x0d);
			sendbyte (0x0a); */
		//	delay();
		    for(i=0;i<50000;i++);
			send("AT+CMGS=");
			sendbyte(0x22);
			send("9727252506");
			sendbyte (0x22);
			sendbyte (0x0d);
			sendbyte (0x0a);
			//delay();
		    for(i=0;i<50000;i++);
			send("nikhil vasoya");
			sendbyte(0x1a);	
		
			

			while(1)
			{
			  /* while(RI==0);
			   c=SBUF; 
			   RI=0;
			   P1=c;
			   if(P1=='Y') 
               {
	             start=1;	
				 stop=0;      
	           }
	           if(P1=='N')
               {
                 stop=1;
				 start=0;       
               }*/
			} 
}
