#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <time.h> 

#include <sys/wait.h>
int main() 

{ 
	time_t seconds; 
    seconds = time(NULL); 

    printf("start time: %ld\n", seconds);
    
    pid_t parent, child;
    


    printf("PPID: %d, PID: %d",getppid(),getpid());
    printf("\n");

    //pid_t child;

    // make two process which run same 
    // program after this instruction 
    
    fork(); 
    child = wait(NULL);
    if(child >0)
    {
    	printf("child stuff\n" );
    }
    else if(child =0 )
    {
    	printf("parent stuff\n");
    }
    else
    {
    	printf("error\n");
    }


    printf("Parent pid = %d\n", getpid()); 
    printf("Child pid = %d\n", child); 
    time_t seconds2 = time(NULL); 
    printf("%ld\n", seconds2);
  
   
    return 0; 
} 
