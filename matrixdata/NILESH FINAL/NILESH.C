#include<reg51.h>

//sbit pin1=P2^0;
//sbit pin2=P2^1;


void uart_ins()
{
	TMOD = 0x20; 	// use timer 1 8-bit auto reload moad
	TH1 = 0xfd;		// 9600 bord rate
	SCON = 0x50; 	// use 8-bit 1 start bit 1 stop bit
	TR1 = 1;		// start timer 1
}

void uart_send(unsigned char uart_data)
{
	SBUF = uart_data;
	while(TI == 0);
	TI = 0;	
}  

char uart_receive()
{
	unsigned char uart_data;
 	while(RI == 0);
	uart_data = SBUF;
	RI = 0;
	return(uart_data);
}

void uart_sends(unsigned char *string)
{
	 while(*string)
	 {
	 	uart_send(*string++);
	 }
} 					

void name(unsigned char n)
{
	char a[]={0xfe,0xfd,0xfb,0xf7,0xef},b[5];
	//	char a[]={0x01,0x02,0x04,0x08,0x10},b[5];
 	int i,j,k;
		
//	while(*n!='\0')
//	{

	switch(n)
	{
	case 'A':
	{
		b[0]=0x10;
		b[1]=0x76;
		b[2]=0x76;
		b[3]=0x76 ;
		b[4]=0x01;
		break; 
		
	}
	case 'B':
	{
		b[0]=0x00;
		b[1]=0x36;
		b[2]=0x36;
		b[3]=0x36 ;
		b[4]=0x41;
		break; 
		
	}
	case 'C':
	{
		b[0]=0x00;
		b[1]=0x3e;
		b[2]=0x3e;
		b[3]=0x3e ;
		b[4]=0x3e;
		break; 
		
	}
	case 'D':
	{
		b[0]=0x00;
		b[1]=0x3e;
		b[2]=0x3e;
		b[3]=0x3e ;
		b[4]=0x41;
		break; 
		
	}
	case 'E':
	{
		b[0]=0x00;
		b[1]=0x36;
		b[2]=0x36;
		b[3]=0x36 ;
		b[4]=0x36;
		break; 
		
	}
	case 'F':
	{
		b[0]=0x00;
		b[1]=0x76;
		b[2]=0x76;
		b[3]=0x76 ;
		b[4]=0x76;
		break; 
		
	}
	case 'G':
	{
		b[0]=0x40;
		b[1]=0x5a;
		b[2]=0x5a;
		b[3]=0x42 ;
		b[4]=0x7b;
		break; 
		
	}
	case 'H':
	{
		b[0]=0x00;
		b[1]=0x77;
		b[2]=0x77;
		b[3]=0x77 ;
		b[4]=0x00;
		break; 
		
	}
	case 'I':
	{
		b[0]=0x3e;
		b[1]=0x3e;
		b[2]=0x00;
		b[3]=0x3e ;
		b[4]=0x3e;
		break; 
		
	}
	case 'J':
	{
		b[0]=0x3e;
		b[1]=0x3e;
		b[2]=0x00;
		b[3]=0x7e ;
		b[4]=0x7e;
		break; 
		
	}
	case 'K':
	{
		b[0]=0x00;
		b[1]=0x77;
		b[2]=0x6b;
		b[3]=0x5d ;
		b[4]=0x3e;
		break; 
		
	}

	case 'L':
	{
	   	b[0]=0x00;
		b[1]=0x3f;
		b[2]=0x3f;
		b[3]=0x3f ;
		b[4]=0x3f; 
		break;
	}
		case 'M':
	{
	 	b[0]=0x00;
		b[1]=0x7d;
		b[2]=0x7b;
		b[3]=0x7d ;
		b[4]=0x00;
		break; 
			
	}
		case 'N':
	{
	 	b[0]=0x00;
		b[1]=0x7d;
		b[2]=0xe3;
		b[3]=0x5f ;
		b[4]=0x00;
		break; 
			
	}
		case 'O':
	{
	 	b[0]=0x00;
		b[1]=0x3e;
		b[2]=0x3e;
		b[3]=0x3e ;
		b[4]=0x00;
		break; 
			
	}
		case 'P':
	{
	 	b[0]=0x80;
		b[1]=0xf6;
		b[2]=0xf6;
		b[3]=0xf6 ;
		b[4]=0xf9;
		break; 
			
	}
		case 'Q':
	{
	 	b[0]=0xf1;
		b[1]=0xee;
		b[2]=0xe6;
		b[3]=0x86 ;
		b[4]=0xb1;
		break; 
			
	}
		case 'R':
	{
	 	b[0]=0x00;
		b[1]=0xee;
		b[2]=0xce;
		b[3]=0xbe ;
		b[4]=0x39;
		break; 
			
	}
		case 'S':
	{
	 	b[0]=0x30;
		b[1]=0x36;
		b[2]=0x36;
		b[3]=0x36 ;
		b[4]=0x06;
		break; 
			
	}
		case 'T':
	{
	 	b[0]=0xfe;
		b[1]=0xfe;
		b[2]=0x00;
		b[3]=0xfe ;
		b[4]=0xfe;
		break; 
			
	}
		case 'U':
	{
	 	b[0]=0xc0;
		b[1]=0x3f;
		b[2]=0x3f;
		b[3]=0x3f ;
		b[4]=0xc0;
		break; 
			
	}
		case 'V':
	{
	 	b[0]=0x60;
		b[1]=0x5f;
		b[2]=0x3f;
		b[3]=0x5f ;
		b[4]=0x60;
		break; 
			
	}
	case 'W':
	{
	 	b[0]=0x00;
		b[1]=0x5f;
		b[2]=0x6f;
		b[3]=0x5f ;
		b[4]=0x00;
		break; 
			
	}
		case 'X':
	{
	 	b[0]=0x1c;
		b[1]=0x6b;
		b[2]=0x77;
		b[3]=0x6b ;
		b[4]=0x1c;
		break; 
			
	}
		case 'Y':
	{
	 	b[0]=0x7e;
		b[1]=0x7d;
		b[2]=0x03;
		b[3]=0x7d ;
		b[4]=0x7e;
		break; 
			
	}
		case 'z':
	{
	 	b[0]=0x1e;
		b[1]=0x2e;
		b[2]=0x36;
		b[3]=0x3a ;
		b[4]=0x3c;
		break; 
			
	}
	case ' ':
	{
		b[0]=0x00;
		b[1]=0x00;
		b[2]=0x00;
		b[3]=0x00 ;
		b[4]=0x00; 

	}	 
	}
		for(i=0;i<5;i++)
			{
				for(j=0;j<5;j++)
			{
				P0=b[j];
				P1=a[j];
				
				for(k=0;k<5;k++);
				P0=0xff	;
				P1=0x00;
			
         	}
	   }
	   n++ ;
}
//}
				   /*
void display(unsigned char str_dis[])
{
 	unsigned char k;
	for(k=str_dis[k];k>0;k--)
		{
		 	pin1=1;
			pin2=1;
			name(str_dis[k]) ;
			pin1=0;
			pin2=1;
			name(str_dis[k]) ;
		   	pin1=1;
			pin2=0;
			name(str_dis[k]) ;
			pin1=0;
			pin2=0;
			name(str_dis[k]) ;
		}
}				  */


void main()
{	
	unsigned char d[10],i,a ;
	P0=0xff;
	P1=0x00;
	P2=0X00;
	uart_ins();
	while(1)
	{
	  
	  d[i]=uart_receive();
	  i++;
	  if(i>=9)
	  {	 while(1)
	  	{
  		 for(i=0 ; i<5 ;i++)
  		 {	 P2=i;
  		 a=d[i];
		// display(s[i]);
	 name(a);
			
		  }
		 }
	  }
 	}
	
}