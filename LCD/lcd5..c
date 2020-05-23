			 #include<reg51.h>
			 #include"lcd.h"
			 void main()
		{
		   cmd1(0x38);
		   delay(100);
		   cmd1(0x0e);
		   delay(100);
		   cmd1(0x80);
		   delay(100);
		   cmd1(0x01);
		   delay(100);
		   
		   data2("vasoya nikhil");
		   delay(100);
		   cmd1(0xc0);
		   delay(100);
		   data2("5TH EC");
		   delay(100);
		  while(1);
		  {
		  }
		}
		  
		  