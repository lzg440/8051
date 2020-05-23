		#include<reg51.h>
		
		
		   unsigned char num[17]={0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe,0xff,0x00,0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff};
		   unsigned char z;
		   unsigned int i;
		void main()
		{
			while(1)
			{
		   for(z=1;z<=17;z++)
		   {
		         P2=num[z];
				 for(i=1;i<30000;i++)
				 {
				 }
		   }
		   }
		 }     
