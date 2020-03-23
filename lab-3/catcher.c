#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

//	cd /mnt/c/Users/Joseph/comp322/lab-3  
pid_t PID;

void handler(int sig) 
{ 
	//pid_t PID = getpid();
    //printf("Caught signal %d\n", sig);
    //write(STDOUT_FILENO, "SIGINT caught\n", 13);
    if (sig == SIGTERM)
    {
       //printf("Received SIGUSR1!\n");
    	write(STDOUT_FILENO, "Received SIGTERM\n", 17);
    }

	if (sig == SIGUSR1)
    {
       //printf("Received SIGUSR1!\n");
    	write(STDOUT_FILENO, "Received SIGUSR1\n", 17);
    }


    if (sig == SIGUSR2)
    {
       //printf("Received SIGUSR1!\n");
    	write(STDOUT_FILENO, "Received SIGUSR2\n", 17);
    }
    //exit(EXIT_SUCCESS);
} 
  


int main(int argc, char *argv[])
{
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
        //sleep(1); 
    //} 
    return 0; 
}
