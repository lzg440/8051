#include<reg51.h>

void delay_ms(unsigned int ms)
{
unsigned int i,j;

for(i=0;i<ms;i++)
for(j=0;j<1275;j++);

}
void main()
{
  //int i;
  while(1)
  {
   
    P1=0Xff;
	delay_ms(2000);
	P1=0x00;
	delay_ms(2000);
  }
}