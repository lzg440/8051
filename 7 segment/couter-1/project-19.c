		  #include<reg51.h>
	      void main()
	     {
	   	  TMOD=0x05;
		  TR0=1; 
		  while(TF0==0)
		  {
		    P1=TL0;
		  }
		  TF0=0;
		}
		 
	  
		

	  
