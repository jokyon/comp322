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
					/*
				if(expVal > 128) //not sure if works in all cases
				{
					expVal = expVal - 128;
				}
					*/
					while(numCount <8)
					{
						printf("0");
						numCount++;
					}
					numCount =0;

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

					//printf("\n");
				}
		    


			printf("\n");
	    }
     }
     

     else if(argc > 2)//
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
					/*
				if(expVal > 128) //not sure if works in all cases
				{
					expVal = expVal - 128;
				}
					*/
					while(numCount <8)
					{
						printf("0");
						numCount++;
					}
					numCount =0;

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

					//printf("\n");
				}
		    


			printf("\n");
	    }
	     
	}
	else if(argc = 2) // doenst even print test
     {
     	char a;
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
		 
		  //c[sz] = '\0'; 
		  printf("%s\n", c); //prints entire string
		  char str[(int)bytes];
		  int l = 0;

		  /*
		  fgets(str, sizeof(str),argv[1]);
		  while(str[l]!= '\0')
		  {
		  	printf("%c", str[l]);
		  	l++;
		  }
			printf("\n");
	   */
	     
	}

	else
	{
		printf("nope");
	}
}

