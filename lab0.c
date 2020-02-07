#include <stdio.h>
#include <stdlib.h>

int input;




int main(int argc, char* argv[])
{
	 
	FILE*  numFile;
	numFile = fopen("numbers.txt", "r");

	int arr[];

	if (inputFile == NULL)
	{
        printf("no file\n");
        return 0;
    }

    int n;
	while (fscanf(inputFile, " %d", &n) == 1) 
	{
    	printf("%d\n", n);
	}

	return 0;

}