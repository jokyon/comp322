#include <stdio.h>
#include <stdlib.h>

int input;

 void ascToBinary(int character, int *ones)
    {
        if(character == 1)
        {
           printf("1");
           *ones+=1;
           return;
        }
        else
        {
            char out;
            if((character%2) == 0)
            {
                 out = '0';
                 character = character/2;
            }
            else
            {
                 out = '1';
                 character = character/2;
                 *ones+=1;

            }
            ascToBinary(character, ones);
            putchar (out);
        }
    }




int main(int argc, char* argv[])
{
	 
	FILE*  numFile;
	numFile = fopen("numbers.txt", "r");

	int arr[]

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