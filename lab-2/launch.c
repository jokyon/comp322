#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <fcntl.h>             
#include <sys/wait.h>
#include <stdlib.h>


//	cd /mnt/c/Users/Joseph/comp322/lab-2  

pid_t parent, child, PID, PPID, cPID;

void processPrint(int prc)
{
    if(prc==0)
    {
    	cPID = getpid();
    	//cPPID = getppid();
        //printf("PPID: %d PID: %d\n",cPPID ,cPID);
        //printf("child stuff\n");
        exit(0);
    }
    
    else if(prc >0)
    {
    	prc = waitpid(prc,NULL, WUNTRACED);
        if( prc == parent)
        {
        	//PID = getpid();
        	//PPID = getppid();
            printf("CPID: %d\n", prc); 
            fprintf(stderr, "= %d\n", cPID); //this is wrong
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
	char* newArgv[argc];
	for (int i =1; i<argc -1; i++)
	{
		int j =0;
		newArgv[i] = argv[i];
		printf("%s", newArgv[i]);
	}
	printf("\n");
	
  	char* newEnvp[] = {NULL};
		parent = fork();
    	child = parent;

		processPrint(parent);
    	processPrint(child);

	//newArgv[0] = argv[1];
	execve(argv[1], newArgv, newEnvp);
  	perror("Could not execve");
  	exit(EXIT_FAILURE);

}