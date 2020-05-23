/*
 * Filename : LCD_4BIT.h
 * Hardware : Controller  -> P89V51RD2
 * I/O      : rs         -> P2.0
 *            rw         -> P2.1
 *            e	         -> P2.2
 * Compiler : keil
 * Author   : vasoya nikhil
 * Date		: 16/09/2013
 */





sbit rs=P1^0;
sbit rw=P1^1;
sbit e=P1^2;
sfr lcd=0x90;
#define clear() cmd(0x01)

/*  ###########function declaration########## */
void lcd_delay(itime);
void cmd(char value);
void dat(char value);
void lcd_init();
void display(char row,char str[]);
void disp(char value);
/*   ########################################### */

void lcd_delay(itime)
{
	int i,j;
	for(i=0;i<itime;i++)
	for(j=0;j<1275;j++);
}


void cmd(char value)
{
	 lcd= (lcd & 0x0f)|((value)&0xf0);
	 rs=0;
	 rw=0;
	 e=1;
	 lcd_delay(1);
	 e=0;
	 
	 lcd= (lcd & 0x0f)|((value<<4)&0xf0);
	 rs=0;
	 rw=0;
	 e=1;
	 lcd_delay(1);
	 e=0; 
}



void dat(char value)
{
	 lcd= (lcd & 0x0f)|((value)&0xf0);
	 rs=1;
	 rw=0;
	 e=1;
	 lcd_delay(1);
	 e=0;
	 
	 lcd= (lcd & 0x0f)|((value<<4)&0xf0);
	 rs=1;
	 rw=0;
	 e=1;
	 lcd_delay(1);
	 e=0; 
}

void lcd_init()
{
 cmd(0x33);
 cmd(0x32);
 cmd(0x28);
 cmd(0x0C);
 cmd(0x06);
 cmd(0x01);
}


void display(char row,char str[])
{ char i;
 if(row==1) cmd(0x80);
 else if(row==2) cmd(0xc0);

 for(i=0;str[i]!=0;i++)
 {
  dat(str[i]);
 }

}

void disp(char value)
{
 char d;
 d= ((value>>4) & 0x0f)|0x30;
 dat(d);
 d= ((value) & 0x0f)|0x30;
 dat(d);
}