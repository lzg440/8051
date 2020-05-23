#included<reg51.h>
#include"lcd3.h"


void main()
{		   lcdcmd(0x38);
   		   delay(100);
		   lcdcmd(0x0e);
		   delay(100);
		   lcdcmd(0x80);
		   delay(100);
		   lcdcmd(0x01);
		   delay(100);
		   data2("VASOYA NIKHIL");
		   delay(100);
		   lcdcmd(0xc0);
		   delay(100);
		   data2("5TH EC");
		   delay(100);
		  while(1);
		  {
		  }

}
