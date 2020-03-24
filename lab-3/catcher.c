#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <time.h> 

//	cd /mnt/c/Users/Joseph/comp322/lab-3  
pid_t PID;
int counter = 0;
 time_t seconds;

      
    
void handler(int sig) 
{ 
	//pid_t PID = getpid();
    //printf("Caught signal %d\n", sig);
    //write(STDOUT_FILENO, "SIGINT caught\n", 13);
    if (sig == SIGTERM)
    {
       //printf("Received SIGUSR1!\n");
    	write(STDOUT_FILENO, "Received SIGTERM\n", 17);
    	//printf("%ld\n",seconds );
    	counter++;
    }

	if (sig == SIGUSR1)
    {
       //printf("Received SIGUSR1!\n");
    	write(STDOUT_FILENO, "Received SIGUSR1\n", 17);
    	//
    	counter++;

    }


    if (sig == SIGUSR2)
    {
       //printf("Received SIGUSR1!\n");
    	write(STDOUT_FILENO, "Received SIGUSR2\n", 17);
    	//printf("%ld\n",seconds );
    	counter++;
    }


    //exit(EXIT_SUCCESS);
} 
  
void seghandler(int sig)
{
	write(STDOUT_FILENO, "Seg fault\n", 10);
	counter++;
	exit(EXIT_SUCCESS); //without exit cotinuously loops
}

int main(int argc, char *argv[])
{
	 time(&seconds);
	char* TERM = "TERM";
	char* USR1 = "USR1";
	char* USR2 = "USR2";

	
	for(int i = 1; i <= argc; i++)
	{
		printf("%d\n", getpid());
		if(strcmp(argv[i], TERM) ==0)
		{
			signal(SIGTERM, handler);
			raise(SIGTERM);
			pause();
			//kill(getpid(), SIGTERM);
		}
		if(strcmp(argv[i], USR1)==0)
		{
			signal(SIGUSR1, handler);
			raise(SIGUSR1);
			pause();
			//kill(getpid(), SIGUSR1);
		}
		if(strcmp(argv[i], USR2)==0)
		{
			signal(SIGUSR2, handler);
			raise(SIGUSR2);
			pause();

			//kill(getpid(), SIGUSR2);
		}
		//if(argv[argc-1])
		//signal(SIGSEGV, seghandler); // if outside for loop, segfault

	}
	
	//execve(argv[1], argv, NULL);
	//signal(SIGINT, handler);
	//pause();
	//kill(PID, SIGINT);
	//signal(SIGUSR1, handler);
	
	//PID = getpid();
    //while (1) 
    //{ 
        printf("cycle: %d\n", PID); 
        printf("signals caught: %d\n", counter);
        
        //sleep(1); 
    //} 
    return 0; 
}
