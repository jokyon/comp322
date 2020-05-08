#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>



// cd /mnt/c/Users/Joseph/comp322/lab-5 

int main(int argc, char* argv[])
{
	int pagesize = 4096; //4kb to 4096bytes
	unsigned int address;
	unsigned int pgNum;
	unsigned int offset;

	if(argc <2)
	{
		printf("Please enter an address\n");
		return - 1;
	}

	address = atoi(argv[1]);
	pgNum = address / pagesize;
	offset = address % pagesize;

	printf("The address: %u\nPage number: %u\nOffset: %u\n", address, pgNum, offset);
	//printf("Page number: %u\n", pgNum);
	//printf("Offset: %u\n", offset);
	
}