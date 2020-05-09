#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <time.h>

int blocks, size, scalar;


int matrix_add(int blk,int sz,int sclr)
{
	for (i = 1; i <= sz; i++)
	{
		for (j = 1; <= sz; j++) 
            {
               blk[i][j] += sclr;
            }     
	} 
}


int main(int argc, char* argv[])
{	
	block = atoi(argv[1]);
	FILE *fp= NULL;
	fp = fopen ("lab7.txt", "a+");
	fprintf(fp, "%s\n", argv[0]);

	time_t curtime;
	struct tm * timeinfo;

  	time ( &rcurtime );
  	timeinfo = localtime ( &curtime );
  	printf ( "Current time: %s", asctime (timeinfo));



  	for(int x =1; x <= blocks; x++)
  	{
  		for(int y = 1; y <= blocks; y++)
  		{
  			
  		}
  	}

	srand(time(0));
	size = (rand() % (2 - 1 + 1)) + 1;
	int block_size = size /block;
}
