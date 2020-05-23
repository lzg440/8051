sbit SCK=P2^4; //serial clock pin
sbit SDA=P2^5; //serial data pin

#define SCKHIGH  SCK=1;
#define SCKLOW   SCK=0;
#define SDAHIGH  SDA=1;
#define SDALOW   SDA=0;

void _nop_(void);
#define delay_us _nop_(); //generates 1 microsecond
void delay_ms(itime);
void start(void);
void stop(void);
void send_byte(unsigned char);
unsigned char receive_byte(unsigned char);
void write_i2c(unsigned char,unsigned char,unsigned char);
unsigned char read_i2c(unsigned char,unsigned char);

unsigned char slave_ack;
unsigned int num;


void delay_ms(itime)
{
	int i,j;
	for(i=0;i<itime;i++)
	for(j=0;j<1275;j++);
}


//starts i2c, if both SCK & SDA are idle
void start(void)
{ 
           if(SCK==0) //check SCK. if SCK busy, return else SCK idle
                        return;
            if(SDA==0) //check SDA. if SDA busy, return else SDA idle
                        return;
	SDALOW //data low
	delay_us
	SCKLOW  //clock low   
	delay_us
}          
//stops i2c, releasing the bus
void stop(void)
{        
	SDALOW //data low
	SCKHIGH //clock high
	delay_us
	SDAHIGH //data high
	delay_us
}

//transmits one byte of data to i2c bus

void send_byte(unsigned char c)
{
	unsigned mask=0x80;
		do  //transmits 8 bits
		{
			if(c&mask) //set data line accordingly(0 or 1)
				SDAHIGH //data high
		
			else
				SDALOW //data low
			
			SCKHIGH   //clock high
			delay_us
			SCKLOW   //clock low
			
			delay_us
			mask/=2;  //shift mask	   hex 80/2=40 /2=20 /2=10 /2=8 /2=4 /2=2 /2 /2=1
		}while(mask>0);
	
	SDAHIGH  //release data line for acknowledge
	SCKHIGH  //send clock for acknowledge
	delay_us
	slave_ack=SDA; //read data pin for acknowledge
	SCKLOW  //clock low
	delay_us
}      

//receives one byte of data from i2c bus
unsigned char receive_byte(unsigned char master_ack)
{
unsigned char c=0,mask=0x80;
           do  //receive 8 bits
           {
				SCKHIGH //clock high
				delay_us
				if(SDA==1) //read data
				c|=mask;  //store data
				SCKLOW  //clock low
				delay_us
				mask/=2; //shift mask
			}while(mask>0);

            if(master_ack==1)
				SDAHIGH //don't acknowledge		
			else
				SDALOW //acknowledge
				SCKHIGH //clock high
				delay_us
				SCKLOW //clock low
				delay_us
				SDAHIGH //data high
				return c;
}

//writes one byte of data(c) to slave device(device_id) at given address(location)

void write_i2c(unsigned char device_id,unsigned char location,unsigned char c)
{
            do
            {
                        start();      //starts i2c bus
                        send_byte(device_id); //select slave device
                        if(slave_ack==1)  //if acknowledge not received, stop i2c bus
                        stop();
			}while(slave_ack==1); //loop until acknowledge is received
	
	send_byte(location); //send address location
	send_byte(c); 			//send data to i2c bus
	stop(); 				//stop i2c bus
	delay_ms(4);
}      

//reads one byte of data(c) from slave device(device_id) at given address(location)

unsigned char read_i2c(unsigned char device_id,unsigned char location)
{
unsigned char c;
            do
            {
                        start();  				 //starts i2c bus  
                        send_byte(device_id); 	//select slave device
                        if(slave_ack==1) 		//if acknowledge not received, stop i2c bus
                        stop();
            }while(slave_ack==1); 				//loop until acknowledge is received

	send_byte(location); 			 //send address location     
	stop(); 						//stop i2c bus
	start(); 						//starts i2c bus  
	send_byte(device_id+1); 			//select slave device in read mode
	c=receive_byte(1); 					//receive data from i2c bus
	stop(); //stop i2c bus
	return c;
}  