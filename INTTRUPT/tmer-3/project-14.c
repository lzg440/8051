		#include<reg51.h>
		#include"lcd4bit.h"
		sbit led=P3^5;
	    unsigned char k,l;
		unsigned char num3[4]={0xf7,0xfb,0xfd,0xfe};
		unsigned char U[3]={'1','2','3'},M[3];
		void main()
	    {
		 lcdinit();
		 while(1)
		 {
		   for(l=0;l<3;l++)
		   { 
             for(k=0;k<4;k++)
			  {
			   P1=num3[k];
			   if(P1==0x77)
			   {
			       while(P1==0x77);
			      	lcd_datac('0');
					M[l]=U[l];
							  
			   }
			   
			   else if(P1==0x7b)
			   {
			        while(P1==0x7b);
			       	lcd_datac('1');
				    M[l]=U[l];
				
			   }
			   else if(P1==0x7d)
			   {
			        while(P1==0x7d);
			       	lcd_datac('2');
				   M[l]=U[l];
				
			   }

			   else if(P1==0x7e)
			   {
			        while(P1==0x7e);
			       	lcd_datac('3');
					 M[l]=U[l];
			   }
			   else if(P1==0xb7)
			   {
			       while(P1==0xb7);
			       lcd_datac('4');
				   M[l]=U[l];
               }
			   else if(P1==0xbb)
			   {
			       while(P1==0xbb);
			       	lcd_datac('5');
					M[l]=U[l];
			   }
			   else if(P1==0xbd)
			   {
			        while(P1==0xbd);
			       	lcd_datac('6');
					M[l]=U[l];
					
		       }
			   else if(P1==0xbe)
			   {
			        while(P1==0xbe);   
			       	lcd_datac('7');
					M[l]=U[l];
			   }
			    else if(P1==0xd7)
			   {
			       while(P1==0xd7);
			       lcd_datac('8');
				  	M[l]=U[l];
			   }
			    else if(P1==0xdb)
			   {
			       while(P1==0xdb);
			       lcd_datac('9');
				   M[l]=U[l];
			   }
			    else if(P1==0xdd)
			   {
			       while(P1==0xdd);
			       lcd_datac('a');
				   M[l]=U[l];
			   }
			    else if(P1==0xde)
			   {
			        while(P1==0xde);
			       	lcd_datac('b');
					M[l]=U[l];
			   }
			    else if(P1==0xe7)
			   {
			       while(P1==0xe7);
			       lcd_datac('c');
				   M[l]=U[l];
				   
			   }
			    else if(P1==0xeb)
			   {
			       while(P1==0xeb);
			       lcd_datac('d');
				   M[l]=U[l];
			   }
			    else if(P1==0xed)
			   {	while(P1==0xed);
			       	lcd_datac('e');
					M[l]=U[l];
			   }
			    else if(P1==0xee)
			   {   
			        while(P1==0xee);
			       	lcd_datac('f');
				    M[l]=U[l];
			   }
			   while(1)
			   {
			  	 if(M[l]==1)
				 {
				   if(M[l]==2)
				   {
				     if(M[l]==3)
					 {
					   led=1;
					 }
					 else
				     {
				        lcddatas(2,"error");
			         }
				   }
				 }
				 
             }
         }
     }
  }
 }