#include<reg51.h>

sfr data1=0xA0;

sbit rs=P3^7; 
sbit rw=P3^5;
sbit e=P3^6;
 
void delay(unsigned char time)
{
    unsigned int i,j;
	for(j=0;j<time;j++)
	{
	   for(i=0;i<1275;i++);
	}
} 

void  cmd(unsigned char value)
{
      data1=value;
      rs=0;
	  rw=0;
	  e=1;
	  delay(1);
	  e=0;
	
}

void  dat(unsigned char value)
{
      data1=value;
      rs=1;
	  rw=0;
	  e=1;
	  delay(1);
	  e=0;
}

void data2(unsigned char *lcdstr)
{
   while(*lcdstr)
   {
		 dat(*lcdstr++);
   }
}		
void lcdrotade(unsigned char k,unsigned char *lcdstr)
{  
    unsigned char j;
	data2(lcdstr);
	if(k==1)
	{
	    for(j=0;j<16;j++)
		{
		     cmd(0x1c);
			 delay(250);
		}
	}
	else if(k==0)
	{
	    for(j=0;j<16;j++)
		{
		    cmd(0x18);
			delay(250);
		}
	}
	else;
}
void main()
{ 
        data1=0x00;
		P3=0x00;
         while(1)
		{
		 cmd(0x38);
		 //delay(250);
         cmd(0x06);
		 //delay(250);
		 cmd(0x0c);
		 //delay(250);
		 cmd(0x8f);
		 data2("vasoya nikhil");
		 cmd(0xcf);
		 data2("7th ec 23");
		 
	     cmd(0x1c);
		 //delay(25);
    
	  //cmd(0x1c);
	  //delay(250);
	    }

}