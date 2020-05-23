#include<PORT.h>
#include "lcd.h"
#include "keyboard.h"
#include "scancodes.h"
#include "delay.h"				

sbit sda1=P0^0;
sbit scl1=P0^1;

unsigned char tag=0,ent=0,temp=0,temp1=0;

unsigned char bal[4]={'0','0','0','0'};
unsigned char cr[4]={'0','0','0','0'};
unsigned char dr[4]={'0','0','0','0'};

#define l1 0x80
#define l2 0xC0					
//===========EEprom Routines=======================
//-------------------------------------------------
  code void outs(unsigned char o);
  code void out(unsigned char o) ;
  code void stop();
  code unsigned char in();
//==================================================
  code void delay_eep()
	{
 	   unsigned int j;
	   	 for(j=0;j<=90;j++);
	}
//---------------------------------------------------
code void outs(unsigned char o)
{
	unsigned int i;
	unsigned char aa,ll;
	ll=o;
	sda1=1;
	scl1=1;
	delay_eep();
	delay_eep();
	sda1=0;
	delay_eep();
	delay_eep();
	scl1=0;
	for(i=1;i<=8;i++)
	{
		aa=ll & 0x80;
		ll=ll << 1;
		if(aa==0x80)
		{sda1=1;}
		else
		{sda1=0;}
		scl1=1;
		delay_eep();
		delay_eep();
		scl1=0;
	}
	sda1=1;
	delay_eep();
	delay_eep();
	scl1=1;
	delay_eep();
	delay_eep();
	scl1=0;
}
//===============================================
code void out(unsigned char o)
{
	unsigned int i;
	unsigned char aa,ll;
	ll=o;

	for(i=1;i<=8;i++)
	{
	aa=ll & 0x80;
	ll=ll << 1;
	if(aa==0x80)
	{sda1=1;}
	else
	{sda1=0;}
	scl1=1;
	delay_eep();
	delay_eep();
	scl1=0;
	}
	sda1=1;
	delay_eep();
	scl1=1;
	delay_eep();
	delay_eep();
	scl1=0;
}
//=======================================================  
  code void stop()
  {
  sda1=0;
  delay_eep();
  scl1=1;
  delay_eep();
  delay_eep();
  sda1=1;
  }
//======================================================
code unsigned char in()
 {  
 	unsigned int i;
	unsigned char ll;
	ll=0x00;
	sda1=1;
	for(i=1;i<=8;i++)
	{
	ll=ll << 1;
	scl1=0;
	delay_eep();
	delay_eep();
	scl1=1;

 	CY=sda1;
	if(CY==1)
	{ll=ll |0x01;}
	}
	scl1=0;
	return ll;
 }
//===============================================================
 code void eeprom_write(unsigned char eeadd,unsigned char eedat)
 {	outs(0xa0);
	out(eeadd);
	out(eedat);
	stop();
 }
//===============================================================
 code unsigned char eeprom_read(unsigned char eeadd)
 {
 	unsigned char ww;	
 	outs(0xa0);
	out(eeadd);
	outs(0xa1);
	ww=in();
	stop();
	return ww;
 }
//===============================================================
 code void codpag();
//==============================================
void interrup0 (void) interrupt 0 
 { 
   keyboard_read();
 }
