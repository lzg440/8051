	  #include<reg51.h>
	  sbit sq1=P2^2;
	  unsigned int i;
	  bit sq=0;
	  void ISR_t0(void) interrupt 0
	  {
          sq=~sq;
		  for(i=1;i<10000;i++);
		  TR0=sq;
	  }
	  void ISR_t1(void) interrupt 1
	  {
	      TF0=0;
		  TL0=0x34;
		  TH0=0xfe;
		  TR0=sq;
		  for(i=1;i<10000;i++);
		  sq1=~sq1;
	  }
	  void main()
	  {
	     
		 TMOD=0x01;
		 IE=0x83;
		 TL0=0x34;
		 TH0=0xfe;
		 TR0=1;
		 while(1);
	  }


	  
