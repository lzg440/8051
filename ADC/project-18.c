		  #include<reg51.h>
		  #include"lcd4bit.h"
		  sbit rd=P3^3;
          sbit wr=P3^4;
		  sbit intr=P3^5;
		  int adc_0804()
          {
            int a;
            rd=1;
            wr=0;
            lcd_delay(2);
            wr=1;
            while(intr==1);
            rd=0;
            lcd_delay(2);
            a=P1;
			intr=1;
			return(a);
          }
           void main()
		   {
		    unsigned int f,b,c,d,e;
            lcdinit();
			while(1)
		    {
			e=adc_0804();
			f=P1%10;
            b=P1/10;
            c=b%10;
			b=b/10;
			d=b;
            d=d+48;
			lcd_datac(d);
			lcd_delay(2);
            c=c+48;
			lcd_datac(c);
			lcd_delay(2);
            f=f+48;
			lcd_datac(f);
			lcd_delay(2);
			lcd_delay(10);
			lcd_delay(1000);
			lcd_command(0x01);
			}
		   }