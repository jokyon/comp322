#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <time.h> 
#include <sys/wait.h>
#include <sys/times.h>
#include <stdlib.h>

/*
cd /mnt/c/Users/Joseph/comp322/lab-1	
*/

/*
void processPrint(int prc)
{
	if(child==0)
    {
    	printf("PPID: %d PID: %d CPID: %d RETVALUE: %d\n", PID,PPID,cPID, child);
    	//printf("child stuff\n");
    	exit(0);
    }
    else if(child == -1)
    {
    	printf("forking error\n");
    	exit(0);
    }
    else
    {
    	if(waitpid(child,NULL, 0) == child)
    	{
    		printf("PPID: %d PID: %d\n",PPID,PID);
    		//printf("child interupt\n");
    		//exit(0);
    	}
    	else
    	{
    		printf("nah\n");
    	}
    }
}
*/


int main() 
{ 	
	time_t seconds;
	time(&seconds);

	printf("START: %ld\n", seconds); 
	
	clock_t times(struct tms *buf);
	

	pid_t parent, child, PID, PPID, cPID, cPPID;
	PID = getpid();
	PPID = getppid();
    //

    child = fork(); 
    cPID = getpid();
	cPPID = getppid();
    
    
    					//this goes up^?/* RETVALUE: %d*/
    struct tms process; 
     times(&process);  //???
     //printf("child is: %d\n", child);

    if(child==0)
    {
    	printf("PPID: %d PID: %d CPID: %d RETVALUE: %d\n", PID,PPID,cPID, child);
    	//printf("child stuff\n");
    	exit(0);
    }
    else if(child == -1)
    {
    	printf("forking error\n");
    	exit(0);
    }
    
    else
    {
    	if(waitpid(child,NULL, WUNTRACED) == child) //WUNTRACED here?
    	{
    		printf("PPID: %d PID: %d\n",PPID,PID);
    		//printf("child interupt\n");
    		//exit(0);
    	}
    	else
    	{
    		printf("nah\n");
    	}
    }
        

    printf("USER: %ld SYS: %ld\nCUSER: %ld CSYS: %ld\n", 
    	process.tms_utime, process.tms_stime, process.tms_cutime, process.tms_cstime);
    

    //times(&process);

    //printf("PPID: %d, PID: %d\n",getppid(),getpid());
    //printf("\n");   
  	
  	printf("END: %ld\n",seconds);
    return 0; 
} 
