#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <time.h>
#include <aio.h>
#include <math.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

// cd /mnt/c/Users/Joseph/comp322/lab-7 

int main(int argc, char* argv[])
{		
	
	int size = atoi(argv[1]);
	//blocks = atoi(argv[2]);
	int mtx[size][size];
	srand(time(0));
	for(int i =1; i <= size; i++)
  	{
  		
  		for(int j = 1; j <= size; j++)
  		{
  			
  			int mtx_value = (rand() % (100 - 0 + 1)) + 1;
  			int negative = (rand() % (2 - 1 + 1)) + 1;
			if(negative ==2 ) //randomly decides negative
			{
	   			mtx_value *= -1;
	   		}
  			mtx[i][j] = mtx_value;
  			//char snum[5];

  			fprintf(stdout, "%d ", mtx_value);
  		}
  		fprintf(stdout,"\n");
  	}	
 	
 	return 0;
}
