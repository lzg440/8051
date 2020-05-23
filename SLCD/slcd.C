// This is the program to display something in LCD. 
#include <REG52.H>									//Header file
#include<string.h>
sbit RS=P3^7;										//RS pin of LCD is connected with 8th pin of Port 3
sbit EN=P3^6;										//EN pin of LCD is connected with 7th pin of Port 3
#define LCD P2										//Lcd is connected with PORT 2
void delay(unsigned int x)							// Delay program
{
unsigned int i,j;
for(i=0;i<=x;i++)
for(j=0;j<=100;j++);
}
void cmd(unsigned char x)						   //Command function for Lcd to send commands from Microcontroller
{												   // RS pin of Lcd should be low
LCD=x;
RS=0;
EN=1;
delay(10);
EN=0;
}
void dat(unsigned char x)						// Data fuction for lcd to send data from Microcontroller
{												//RS pin of Lcd should be high
LCD=x;
RS=1;
EN=1;
delay(10);
EN=0;
}												//This is the function to send the string to LCD
void message(unsigned char *p)
{
unsigned char c,m;
c=strlen(p);
for(m=0;m<=c;m++)
{
dat(p[m]);
}
}
void main()										//Make P2 and P3 ports are outputs
{
P2=0x00;										
P3=0x00;										 //Command for choosing 16x2 Lcd
cmd(0x38);										//Command for choosing Right shift
cmd(0x06);										//Command for display without cursor(Means cursor OFF)
cmd(0x0c);	
cmd(0x8F);									
message("*Welcome To Circuit City*");	//Message to display to LCD
cmd(0xCF);					      						  //Command to goto next line. Choosing second coloumn of lcd
message("----------------------------");
while(1)										//infinite loop
{
cmd(0x1C);										//Command to scroll display 
delay(200);
}
}