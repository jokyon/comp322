#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h> 
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <unistd.h>
// 01011101 10110111 11101011 111101

int main(int argc, char** argv)
{
    //make sure only 2 command line arguments entered
    if( argc < 2)
        {
        printf("error not enough arguments\n");
        return 1;
        }
     else if(argv[1][0] == '-')
     {
     	printf("Original As De Pa\n");
		printf("-------- -- -- --\n");
	    for(int i =2; i < argc; i++)
	    {    
	    	
	    	
		    for (int j = 0; j < strlen(argv[i]); j++)
		    {
		   	  	int m = strlen(argv[i]);
		    	int keyword[m];
		    	keyword[j] = argv[i][j] - '0';
		    	printf("%d",keyword[j]);
		    }
			printf("\n");
	    }
     }
     else if(argc > 2)//
     {
         // declare variable "m" to designate the number of elements in the array "keyword"
        	//int m2 = strlen(argv[1]);
        //array declaration for "keyword" with "m" elements
        	//int keyword2[m2];
        	//keyword2[0] = argv[1][1] - '0';  //seconded number increments thru the input number
        //convert characters to integers
        //iterate through characters in argv[1] in order to printf the elements in the array
	    	//printf("%d\n",keyword2[0]);
	    printf("Original As De Pa\n");
		printf("-------- -- -- --\n");
	    for(int i =1; i < argc; i++)
	    {    
	    	 	
		    for (int j = 0; j < strlen(argv[i]); j++)
		    {
		   	  	int m = strlen(argv[i]);
		    	int keyword[m];
		    	keyword[j] = argv[i][j] - '0';
		    	printf("%d",keyword[j]);
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

		  fgets(str, sizeof(str),argv[1]);
		  while(str[l]!= '\0')
		  {
		  	printf("%c", str[l]);
		  	l++;
		  }
			printf("\n");
	   
	     
	}
	else
	{
		printf("nope");
	}
}

