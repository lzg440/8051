	  #include<reg51.h>
	  sbit sq=P2^0;
	  sbit sp1=P2^1;
	  unsigned int i;
	  void ISR_t0(void) interrupt 1
	  {
	      TF0=0;
		  TL0=0x34;
		  TH0=0xfe;
		  sq=~sq;
	  }
	  void main()
	  {
	     sq=1;
		 TMOD=0x01;
		 IE=0x82;
		 TL0=0x34;
		 TH0=0xfe;
		 sq=0;
		 TR0=1;
		 while(1)
		 {
		   sp1=1;
		   for(i=1;i<100;i++);
		   sp1=0;
		   for(i=1;i<100;i++);
		 }
	   }


	  
