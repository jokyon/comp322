#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

// cd /mnt/c/Users/Joseph/comp322/lab-6 

void sigHandler(int sig)
{
	//if (sig == SIGTERM)
   //{
     	sem_destroy(&mutex);
		printf("Philosopher completed %d cycles\n", cycle_count);
		exit(0);
    //}
}


int main(int argc, char* argv[])
{
	FILE *fp= NULL;
	pid_t process_id = 0;
	pid_t sid = 0;

	pid = fork();

	if (pid < 0)
	{
		printf("fork failed\n");
		exit(1);
	}
	
	if (pid > 0)
	{
		printf("child's pid: %d\n", pid);
		exit(0);
	}
	
	umask(0);
	
	sid = setsid(); //set new session
	if(sid < 0)
	{
		// Return failure
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

	fp = fopen ("Log.txt", "w+");
	while (1)
	{
		//Dont block context switches, let the process sleep for some time
		sleep(1);
		fprintf(fp, "Logging info...\n");
		fflush(fp);
		// Implement and call some function that does core work for this daemon.
		}
	fclose(fp);
	return (0);
}
