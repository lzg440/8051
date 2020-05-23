		    #include<reg51.h>
		    unsigned char num[11]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0xff,0x6f,0x3f};
			//unsigned char num1[4]={0x01,0x03,0x07,0x0f};
	   	    unsigned char z,x,y,w,i;
			unsigned int j;
			void main()
			{
			  while(1)
			  {	 
			     for(w=1;w<11;w++)
				 {   
				      for(x=1;x<11;x++)
					  {
					     for(y=1;y<11;y++)
						 {
				             for(z=0;z<11;z++)
				             {	   
							       P3=0x01;
					               for(j=1;j<20000;j++);
				                   P0=num[z];
							 }
							 P3=0x02;
							 P0=num[y];
						 }
						 P3=0x04;
						 P0=num[x];
				      }
					  P3=0x08;
					  P0=num[w];
		      	 }
			  }
			}
		

			    