		  #include<reg51.h>
          #include"4bit.h"
		  void main()
          {		  
		
		   lcdcmd(0x28);
		   delay(50);
		   lcdcmd(0x38);   		 
		   delay(50);		  
		   lcdcmd(0x0e);		   
		   delay(50);		   
		   lcdcmd(0x01);
		   delay(50);
		  
		
		   lcdcmd(0x80);
		   
		   data2("VASOYA NIKHIL");
		   delay(50);
		   lcdcmd(0xc0);
	     
		   data2("5TH EC");
		   delay(50);
		   while(1);
		   {
		   }

       }