#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <fcntl.h>             
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

// cd /mnt/c/Users/Joseph/comp322/lab-2 

pid_t parent, child1, child2, cPID;

void processPrint(int prc, pid_t printChild)
{
    if(prc==0)
    {
    	cPID = getpid();
    	//printf("PPID: %d PID: %d\n",cPPID ,cPID);
        //printf("child stuff\n");
        exit(0);
    }
    
    else if(prc >0)
    {
    	prc = waitpid(prc,NULL, WUNTRACED);
        if( prc == printChild)
        {
        	printf("CPID = %d\n", prc); // prc and pPID names need testing or renaming 
            fprintf(stderr, "= %d\n", cPID);
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




int main(int argc, char *argv[]) 
{   
	char buf;
    int pipeC1[2];
    int pipeC2[2];


    child1 = fork();
    parent = child1;    
    processPrint(child1, parent);

    close(pipeC1[1]);
    while (read(pipeC1[0], &buf, 1) > 0)
    {
        write(STDOUT_FILENO, &buf, 1);
    }
    
    write(STDOUT_FILENO, "\n", 1);
    close(pipeC1[0]);
    //_exit(EXIT_SUCCESS);
        
    //dup2(argv[1],2);

    child2 = fork();
    parent =child2;
        
    processPrint(child2, parent);
    close(pipeC2[2]);
    while (read(pipeC2[0], &buf, 1) > 0)
    {
        write(STDOUT_FILENO, &buf, 1);
    }
    
    write(STDOUT_FILENO, "\n", 1);
    close(pipeC2[0]);
        
   		//execve(argv[1], argv, NULL);
  		//perror("Could not execve");
  		//exit(EXIT_FAILURE);
   //parent = child1;
       _exit(EXIT_SUCCESS); 
   return 0; 
}


