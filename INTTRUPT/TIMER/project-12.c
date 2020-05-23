		 #include<reg51.h>
		 #include"lcd4bit.h"
		 unsigned char num[4]={0xf7,0xfb,0xfd,0xfe};
		 unsigned int i,j;
		 void main()
		 {
		 lcdinit();
		 while(1)
		 {
		    for(j=0;j<4;j++)
			{
			   P1=num[j];
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
			       while(P1==0xd
				   );
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
