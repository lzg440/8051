// interfacing ds1307 with AT89C51

#include <reg51.h>
#include <lcd_4bit.h>
#include <i2c.h>
#include <ds1307.h>
unsigned char clock[]={0x00,0x47,0x11,0x02,0x23,0x07,0x13};
unsigned char add=0,x;

void main()
{
  // unsigned int i,j,k;
   //settime(0x10,0x00,0x00);
   setdate(0x28,0x10,0x13);
   setday(0x02);   // 0x00-SUN, 0x01-MON , 0x02-TUE


	lcd_init();
	display(1,"WELCOME TO");
	display(2,"MY PROJECT");
	lcd_delay(100);
	clear();
	display(1,"RTC INTERFACING");
	display(2,"   USING I2C   ");
	lcd_delay(100);
	clear();
	display(1,"TIME: ");
	display(2,"DAY: ");

	while(1)
	{
		disp_time();
		disp_date();
		disp_day();
	}

}              