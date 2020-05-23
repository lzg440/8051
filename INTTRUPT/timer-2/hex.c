		#include<reg51.h>
		#include"lcd4bit.h"
	    sbit sq=P3^7;
	    sbit sp1=P2^6;
	    unsigned int j;
	    unsigned char z,k;
	    unsigned char num1[4]={0x06,0x5b,0x4f,0x66};
	    unsigned char num2[4]={0x01,0x02,0x04,0x08};
		unsigned char num3[4]={0xf7,0xfb,0xfd,0xfe};
	    void ISR_t0(void) interrupt 1
	    {
	      TF0=0;
		  TL0=0xff;
		  TH0=0xcd;
	      for(z=0;z<4;z++)
		  {
		    P0=num1[z];
			P2=num2[z];
			for(j=1;j<200;j++)
			{}
		   
		  }
		}
		 void main()
	    {
	     sq=1;
		 TMOD=0x01;
		 IE=0x82;
		 TL0=0xff;
		 TH0=0xcd;
		 sq=0;
		 TR0=1;
		 lcdinit();
		 while(1)
		 {
		   for(k=0;k<4;k++)
			{
			   P1=num3[k];
			   if(P1==0x77)
			   {
			       while(P1==0x77);
			      	lcd_datac('0');
							  
			   }
			   
			   else if(P1==0x7b)
			   {
			        while(P1==0x7b);
			       	lcd_datac('1');
				
			   }
			   else if(P1==0x7d)
			   {
			        while(P1==0x7d);
			       	lcd_datac('2');
				
			   }

			   else if(P1==0x7e)
			   {
			        while(P1==0x7e);
			       	lcd_datac('3');
				
			   }
			   else if(P1==0xb7)
			   {
			       while(P1==0xb7);
			       lcd_datac('4');
				   
               }
			   else if(P1==0xbb)
			   {
			       while(P1==0xbb);
			       	lcd_datac('5');
					
			   }
			   else if(P1==0xbd)
			   {
			        while(P1==0xbd);
			       	lcd_datac('6');
					
		       }
			   else if(P1==0xbe)
			   {
			        while(P1==0xbe);   
			       	lcd_datac('7');
					
			   }
			    else if(P1==0xd7)
			   {
			       while(P1==0xd7);
			       lcd_datac('8');
				  
			   }
			    else if(P1==0xdb)
			   {
			       while(P1==0xdb);
			       lcd_datac('9');
				   
			   }
			    else if(P1==0xdd)
			   {
			       while(P1==0xdd);
			       lcd_datac('a');
				   
			   }
			    else if(P1==0xde)
			   {
			        while(P1==0xde);
			       	lcd_datac('b');
					
			   }
			    else if(P1==0xe7)
			   {
			       while(P1==0xe7);
			       lcd_datac('c');
				   
			   }
			    else if(P1==0xeb)
			   {
			       while(P1==0xeb);
			       lcd_datac('d');
				  
			   }
			    else if(P1==0xed)
			   {	while(P1==0xed);
			       	lcd_datac('e');
					
			   }
			    else if(P1==0xee)
			   {   
			        while(P1==0xee);
			       	lcd_datac('f');
					
			   }
			}
		 
	    }
     }