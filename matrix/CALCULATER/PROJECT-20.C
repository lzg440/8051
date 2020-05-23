		 #include<reg51.h>
		 unsigned char n[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0xff,0x6f};
		 unsigned char m[]={0xf7,0xfb,0xfd,0xfe};
		 unsigned char c,j,k[3],x,y,i,l;
		 void add()
		 {	 
		     x=1;
		 }
		 void sub()
		 {	
		     x=2;	
		 }
		 void eq()
		 {
		 //	P0=n[1];
		    if(x==1)
		     {
		      c=k[0]+k[1];
		      P0=n[c];
			  i=0;
		      x=0;
		   	 }
		   else if(x==2)
		   {    
		        c=k[0]-k[1];
		        P0=n[c];
			    y=0;
		   }

		 }
		 void main()
		 {
		   i=0;
		   while(1)
		   {
		      P3=0x01;
			  for(j=0;j<4;j++)
			  {
			    P1=m[j];
			    if(P1==0x77)
			    {
			       while(P1==0x77);
				   P0=n[0];
				   k[i]=0;	
				   i++;
			    }
			   else if(P1==0x7b)
			   {
			        while(P1==0x7b);
			       	P0=n[1];
				    k[i]=1;
					i++;		
			   }
			   else if(P1==0x7d)
			   {
			        while(P1==0x7d);
			        P0=n[2];
					k[i]=2;
					i++;		
						
			   }
			   else if(P1==0x7e)
			   {
			        while(P1==0x7e);
			       	P0=n[3];
				    k[i]=3;
					i++;		
			   }	
			   else if(P1==0xb7)
			   {
			        while(P1==0xb7);
			        P0=n[4];
				    k[i]=4;
					i++;		  
               }
			   else if(P1==0xbb)
			   {
			        while(P1==0xbb);
			       	P0=n[5];
				    k[i]=5;
					i++;	
			   }
			   else if(P1==0xbd)
			   {
			         while(P1==0xbd);
			         P0=n[6];
					 k[i]=6;
					 i++;	
		       }
			   else if(P1==0xbe)
			   {
			         while(P1==0xbe);   
			         P0=n[7];
					 k[i]=7;
					 i++;		
			   }
			    else if(P1==0xd7)
			   {
			        while(P1==0xd7);
			        P0=n[8];
				    k[i]=8;
					i++;	  
			   }
			    else if(P1==0xdb)
			   {
			       while(P1==0xdb);
			       P0=n[9];
				   k[i]=9;
				   i++;	 
			   }
			    else if(P1==0xdd)
			   {
			       while(P1==0xdd);
			       add();   
			   }
			    else if(P1==0xde)
			   {
			        while(P1==0xde);
			        sub();
			   }
			   else if(P1==0xe7)
			   {
			        while(P1==0xe7);
			        eq();
			   }
			   
		     }
	     }
      }						
