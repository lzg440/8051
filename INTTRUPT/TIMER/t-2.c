	    #include<reg51.h>
	    sbit sq=P2^0;
	    sbit sp1=P2^1;
	    unsigned int i,j;
	    unsigned char z;
	    unsigned char num1[4]={0x06,0x5b,0x4f,0x66};
	    unsigned char num2[4]={0x01,0x02,0x04,0x08};
	    void ISR_t0(void) interrupt 1
	    {
	      TF0=0;
		  TL0=0xff;
		  TH0=0xed;
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
		 TH0=0xed;
		 sq=0;
		 TR0=1;
		 while(1)
		 }
