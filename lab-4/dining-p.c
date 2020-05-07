#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h> 
#include <time.h>

#define TEMP 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0

#define LEFT (pNum + 4) % TEMP
#define RIGHT (pNum + 1) % TEMP

//	cd /mnt/c/Users/Joseph/comp322/lab-4  



int state[TEMP]; 
int phil[TEMP] = { 0, 1, 2, 3, 4 }; 
  
sem_t mutex; 
sem_t seats[TEMP]; 

 
int cycleCount =0;  
void pickup(int pNum) 
{ 
    if (state[pNum] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) 
    { 
        
        state[pNum] = EATING; 
  
        sleep(2); 
  
        printf("Philosopher %d picks up sticks %d and %d\n", pNum + 1, LEFT + 1, pNum + 1); 
        printf("Philosopher %d is eating\n", pNum + 1); 
  
        sem_post(&seats[pNum]); 
    } 
} 
  
// take up chopsticks 
void eat(int pNum) 
{ 
  
    sem_wait(&mutex); 
  
    
    state[pNum] = HUNGRY; 
  
    printf("Philosopher %d is hungry\n", pNum + 1); 
  
    
    pickup(pNum); 
  
    sem_post(&mutex); 
  
     
    sem_wait(&seats[pNum]); 
  
    sleep(1); 
} 
  

void think(int pNum) 
{ 
  
    sem_wait(&mutex); 
  
    
    state[pNum] = THINKING; 
  
    printf("Philosopher %d drops sticks %d and %d down\n", 
           pNum + 1, LEFT + 1, pNum + 1); 
    printf("Philosopher %d is thinking\n", pNum + 1); 
  
    pickup(LEFT); 
    pickup(RIGHT); 
  
    sem_post(&mutex); 
} 
  
void sigHandler(int sig)
{
	//if (sig == SIGTERM)
   //{
     	sem_destroy(&mutex);
		printf("Philosopher completed %d cycles\n", cycleCount);
		exit(0);
    //}
}

void* philospher(void* num) 
{ 
  	
    while (1)
    { 	cycleCount++; 
    	int* i = num; 
        sleep(1); 
        eat(*i);
        	usleep(rand()/2);  
        sleep(0); 
        think(*i);
        	usleep(rand()/2); 
    } 
} 
  
int main(int argc, char *argv[]) 
{ 
	srand(time(0));
  	pid_t PID = getpid();
  	printf("%d\n",PID);

  	//int x = atoi(argv[1]);

    int i; 
    pthread_t thread_id[TEMP]; 
  	signal(SIGTERM, sigHandler);
    // initialize the semaphores 
    sem_init(&mutex, 0, 1); 
  
    for (i = 0; i < TEMP; i++) 
  	{
        sem_init(&seats[i], 0, 0); 
  	}
  	printf("Everyone is thinking\n"); 
    for (i = 0; i < TEMP; i++) 
    { 
    	pthread_create(&thread_id[i], NULL, philospher, &phil[i]); 
  		//printf("Philosopher %d is thinking\n", i + 1); 
    } 
  
    for (i = 0; i < TEMP; i++) 
  	{
    	pthread_join(thread_id[i], NULL); 
  	}
  	 	
} 