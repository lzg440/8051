 /*


rs = P3.2 
e  = P3.3
d4 t0 d7 = P2.4 to P2.7

*/

#ifndef _leddatas_H
#define _leddatas_H

#include <reg51.h>
 
sbit lcd_en = P3^0;
sbit lcd_rs = P3^2; 
void lcd_delay(unsigned char ms)
{
	unsigned char n;
	unsigned int i;
	for (n=0; n<ms; n++)
	{
		for (i=0; i<1272; i++);
	}
}

void lcd_enable()
{
    lcd_en = 0; 
    lcd_delay(1);
    lcd_en = 1; 
}

void lcd_command(unsigned char command)
{
    lcd_rs = 0; 
    P2 = (P2 & 0x0f)|(((command>>4) & 0x0F)<<4);
    lcd_enable();
    P2 = (P2 & 0x0f)|((command & 0x0F)<<4);
    lcd_enable();
    lcd_delay(1);
}

void lcdinit()
{
    lcd_en = 1; 
    lcd_rs = 0;  
    lcd_command(0x33);
    lcd_command(0x32);
    lcd_command(0x28);
    lcd_command(0x0C);
    lcd_command(0x06);
    lcd_command(0x01); 
    lcd_delay(25);
}

void lcd_datac(unsigned char ascii)
{
    lcd_rs = 1; 
    P2 = (P2 & 0x0f)|(((ascii>>4) & 0x0F)<<4);
    lcd_enable();
    P2 = (P2 & 0x0f)|((ascii & 0x0F)<<4);
    lcd_enable();
    lcd_delay(1);
}

void lcdrow(unsigned char no)
{
	if (no == 1)
	{	
		lcd_command(0x80);
	}
	if (no ==2)
	{
		lcd_command(0xC0);
	}
}

void lcddatas (unsigned char row,unsigned char *lcdstring)
{
	lcdrow(row);
	while (*lcdstring) 
	{
		lcd_datac(*lcdstring++);
	}
}

void lcdblink(unsigned char no,unsigned char *lcdstring)
{
	unsigned char j;
	for(j=0;j<no;j++)
	{
	lcd_command(0x01);
	lcd_delay(50);
	lcddatas(1,lcdstring);
	lcd_delay(50);
	}
}

void lcdrotade(unsigned char no,unsigned char dir,unsigned char *lcdstring)
{
	unsigned char i;
	lcddatas(no,lcdstring);
	if (dir == 'l')
	{
		for (i=0;i<16;i++)
		{
		lcd_delay(100);
		lcd_command(0x18);
		}
	}
	if (dir == 'r')
	{
		for (i=0;i<16;i++)
		{
		lcd_delay(100);
		lcd_command(0x1C);
		}
	}	
}
