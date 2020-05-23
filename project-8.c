			 #include<reg51.h>
			 sbit sw1=P1^0;
			 void main()
			 {
			  P1=0xff;
			  P2=0X00;
			  if(sw1==0)
			  {
			    P2=0xff;
			  }
			  else if(sw1==1)
			  {
			     P2=0X00;
			  }
			
			}