#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[])
{
	//execve(argv[1], argv, NULL);
	signal(SIGINT, handle_sigint); 
    while (1) 
    { 
        printf(“hello world\n”); 
        sleep(1); 
    } 
    return 0; 
}
