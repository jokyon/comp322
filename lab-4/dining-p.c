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

#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define TEMP 5

#define LEFT (pNum + 4) % TEMP 
#define RIGHT (pNum + 1) % TEMP 

//	cd /mnt/c/Users/Joseph/comp322/lab-4  

//notes doesnt need to break, needs sigterm
int state[TEMP];
//int seats;
int phil[TEMP] ={0,1,2,3,4};

sem_t mutex;
sem_t seats[TEMP];

//sem_t *chopstick[5];
//int *chopstick[5];

int cycle_count;

void pickup(int pNum)
{
	if(state[pNum] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
	{
		state[pNum] = EATING;
		sleep(2); //

		printf("Philosopher %d picks up sticks %d and %d\n", pNum + 1, LEFT + 1, pNum + 1); 
		printf("Philosopher %d can eat\n", pNum + 1);
	}
	sem_post(&seats[pNum]);
}


void eat(int pNum)
{
	sem_wait(&mutex);
	state[pNum] = HUNGRY; 
	printf("Philosopher %d hungry\n", pNum + 1); 

	//int r = rand();
	//usleep(r);
	//usleep(1);
	pickup(pNum);
	sem_post(&mutex);
	sem_wait(&seats[pNum]);

	printf("Philosopher #%d is eating\n",pNum);
	sleep(1);
}

void think(int pNum)
{
	sem_wait(&mutex);
	state[pNum] = THINKING;
	//int r = rand();
	//usleep(r);
	//usleep(1);
 	printf("Philosopher %d putting sticks %d and %d down\n", 
           pNum + 1, LEFT + 1, pNum + 1); 
    printf("Philosopher #%d is thinking\n", pNum + 1); 
	pickup(LEFT);
	pickup(RIGHT);

	sem_post(&mutex);
}


void sigTermHandler(int sig)
{
	//printf("Philosopher #%d has eaten %d times.\n", process_number, eat_count);
	sem_destroy(&mutex);
	printf("%d cycles done\n", cycle_count);
	exit(0);
}


void* philosopher(void* n)
{
	while(1)
	{
		int * i = n;
		sleep(1);//
		eat(*i);
		sleep(0);//
		think(*i);
		cycle_count++;
	}
}

int main(int argc, char *argv[])
{
	//printf("my %s has %d chars\n", "string format", 30);
	int i;
	pthread_t threadID[TEMP];
	sem_init(&mutex, 0,1);
		int PID = getpid();
		printf("%d\n",PID );
	for(i =0; i < TEMP; i++);
	{
		sem_init(&seats[i],0,0);
	}
	for(i =0; i < TEMP; i++);
	{
		pthread_create(&threadID[i], NULL, philosopher,&phil[i]);
		printf("Philosopher %d is thinking\n", i + 1); 
	}

	for(i = 0; i < TEMP; i++)
	{
		pthread_join(threadID[i],NULL);
	}


	//seats = argv[1];
	//int position = argv[2];
	//philosophers(2,seats);


}