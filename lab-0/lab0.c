#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h> 
#include <math.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <unistd.h>
// 01011101 10110111 11101011 111101

int main(int argc, char** argv)
{
    //make sure only 2 command line arguments entered
    int parity =0;
	int expCounter = 8;
	int expVal = 0;
	int numCount = 0;
   	
    if( argc < 2)
        {
        printf("error not enough arguments\n");
        return 1;
        }
     else if(argv[1][0] == '-')
     {
     	printf("Original Ascii Decimal Parity\n");
		printf("-------- ----- ------- ------\n");
	    for(int i =2; i < argc; i++)
	    {    
	    	int j;
	    	int m= strlen(argv[i]);
	    	
	    	int keyword[m];
	    	for (j = 0; j < m; j++)
		    {
		   	  	
		    	keyword[j] = argv[i][j] - '0';
		    	printf("%d",keyword[j]);
		    	//j2++;
		    	numCount++;
		    	expCounter--;

				if(expVal > 128) //not sure if works in all cases
				{
					expVal = expVal - 128;
				}		    	
		    	if((int)keyword[j] == 1)
				{
					parity++;
					expVal += pow(2, expCounter);  // need to fix leftmost bit exponent
				}	
		    	
		    }
		   		    	
				if(keyword[j] = ' ')
				{
					
					while(numCount <8)
					{
						printf("0");
						numCount++;
					}
					numCount =0;
					if(expVal == 1 || expVal == 2 || expVal == 3 || expVal == 4 ||
						expVal == 5 || expVal == 6 || expVal == 7 || expVal == 8 ||
						expVal == 9 || expVal == 10 || expVal == 11 || expVal == 12 ||
						expVal == 13 || expVal == 14 || expVal == 15 || expVal == 16||
						expVal == 17 || expVal == 18 || expVal == 19 || expVal == 20 ||
						expVal == 21 || expVal == 22 || expVal == 23 || expVal == 24 ||
						expVal == 25 || expVal == 26 || expVal == 27 || expVal == 28 ||
						expVal == 29 || expVal == 30 || expVal == 31 || expVal == 32||     
						expVal == 127)
					{
						printf("  NULL");
					}
					
					else
					{
						printf("     %c", expVal);
					}

					printf("     %c", expVal);
					printf("     %d", expVal);
					expCounter = 8;
					expVal = 0;
					
					if(parity % 2 == 0)
					{
						printf("   even");
						parity = 0;
					}
					else
					{
						printf("    odd");
						parity =0;
					}

					
				}
		    


			printf("\n");
	    }
     }
     

     else if((argv[1][0] == '1') || (argv[1][0] == '0'))//
     {
        printf("Original Ascii Decimal Parity\n");
		printf("-------- ----- ------- ------\n");
	    for(int i =1; i < argc; i++)
	    {    
	    	int j;
	    	int m= strlen(argv[i]);
	    	
	    	int keyword[m];
	    	for (j = 0; j < m; j++)
		    {
		   	  	
		    	keyword[j] = argv[i][j] - '0';
		    	printf("%d",keyword[j]);
		    	//j2++;
		    	numCount++;
		    	expCounter--;

				if(expVal > 128) //not sure if works in all cases
				{
					expVal = expVal - 128;
				}		    	
		    	if((int)keyword[j] == 1)
				{
					parity++;
					expVal += pow(2, expCounter);  // need to fix leftmost bit exponent
				}	
		    	
		    }
		   		    	
				if(keyword[j] = ' ')
				{
				
					while(numCount <8)
					{
						printf("0");
						numCount++;
					}
					numCount =0;
					if(expVal == 1 || expVal == 2 || expVal == 3 || expVal == 4 ||
						expVal == 5 || expVal == 6 || expVal == 7 || expVal == 8 ||
						expVal == 9 || expVal == 10 || expVal == 11 || expVal == 12 ||
						expVal == 13 || expVal == 14 || expVal == 15 || expVal == 16||
						expVal == 17 || expVal == 18 || expVal == 19 || expVal == 20 ||
						expVal == 21 || expVal == 22 || expVal == 23 || expVal == 24 ||
						expVal == 25 || expVal == 26 || expVal == 27 || expVal == 28 ||
						expVal == 29 || expVal == 30 || expVal == 31 || expVal == 32||     
						expVal == 127)
					{
						printf("  NULL");
					}
					
					else
					{
						printf("     %c", expVal);
					}

					printf("     %d", expVal);
					expCounter = 8;
					expVal = 0;
					
					if(parity % 2 == 0)
					{
						printf("   even");
						parity = 0;
					}
					else
					{
						printf("    odd");
						parity =0;
					}

					//printf("\n");
				}
		    


			printf("\n");
	    }
	     
	}
	else if(isascii(argv[1][0])) // doenst even print test
     {
     	printf("Original Ascii Decimal Parity\n");
		printf("-------- ----- ------- ------\n");
     	char a;
     	int i,j;
     	int fd = open(argv[1], O_RDONLY);
     	char buf[100];
     	//char *inbuf;
     	ssize_t bytes = read(fd,&a,sizeof(buf)-1);
     	//printf("%d\n",bytes ); testing characters inside file size
     	
     	int sz; 
		  char *c = (char *) calloc(100, sizeof(char)); 
		  
		  fd = open(argv[1], O_RDONLY); 
		  if (fd < 0) 
		  	{ 
		  		perror("r1"); exit(1); 
		  	} 
		  
	
     	
		  sz = read(fd, c, (int)bytes); // number of char read
		 
		  
		  for (i = 0; i <= sz; i++)
		  {

		  	printf("%c", c[i]);
		  	numCount++;
			expCounter--;
			int zPrint;


			if(c[i] == '1')
			{
				parity++;
				expVal += pow(2, expCounter);  // need to fix leftmost bit exponent
			}
			if(expVal > 128) //not sure if works in all cases
				{
					expVal = expVal - 128;
				}		
		  	
		  	
		  	

		  	if((c[i] == ' '))
		  	{
		  		while(numCount <=8)
				{
					printf("0");
					numCount++;
				}
				numCount =0;
					
					if(expVal == 1 || expVal == 2 || expVal == 3 || expVal == 4 ||
						expVal == 5 || expVal == 6 || expVal == 7 || expVal == 8 ||
						expVal == 9 || expVal == 10 || expVal == 11 || expVal == 12 ||
						expVal == 13 || expVal == 14 || expVal == 15 || expVal == 16||
						expVal == 17 || expVal == 18 || expVal == 19 || expVal == 20 ||
						expVal == 21 || expVal == 22 || expVal == 23 || expVal == 24 ||
						expVal == 25 || expVal == 26 || expVal == 27 || expVal == 28 ||
						expVal == 29 || expVal == 30 || expVal == 31 || expVal == 32||     
						expVal == 127)
					{
						printf("  NULL");
					}
					
					else
					{
						printf("     %c", expVal);
					}

					printf("     %d", expVal);
					expCounter = 8;
					expVal = 0;
					
					if(parity % 2 == 0)
					{
						printf("   even");
						parity = 0;
					}
					else
					{
						printf("    odd");
						parity =0;
					}




		  		printf("\n");
		  	}
		  	if((c[i] == c[sz]) && (numCount != 8))//
		  	{
		  		while(numCount <=8)
				{
					printf("0");
					numCount++;
				}
				numCount =0;
					
					if(expVal == 1 || expVal == 2 || expVal == 3 || expVal == 4 ||
						expVal == 5 || expVal == 6 || expVal == 7 || expVal == 8 ||
						expVal == 9 || expVal == 10 || expVal == 11 || expVal == 12 ||
						expVal == 13 || expVal == 14 || expVal == 15 || expVal == 16||
						expVal == 17 || expVal == 18 || expVal == 19 || expVal == 20 ||
						expVal == 21 || expVal == 22 || expVal == 23 || expVal == 24 ||
						expVal == 25 || expVal == 26 || expVal == 27 || expVal == 28 ||
						expVal == 29 || expVal == 30 || expVal == 31 || expVal == 32||     
						expVal == 127)
					{
						printf("  NULL");
					}
					
					else
					{
						printf("     %c", expVal);
					}

					printf("     %d", expVal);
					expCounter = 8;
					expVal = 0;
					
					if(parity % 2 == 0)
					{
						printf("   even");
						parity = 0;
					}
					else
					{
						printf("    odd");
						parity =0;
					}




		  		printf("\n");
		  	}

		  
		  }
		  
				printf("\n");
		  
	     
	}
	
	else
	{
		printf("nope");
	}
	
	return 0;
}

