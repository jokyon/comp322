#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <time.h> 
#include <sys/wait.h>
#include <sys/times.h>
		/*
		struct tms 
		{
		    clock_t tms_utime;   //user time 
		    clock_t tms_stime;  //system time 
		    clock_t tms_cutime; // user time of children 
		    clock_t tms_cstime; / system time of children 
		};
		*/
int main() 
{ 	
	time_t seconds;
	time(&seconds); 
	printf("start: %ld\n", seconds); 
	
	clock_t times(struct tms *buf);
	

	pid_t parent, child;
    printf("PPID: %d, PID: %d\n",getppid(),getpid());

    
    fork();

    struct tms process; 
  
     if( waitpid(getpid(),NULL, WUNTRACED) >0)
    {
    	printf("child stuff\n" );
    }
    else if(waitpid(getpid(),NULL, WUNTRACED) == 0 )
    {
    	printf("parent stuff\n");
    }
    else
    {
    	printf("error\n");
    }




    printf("user: %ld, sys: %ld\ncuser: %ld, csys: %ld\n", 
    	process.tms_utime, process.tms_stime, process.tms_cutime, process.tms_cstime);
    

    //printf("PPID: %d, PID: %d\n",getppid(),getpid());
    //printf("\n");   
  	
  	time(&seconds); 
  	printf("stop %ld\n",seconds);
    return 0; 
} 
