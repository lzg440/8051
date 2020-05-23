
//==========================================							   
code void msdelay(unsigned char ms);
code void lcdcmd(unsigned char command);
code void lcddata(unsigned char ascii);
code void lcd_int();
//==========================================
code void lcd_int()
{
	 lcdcmd(0x38);
	 msdelay(50);
	 lcdcmd(0x0E);
	 msdelay(50);
	 lcdcmd(0x01);
	 msdelay(50);
	 lcdcmd(0x06);
	 msdelay(50);
	 lcdcmd(0x00);
	 msdelay(50);
}
//==========================================
code void msdelay(unsigned char o)
{
 unsigned int i,j;
	for(i=0;i<o;i++)
	for(j=0;j<75;j++);    
}
//===========================================
code void lcdcmd(unsigned char command)
{
    rs = 0; /* Clear bit P1.5 */
	rw = 0;
    P2 = command;
    en = 1; /* Clear bit P1.4 */
   msdelay(1);
    en = 0; /* Set bit P1.4 */
    
}
//============================================
code void lcddata(unsigned char value)
{
	P2 = value;
	rs =1;
	rw = 0;
	en = 1;
	msdelay(1);
	en = 0;
}
//===========================================================
 void lcd_puts(char *aaa)
  {
    unsigned int i=0;
    for(;aaa[i]!=0;i++)
	 {lcddata(aaa[i]);}
  }
//===========================================================
