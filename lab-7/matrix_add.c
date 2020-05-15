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
#include <syslog.h>
#include <sys/resource.h>

// cd /mnt/c/Users/Joseph/comp322/lab-7 

  	//int last, current, next;
int block_s, size, scalar;
//int block;

typedef struct aiocb aiocb_t;
   aiocb_t  last, current, next;


   //aiocb_t  *my_aio_list[1] = {&my_aio};

void matrix_add(int blk[size][size] ,int sz,int sclr)
{
	//int matrix[sz][sz];
	for (int i = 1; i <= sz; i++)
	{
		for (int j = 1; j <= sz; j++) 
            {
               blk[i][j] += sclr;
            }     
	} 
}


int main(int argc, char* argv[])
{	
	
	time_t curtime,endtime;
	struct tm * timeinfo;
	time (&curtime);
  	timeinfo = localtime (&curtime);
  	printf ( "Start time: %s", asctime (timeinfo));
  		
  	size =atoi(argv[1]);
	block_s = atoi(argv[2]);
	int block[size][size];

	off_t offset;


	aio_read(&current);
	aio_return(&current);
	/*
	for(current = 0; block_size )
	last = current -1;
	next - current +1 ;	
	*/
	//aio_int(&last, )
	/*
	int ret = aio_read(&my_aio);
    if (ret < 0)
        perror("aio_read");
	*/
	srand(time(0));
	scalar = rand();
	int block_size = size /block_s;
	//int q,w;
	//int mtx[q][w];

  	matrix_add(block, block_size,scalar);
  	
  	aio_write(&last);
  	aio_return(&last);
  		
	
  	
  	  	

  	//sleep(1);
  	time (&endtime);
  	timeinfo = localtime (&endtime);
	printf ( "End time: %s", asctime (timeinfo));
}
