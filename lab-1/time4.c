#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <time.h> 
int main() 

{ 
  
    // make two process which run same 
    // program after this instruction 
    fork(); 
    time_t seconds; 
      
    seconds = time(NULL); 
    printf("%ld\n", seconds);
  
    printf("Hello world!\n"); 
    return 0; 
} 
