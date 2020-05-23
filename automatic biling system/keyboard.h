
sbit KEYB_DATA=P3^3;

unsigned char r0=8,r1=1,q,k,v,extra_key=0,is_up=0,p=0x80;
unsigned char shift=0,ctrl=0;
bit y=0;
unsigned char F2=0,F12=0,F11=0,F10=0,esc=0,entr=0;
//--------------------------------------------
void keyboard_int()
{
   q=0;k=0;r0=8;r1=1;
   y=0	;
}
//-------------------------------------------- 	
code void keyboard_read()
{
  KEYB_DATA=1;

  if(y==0)
	{y=1;}
  else
   {
	if(r0>0 && r1 > 0)
	{  if(r0>1)
			{	
				if(KEYB_DATA == 1)
				{k=(k | 0x80); k=k >> 1;	r0=r0-1;}
				else
	 			{k= k >> 1;	r0=r0-1;}
			}
			else
				{	  
					if(KEYB_DATA == 1)
					{k=(k | 0x80);}
				 	r0=r0-1;
		 		}
	}
  	else
  	{
		if(r1>0){r1=r1-1;}
   		else
		{
		//---------------------------------------
		if(is_up==0 && extra_key==0)
         {
 		    switch (k)
            {
			  case 0xF0 :        // The up-key identifier
              is_up = 1;
              break;

			  case 0xE0 :        // The extra key identifier
              extra_key=1;
			  break;
			 
              case 0x76 :        // Esc
  		      esc=1;
			  break;
              
			  case 0x07 :        // F12
  		      F12=1;
			  break;

			  case 0x5A :        // ENTER
  		      entr=1;
			  break;

			  case 0x78 :        // F11
  		      F11=1;
			  break;
			  
			  case 0x09 :        // F10
  		      F10=1;
			  break;

			  default:
			  q=k;
			  break;
		    }
         }
		else if(extra_key==1)
        {
		    extra_key=0;
		    switch(k)
		     {  
		       case 0xF0 :        // The up-key identifier
               is_up = 1;
               break;
			   case 0x74 :        // -> _KEY
			   p++;
			   break;
          	   case 0x6B :        // <- _KEY
               p--;
			   break;
			   default:
		       break;
             }
	    }
       else
	    {is_up=0;}
   	     y=0;r0=8;r1=1;k=0;
		}
 	 }
}
}




