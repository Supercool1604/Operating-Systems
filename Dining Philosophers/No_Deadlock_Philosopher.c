#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
sem_t *forks;
sem_t footman;
pthread_t philosophers[7];


int right(int i)
{
	return (i+1)%5;
}

int left(int i)
{
	return (i)%5;
}


void think(int i)
{
	int s = rand()%3;
	printf("Philosopher %d will think for %d seconds\n", i, s);
	sleep(s);
}

void pick(int i)
{
	
	
	sem_wait(&footman);
	printf("Philosopher %d waiting for fork %d\n", i, right(i));

	// locking the right fork
	sem_wait(&forks[right(i)]);
	
	printf("Philosopher %d picked up fork %d\n", i, right(i));

	printf("Philosopher %d waiting for fork %d\n", i, left(i));
	
	//locking the left fork
	sem_wait(&forks[left(i)]);
	
	printf("Philosopher %d picked up fork %d\n", i, left(i));

	}


void eat(int i) {
	int eatTime = rand()%3;
	printf("Philosopher %d eats %d seconds\n", i, eatTime);
	sleep(eatTime);
	// sem_post(&mutex);
}

void drop(int i) {
	printf("Philosopher %d will drop his forks\n", i);
	sem_post(&forks[right(i)]);
	sem_post(&forks[left(i)]);
	sem_post(&footman);
}

void *philosopher(void * i)
{
	while(1)
	{
		think(i);
		pick(i);
		eat(i);
		drop(i);
	}
}

int main()
{
	int i;
	forks = malloc(sizeof(sem_t)*5);
	sem_init(&footman, 0 , 4);
	for (i = 0; i < 5; ++i) 
	{
		sem_init(&forks[i],0,1);
	}
	for (i = 0; i < 5; ++i) 
	{
		pthread_create(&philosophers[i], NULL, philosopher, (void *)(i));
	}
	for (i = 0; i < 5; ++i) 
	{
		pthread_join(philosophers[i], NULL);
	}
	return 0;
}
