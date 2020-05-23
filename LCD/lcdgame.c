	  #include<reg51.h>
	  #include"lcd3.h"
	  void main()
	  {
	       lcdcmd(0x38);
   		   //delay(100);
		   lcdcmd(0x0e);
		   //delay(100);
		   lcdcmd(0x01);
		   //delay(100);
		   lcdcmd(0x64);
   		   //delay(100);
		   data1(0x00);
		  // delay(100);

		   data1(0x1f);
		   //delay(100);
		   data1(0x0f);
		   //delay(100);
		   data1(0x15);
		   //delay(100);
		   data1(0x06);
		   //delay(100);
		   data1(0x06);
		   //delay(100);
		   data1(0x06);
		   //delay(100);
		   data1(0x00);
		   //delay(100);
		   lcdcmd(0x80);
		   //delay(100);
		   data1(0);
		   //delay(100);
		  while(1)
		  {
		  }
	   }