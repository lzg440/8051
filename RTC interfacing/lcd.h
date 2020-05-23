#define LCD P1
sbit RS=P3^0; //connect p3.0 to rs pin of lcd
sbit EN=P3^2; //connect p3.2 to en pin of lcd
sbit RW=P3^1; //connect p3.1 to en pin of lcd


void integer_lcd(int);			
void init_lcd(void);			
void cmd_lcd(unsigned char);	
void write_lcd(unsigned char);	
void display_lcd(unsigned char *);	
void delay_ms(unsigned int);

void init_lcd(void)
{                           
	delay_ms(10); //delay 10 milliseconds
	cmd_lcd(0x0e); //lcd on, cursor on
	delay_ms(10);
	cmd_lcd(0x38); //8 bit initialize, 5x7 character font, 16x2 display
	delay_ms(10);
	cmd_lcd(0x06); //right shift cursor automatically after each character is displayed
	delay_ms(10);
	cmd_lcd(0x01); //clear lcd
	delay_ms(10);
	cmd_lcd (0x80);
}

//transmit command or instruction to lcd
void cmd_lcd(unsigned char c)
{
	EN=1;
	RW=0;//set enable pin
	RS=0; //clear register select pin
	LCD=c; //load 8 bit data
	EN=0; //clear enable pin
	delay_ms(2); //delay 2 milliseconds
}

//transmit a character to be displayed on lcd
void write_lcd(unsigned char c)
{
	EN=1; //set enable pin
	RW=0;
	RS=1; //set register select pin
	LCD=c;  //load 8 bit data
	EN=0; //clear enable pin
	delay_ms(2); //delay 2 milliseconds
}
										
//transmit a string to be displayed on lcd

void display_lcd(unsigned char *s)
{
	while(*s)
	write_lcd(*s++);
}

//generates delay in milli seconds
void delay_ms(unsigned int i)
{
unsigned int j;
	while(i-->0)
	{
		for(j=0;j<500;j++)
			{;}
	}
} 
