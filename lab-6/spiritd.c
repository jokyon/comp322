#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
   
// cd /mnt/c/Users/Joseph/comp322/lab-6 

//execve(argv[0], argv, NULL);
    	
pid_t daePID, mole1, mole2;
//pid_t mole1 = 0;
//pid_t mole2 = 0;
/*
void sigHandler(int sig)
{
	srand(time(0));
	int randNum = (rand() % (2 - 1 + 1)) + 1;
	if (sig == SIGTERM)
   {
     	kill(mole1);
     	kill(mole2);
		printf("Caught SigTerm");
		exit(0);
    }

	
    if (signum == SIGUSR1)
    {
    	kill(mole1);
    	if(randNum ==1)
    	{
    		mole2 = fork();
    		//execve(argv[0], argv, NULL);
    	}
    	else
    	{
    		mole1 = fork();
    		//execve(argv[0], argv, NULL);
    	}
    	execve(argv[0], argv, NULL);
        printf("Received SIGUSR1\n");
    }

	if (signum == SIGUSR2)
    {
    	
    	if (mole2 <= 0)
    	{
    		mole2 = fork(); 
    	}
    	if(randNum ==1)
    	{
    		mole2 = fork();

    	}
    	else
    	{
    		mole1 = fork();    		
    	}
    	execve(argv[0], argv, NULL);
        printf("Received SIGUSR2\n");
    }


}
*/

int main(int argc, char* argv[])
{
	daePID = getpid();
	FILE *fp= NULL;
	//pid_t mole1 = 0;
	pid_t sid = 0;
	char *newargv[] ={0};
	newargv[0]= argv[1];

	/*
	signal(SIGTERM, sigHandler);
	signal(SIGUSR1, sigHandler);
	signal(SIGUSR2, sigHandler);
	*/

	mole1 = fork();	
	if (mole1 < 0)
	{
		printf("fork failed\n");
		exit(1);
	}
	
	if (mole1 > 0)// kill parent
	{
		printf("mole's pid: %d\n", mole1);
		exit(0);
	}
	execve(argv[1], newargv, NULL);
   	perror("execve"); //
	exit(EXIT_FAILURE);
	umask(0);
	
	sid = setsid(); //set new session
	if(sid < 0)
	{
		// Return fail
		exit(1);
	}
	// Change the current working directory to root.
	chdir("/");
	// Close stdin. stdout and stderr
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	// Open a log file in write mode.

	int devNull = open("/dev/null", O_WRONLY);
	int copy_desc = dup(devNull); 

	fp = fopen ("lab6.log", "a+");

	if(fp == NULL)
	{
		printf("log fail\n");
	}

	fprintf(fp, "Pop %s\n", argv[0]); //

	while (1)
	{
		//Dont block context switches, let the process sleep for some time
		sleep(1);
		fprintf(fp, "Logging info...\n");
		fflush(fp);
		break;
		// Implement and call some function that does core work for this daemon.
	}
	fclose(fp);
	return (0);
}