//==============================================
void main()
 {
    keyboard_int();
    lcd_int();       //LCD

    IE=0x83;
    IT0=1 ;
  
  lcdcmd(l1);
  lcd_puts("   :WELCOME:    ");

  lcdcmd(l2);
  lcd_puts("Final Year Proj.");
  
  DelayMs(2000);
  lcdcmd(l2);
  lcd_puts("By.:KIRAN...     ");
  DelayMs(2000);
  lcdcmd(l2);
  lcd_puts("By.:JIGNESH..    ");
  DelayMs(2000);
  lcdcmd(l2);
  lcd_puts("By.:KAUSHIK..     ");
  
  
  DelayMs(2000);
  lcdcmd(l1);
  lcd_puts("   :WELCOME:    ");

  lcdcmd(l2);
  lcd_puts(" LDRP-ITR 2013/14    ");
	
	 eeprom_write(0x00,'a');
	 delay_eep();
     eeprom_write(0x01,'0');   
     delay_eep();
     eeprom_write(0x02,'0');   
     delay_eep();
     eeprom_write(0x03,'0');   
     delay_eep();
  	 eeprom_write(0x04,'0');   
     delay_eep();
  
//----------------------------------------------------------- 
 while(1)
   {
     //===============================================================
	 	 if(esc==1)
		 { entr=0;ent=0;F12=0;F11=0;F10=0;esc=0;}
	 //===============================================================
   		 if(F11==1)
		 { ent=1;
		  lcdcmd(l1);
          lcd_puts("Name: Mr. ABC       ");
  		  lcdcmd(l2);
          lcd_puts("Credit Bal:        ");
		  	p=0xCB;
		    while(!entr)
			{
			  	if(q!=0)
	       	     {if(p>0xCE){p=0xCE;}
				  if(p<0xCB){p=0xCB;}
				   lcdcmd(p);
                   codpag();
		           lcddata(v);
				   cr[p-0xcb]=(v-0x30);
		           q=0;p++;
		         }
			}
		    temp =eeprom_read(0x01);
		    bal[0] = temp - 0x30;
			temp =eeprom_read(0x02);
		    bal[1] = temp - 0x30;
			temp =eeprom_read(0x03);
		    bal[2] = temp - 0x30;
			temp =eeprom_read(0x04);
		    bal[3] = temp - 0x30;
			
			bal[0] = (bal[0]+cr[0]);
			bal[1] = (bal[1]+cr[1]);
			bal[2] = (bal[2]+cr[2]);
			bal[3] = (bal[3]+cr[3]);
			
			bal[0] = (bal[0]+ 0x30);
			bal[1] = (bal[1]+ 0x30);						   
			bal[2] = (bal[2]+ 0x30);
			bal[3] = (bal[3]+ 0x30);
			
			  eeprom_write(0x01,bal[0]);   
              delay_eep();
              eeprom_write(0x02,bal[1]);   
              delay_eep();
              eeprom_write(0x03,bal[2]);   
              delay_eep();
  	          eeprom_write(0x04,bal[3]);   
              delay_eep();
			  entr=0;F11=0;
		  }
      //================================================================
		 if(F10==1)
		 { ent=1;
		  lcdcmd(l1);
          lcd_puts("Name: Mr. ABC       ");
  		  lcdcmd(l2);
          lcd_puts("Debit Bal :        ");
		  	p=0xCB;
		    while(!entr)
			{
			  	if(q!=0)
	       	     {if(p>0xCE){p=0xCE;}
				  if(p<0xCB){p=0xCB;}
				   lcdcmd(p);
                   codpag();
		           lcddata(v);
				   dr[p-0xcb]=(v-0x30);
		           q=0;p++;
		         }
			}
		    temp =eeprom_read(0x01);
		    bal[0] = temp - 0x30;
			temp =eeprom_read(0x02);
		    bal[1] = temp - 0x30;
			temp =eeprom_read(0x03);
		    bal[2] = temp - 0x30;
			temp =eeprom_read(0x04);
		    bal[3] = temp - 0x30;
			
			bal[0] = (bal[0]-dr[0]);
			bal[1] = (bal[1]-dr[1]);
			bal[2] = (bal[2]-dr[2]);
			bal[3] = (bal[3]-dr[3]);
			
			bal[0] = (bal[0]+ 0x30);
			bal[1] = (bal[1]+ 0x30);						   
			bal[2] = (bal[2]+ 0x30);
			bal[3] = (bal[3]+ 0x30);
			
			  eeprom_write(0x01,bal[0]);   
              delay_eep();
              eeprom_write(0x02,bal[1]);   
              delay_eep();
              eeprom_write(0x03,bal[2]);   
              delay_eep();
  	          eeprom_write(0x04,bal[3]);   
              delay_eep();
			  entr=0;F10=0;
		  
		  }
	  //=================================================================
		 if(F12==1)
		 {lcdcmd(l1);
          lcd_puts("Name: Mr. ABC       ");
  		  lcdcmd(l2);
          lcd_puts("BALANCE :          ");
		   
		   bal[3] =eeprom_read(0x01);
		   lcdcmd(l2+10);
		   lcddata(bal[3]);
		   bal[2] =eeprom_read(0x02);
		   lcdcmd(l2+11);
		   lcddata(bal[2]);
		   bal[1] =eeprom_read(0x03);
		   lcdcmd(l2+12);
		   lcddata(bal[1]);
		   bal[0] =eeprom_read(0x04);
		   lcdcmd(l2+13);
		   lcddata(bal[0]);
		   DelayMs(1000);
		 }
 	 //===============================================================
 	 	tag =eeprom_read(0x00);
	    if(tag=='a' && ent==0)
	     {
		  lcdcmd(l2);
          lcd_puts(" TAG Dectd...!!!   ");
		  DelayMs(1000);
  		  lcdcmd(l1);
          lcd_puts("Hello...!!!         ");
          lcdcmd(l2);
          lcd_puts("Name: Mr. ABC       ");
  		  DelayMs(1000);
         }
		if(tag!='a' && ent==0)
		 { 
		   lcdcmd(l1);
           lcd_puts("   :WELCOME:       ");
		   lcdcmd(l2);
           lcd_puts(" LDRP-ITR 2013/14    ");
  		 }	
   }
//------------------------------------------------------------
}
//============================================================
code void codpag()
  {
	  unsigned int aa;
	  for(aa = 0; ((unshifted[aa][0]!=q)&&(aa<=36)); aa++);
                   if (unshifted[aa][0] == q)
			 {v=unshifted[aa][1];}
  }
//============================================================