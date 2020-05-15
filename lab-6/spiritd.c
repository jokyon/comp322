#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <syslog.h>
#include <sys/resource.h>
#include <signal.h>
   
// cd /mnt/c/Users/Joseph/comp322/lab-6 


pid_t daePID, mole1, mole2;
char *newargv[] ={0};
 char *newenviron[] = { NULL };
pid_t mole1 = 0;
pid_t mole2 = 0;

void sigHandler(int sig)
{
	srand(time(0));
	int randNum = (rand() % (2 - 1 + 1)) + 1;
	if (sig == SIGTERM)
   	{
     	kill(mole1,SIGKILL);
     	kill(mole2,SIGKILL);
		printf("Killing all moles");
		exit(0);
    }

	pid_t newMole = 0;	
    if (sig == SIGUSR1)
    {

    	kill(mole1,SIGKILL);
    	if(randNum ==1)
    	{
    		mole2 = fork();
    		newMole = mole2;
    		execve(newargv[0], newargv, newenviron);
    	}
    	else
    	{
    		mole1 = fork();
    		newMole = mole1;
    		execve(newargv[0], newargv, newenviron);
    	}
    	execve(newargv[0], newargv, newenviron);
        printf("mole %d made \n", newMole);
    }

	if (sig == SIGUSR2)
    {
    	kill(mole2,SIGKILL);
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
    	execve(newargv[0], newargv, newenviron);
        printf("Received SIGUSR2\n");
    }

}


int main(int argc, char* argv[])
{
	//daePID = getpid();
	
	if(argc <2)
	{
		printf("needs moles\n");
		return - 1;
	}
	FILE *fp= NULL;
	//pid_t mole1 = 0;
	pid_t sid = 0;
	int i, fd0, fd1, fd2;
	
		char * word = strtok (argv[1], " ");
	    char path[128] = "/bin/";
	    strcat (path, word);
           
 
	newargv[0]= argv[1];
	printf ("[%s]\n", path);
	srand(time(0));
		
	


	signal(SIGTERM, sigHandler);
	signal(SIGUSR1, sigHandler);
	signal(SIGUSR2, sigHandler);
	
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
		
		execve(argv[1], newargv,newenviron); //stuck here
   	//perror("execve"); //
	//exit(EXIT_FAILURE);
	umask(0);
	
	sid = setsid(); //set new session
	if(sid < 0)
	{
		// Return fail
		exit(1);
	}
	// Change the current working directory to root.
	chdir("~/");
	//err_quit("%s: can’t change directory to /", cmd);
	// Close stdin. stdout and stderr
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	// Open a log file in write mode.

	int devNull = open("/dev/null", O_WRONLY);
	int copy_desc = dup(devNull); 
	/*
	fp = fopen ("lab6.log", "a+");

	if(fp == NULL)
	{
		printf("log fail\n");
	}

	fprintf(fp, "Pop %s\n", argv[0]); //
	*/	
		
	fclose(fp);
	return (0);
}
