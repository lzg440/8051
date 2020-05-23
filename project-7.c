	        #include<reg51.h>
			unsigned char num1[]={0x00,0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff};
			
		    sbit sw1=P1^0;
			sbit sw2=P1^1;
		    unsigned char z;
			
		    void main()
			{
			   P1=0xff;
			   P2=0x00;
			   while(1)
			   {
			     if(sw1==0)
			     {
			       z++;
				  while(sw1==0) 
				   P2=num1[z];
				  }
				  else if(sw2==0)
				  {
				    z--;
					while(sw2==0)
					 P2=num1[z];
				   }
				   
				}
				}
				

			     
			 