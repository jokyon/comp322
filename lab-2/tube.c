#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <fcntl.h>             
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

// cd /mnt/c/Users/Joseph/comp322/lab-2 

int main(int argc, char *argv[])
{
	pid_t child1, child2, parent;
	//child1 = fork();
	//child2 = fork();
	char buf;

	int pipeC1[2];
	int pipeC2[2];

	if (argc != 2) 
	{
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (pipe(pipeC1) == -1) 
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

   	child1 = fork();
    if (child1 == -1) 
    {
	    perror("fork");
	    exit(EXIT_FAILURE);           
    }                         

	if (child1 == 0) 
	{    /* Child reads from pipe */
        close(pipeC1[1]);          /* Close unused write end */

        while (read(pipeC1[0], &buf, 1) > 0)
                   write(STDOUT_FILENO, &buf, 1);

               write(STDOUT_FILENO, "\n", 1);
               close(pipeC1[0]);
               _exit(EXIT_SUCCESS);
    }

    else 
    {            /* Parent writes argv[1] to pipe */
    	close(pipeC1[0]);          /* Close unused read end */
    	write(pipeC1[1], argv[1], strlen(argv[1]));
    	close(pipeC1[1]);          /* Reader will see EOF */
    	wait(NULL);                /* Wait for child */
    	exit(EXIT_SUCCESS);
    }



}