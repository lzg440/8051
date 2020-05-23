/*
 * Filename : ds1307.h
 * Hardware : Controller  -> P89V51RD2
 *            XTAL        -> 18.432 MHz
 *            Mode        -> 6 Clock/MC
 * I/O      : SDA         -> P2.7
 *            SCL         -> P2.6
 * Compiler : SDCC            
 * Author   : vasoyanikhil@gmail.com
 * Date		: 23/08/06
 */
	

#define SEC   0x00
#define	MIN   0x01	
#define HOUR  0x02
#define DAY   0x03
#define DATE  0x04
#define MONTH 0x05
#define YEAR  0x06
unsigned char *day[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};


void settime(unsigned char hh, unsigned char mm, unsigned char ss)
{

	write_i2c(0xD0,HOUR,hh);
	write_i2c(0xD0,MIN,mm);
	write_i2c(0xD0,SEC,ss);	
}

void Gettime(unsigned char *hh, unsigned char *mm, unsigned char *ss)
{
	write_i2c(0xD0,HOUR,*hh);
	write_i2c(0xD0,MIN,*mm);
	write_i2c(0xD0,SEC,*ss);	
}

void setdate(unsigned char dd, unsigned char mm, unsigned char yy)
{
	write_i2c(0xD0,DATE,dd);
	write_i2c(0xD0,MONTH,mm);
	write_i2c(0xD0,YEAR,yy);
}

void setday(unsigned char day)
{
	write_i2c(0xD0,DAY,day);
}

void disp_time()
{ 
 char x;
 cmd(0x86);
 x=read_i2c(0xD0,HOUR);
 disp(x);
 dat(':');

 x=read_i2c(0xD0,MIN);
 disp(x);
 dat(':');

 x=read_i2c(0xD0,SEC);
 disp(x);
}


void disp_date()
{ 
 char x;
 cmd(0xC4);
 x=read_i2c(0xD0,DATE);
 disp(x);
 dat('/');

 x=read_i2c(0xD0,MONTH);
 disp(x);
 dat('/');

 x=read_i2c(0xD0,YEAR);
 disp(x);
}

void disp_day()
{ 
 char x;
 cmd(0xCD);
 x=read_i2c(0xD0,DAY);
 display(0,day[x]);
}