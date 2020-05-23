#include <reg51.h>//philips/
#include<stdio.h>

//void uart_delay(unsigned int a)
//{
//	unsigned int i1,j1;
//	for(i1 =0;i1<=a;i1++)
//	{
//		for(j1=0;j1<=1274;j1++);
//	}
//}

void uart_ins()
{
	TMOD = 0x20; 	// use timer 1 8-bit auto reload moad
	TH1 = 0xfd;		// 9600 bord rate
	SCON = 0x50; 	// use 8-bit 1 start bit 1 stop bit
	TR1 = 1;		// start timer 1
}

//void uart_send(unsigned char uart_data)
//{
//	SBUF = uart_data;
//	while(TI == 0);
//	TI = 0;	
//}

char uart_receive()
{
	unsigned char uart_data;
 	while(RI == 0);
	uart_data = SBUF;
	RI = 0;
	return(uart_data);
}

//void uart_sends(unsigned char *string)
//{
//	 while(*string)
//	 {
//	 	uart_send(*string++);
//	 }
//} 
				   
//void uart_conv_send(unsigned int dataconv)
//{
//	unsigned char d,c,data1,data2,data3,d1,d2,d3;
//	d = dataconv;
//	d3 = d%10;
//	c = d/10;
//	d2 = c%10;
//	d1 = c/10;
//	data1 = d1 | 0x30;
//	data2 = d2 | 0x30;		
//	data3 = d3 | 0x30;
//	uart_send(data1);
//	uart_send(data2);
//	uart_send(data3);
//}