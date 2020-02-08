#include <stdio.h>
#include <stdlib.h>




int main(int argc, char* argv[])
{
	int i;
	int size;
	//char buf[10];
	char* buf;
	FILE* inputFile = fopen("numbers.txt", "r");
	if(inputFile == NULL)
	{
		printf("error opening file");
		exit(1);
	}
	fseek(inputFile, 0L, SEEK_END);
	size = ftell(inputFile);
	rewind(inputFile);

	buf = calloc(1, size +1);
	if(!buf) fclose(inputFile),fputs("memory alloc fails",stderr),exit(1);
	int parity;
	if(1 != fread(buf, size, 1 , inputFile))fclose(inputFile),free(buf),fputs("entire read fails",stderr),exit(1);
	
		for(i= 0; i <= size+1; i++)
		{	
			printf("%c", buf[i]);
			if(buf[i] == '1')
			{
				parity++;
			}
			if(buf[i] == ' ')
			{
				printf(" ");
				if(parity % 2 == 0)
				{
					printf("even");
					parity = 0;
				}
				else
				{
					printf("odd");
					parity =0;
				}

				printf("\n");
				
			}

				
				
		}
		
	
	fclose(inputFile);
	free(buf);
}