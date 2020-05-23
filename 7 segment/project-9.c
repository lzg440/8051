	   #include<reg51.h>
       unsigned char z;
	   unsigned int j;
	   unsigned char num1[4]={0x06,0x5b,0x4f,0x66};
	   unsigned char num2[4]={0x01,0x02,0x04,0x08};
	   void main()
	   {
	     while(1)
		 {
		   for(z=0;z<4;z++)
		   {
		    P1=num1[z];
			P2=num2[z];
			for(j=1;j<200;j++)
			{}
		   }
		 }
		}

			 