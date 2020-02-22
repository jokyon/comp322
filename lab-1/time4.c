#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
	time_t seconds; 
    
    fork(); 
    seconds = time(NULL); 
    printf("%ld\n", seconds); 

    printf("test\n"); 
    return 0; 
} 
