		#include<reg51.h>
        void main()
		{
		P1=0xff;
		P2=0x00;
		switch(P1)
		{
		 case 0x01:return(0x80);
		 case 0x02:return(0x40);
		 case 0x03:return(0x20);
		 case 0x04:return(0x10);
		 case 0x05:return(0x08);
		 case 0x06:return(0x04);
		 case 0x07:return(0x02);
		 case 0x08:return(0x01);
		 default:return(0xff);
		 }
		 }

		  