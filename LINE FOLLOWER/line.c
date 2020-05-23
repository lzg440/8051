#include<avr/io.h>


void main(void)
{
	unsigned int k, h;
	DDRA=0x00;
	DDRD=0XFF;
	PORTD=0XFF;
	while (1)
	{
		k =PINA;
h=k & 0xFF;
switch (h)
{
case 0x01://if I/P is 0x
{
PORTD=0x02;//O/P 0x89 ie Forward
break;
}

case 0x02://if I/P is 0x
{
PORTD=0x08;                     
break;
}
case 0x03://if I/P is 0x
{
PORTD=0x0A;//O/P 0x89 ie Forward
break;
}

		
	

}

}
}
