#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <syslog.h>
#include <sys/resource.h>
#include <signal.h>

// cd /mnt/c/Users/Joseph/comp322/lab-6 

int main(int argc, char *argv[])
{

	FILE *fp= NULL;
	//int j;

	fp = fopen ("lab6.log", "a+");
	if(fp == NULL)
	{
		printf("log fail\n");
	}
	fprintf(fp, "Pop %s\n", argv[0]); //

    //for (j = 0; j < argc; j++)
    
	printf("went to mole\n");
    exit(EXIT_SUCCESS);
}
