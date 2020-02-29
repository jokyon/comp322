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

pid_t parent, child, PID, PPID, cPID, cPPID;

void processPrint(int prc)
{
    if(prc==0)
    {
    	cPID = getpid();
    	cPPID = getppid();
        printf("PPID: %d PID: %d\n",cPPID ,cPID);
        //printf("child stuff\n");
        exit(0);
    }
    
    else if(prc >0)
    {
    	prc = waitpid(prc,NULL, WUNTRACED);
        if( prc == parent)
        {
        	PID = getpid();
        	PPID = getppid();
            printf("PPID: %d PID: %d CPID: %d RETVALUE: %d\n",PPID, PID, prc, cPID); // prc and pPID names need testing
            //printf("child interupt\n");
            //exit(0);
        }
        
    }
    else if(prc == -1)
    {
        printf("forking error\n");
        exit(0);
    }
}




int main() 
{   
    time_t seconds;
    time(&seconds);

    printf("START: %ld\n", seconds); 
        

    //pid_t parent, child, PID, PPID, cPID, cPPID;
    //PID = getpid();
    //PPID = getppid();
    

    parent = fork();
    child = parent;
    
    //cPID = getpid();
    //cPPID = getppid();
    
    
                        
    struct tms process; 
    times(&process);  
     
    
    processPrint(parent);
    processPrint(child);
    

    printf("USER: %ld SYS: %ld\nCUSER: %ld CSYS: %ld\n", 
        process.tms_utime, process.tms_stime, process.tms_cutime, process.tms_cstime);
    

    

    time(&seconds);
    printf("END: %ld\n",seconds);
    return 0; 
} 
