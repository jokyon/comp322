#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
	int i;
	int size;
	char* buf;
	
	FILE* inputFile = fopen("numbers.txt", "r");
	if(inputFile == NULL)
	{
		perror("error opening file");
		exit(1);
	}

	fseek(inputFile, 0L, SEEK_END);
	size = ftell(inputFile);
	rewind(inputFile);

	buf = calloc(1, size +1);
	if(!buf) fclose(inputFile),fputs("memory alloc fails",stderr),exit(1);
	int parity;
	int expCounter = 8;
	int expVal = 0;
	if(1 != fread(buf, size, 1 , inputFile))fclose(inputFile),free(buf),fputs("entire read fails",stderr),exit(1);
	int numCount = 0;
	printf("Original  As De Pa\n");
	printf("--------  -- -- --\n");
	//printf("test1 %c\n", buf[0]);
		for(i= 0; i <= size+1; i++) // puts each char into arr index
		{	
			
			
			printf("%c", buf[i]);
			numCount++;
			
			expCounter--;
			if(buf[i] == '1')
			{
				parity++;
				expVal += pow(2, expCounter);  // need to fix leftmost bit exponent
			}
			
			//num += (val - '0') <<(7-i);
			//printf("test2 %d",num);

			if(buf[i] == ' ') 
			{
				/*
				if(numCount < 8) //trying to pad, need to insert into array
				{
					for(int pad =0; pad <= 8-numCount; pad++ )
					{
						printf("0");
					}
					numCount =0;
				}
				numCount=0;
				*/
				
				if(expVal > 128) //not sure if works in all cases
				{
					expVal = expVal - 128;
				}
				
				printf(" %c ", expVal);
				printf(" %d ", expVal);
				expCounter = 8;
				expVal = 0;
				
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

			//num += (val - '0') <<( 7-1); 
			//printf("%d", num);		
					
		}
		
	fclose(inputFile);
	free(buf);
}