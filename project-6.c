		   #include<reg51.h>
		    unsigned char num1[8]={0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe,0xff};
			unsigned char num2[8]={0x7f,0x3f,0x1f,0x0f,0x07,0x03,0x01,0x00};
			sbit sw1=P1^0;
			sbit sw2=P1^1;
		    unsigned char z;
		    unsigned int i;
		   void main()
		   {
		     P2=0x00;
			 P1=0xff;
			 while(1)
			 {
		     if(sw1==0)
			 {
			    for(z=0;z<8;z++)
				{
				  P2=num1[z];
				  for(i=1;i<30000;i++)
				  {
				  }
				}
			  }
			  else if(sw2==0)
			  {
			  for(z=0;z<8;z++)
				{
				 
				  P2=num2[z];
				  for(i=1;i<30000;i++)
				  {
				  }

				}
			  }
			 
			}
			   
			}	  
