#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

#define PAGESIZE 4096

int main(int argc, char* argv[])
{
	unsigned int address;
	unsigned int pgNum;
	unsigned int offset;

	if(argcc <2)
	{
		printf("enter address: \n", );
		return - 1;
	}

	address = atoi(argv[1]);
	pgNum = address / PAGESIZE;
	offset = address % PAGESIZE;

	printf("The address: %u\n", address);
	printf("Page number: %u\n", pgNum);
	printf("Offset: %u\n", offset);
	
}