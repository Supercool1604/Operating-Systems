#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define ll int
sem_t fillCount;	
sem_t emptyCount;
sem_t mutex;
pthread_t Producer;
int buffer[10];
int out = 0;
int in = 0;
pthread_t Consumer[3];



void* Consumerr(int i)
{
	if(i==0)
	{
		while(1)
		{

		sem_wait(&mutex);
			sem_wait(&fillCount);
			ll item = buffer[out];
			if(item  == -1)
			{
				printf("Consumer tried to consume from empty slot in buffer\n");
				return;
			}
			printf("Consumer 0 consumed value %d \n", item);
			sem_post(&emptyCount);
			buffer[out] = -1;
			out  = (out+1)%10;

		sem_post(&mutex);
		}

	}
	else
	{
		while(1)
		{
			int temp;
				sem_wait(&mutex);
			 sem_getvalue(&fillCount,&temp);

			if(temp<2)
			{
			
				wait();
			}
			
			else
				{

					sem_wait(&fillCount);
					sem_wait(&fillCount);
					ll item1 = buffer[out];
					ll item2 = buffer[(out+1)%10];
					if(item1 == -1 || item2 == -1)
					{
						printf("Consumer 1 trying to consume empty slot\n");
						return;
					}			
					printf("Consumer 1 consumed values %d and %d \n", item1,item2);
					sem_post(&emptyCount);
					sem_post(&emptyCount);
					buffer[out]=-1;
					buffer[(out+1)%10]=-1;
					out = (out+2)%10;
					sem_post(&mutex);
		}



	}
}
}
void* Producerr() {
	static int nextProduced = 0;
	while(1)
	{
		sem_wait(&emptyCount);
		if(buffer[in]!=-1)
		{
			printf("Producer trying to produce in filled slot\n");
			return;
		}
		nextProduced++;
		buffer[in]=nextProduced;
		printf("Producer produced value %d \n", nextProduced);
		in = (in + 1)%10;
		sem_post(&fillCount);
	}
}


int main()
{
	int i;
	for(int i=0;i<10;i++)
{
	buffer[i]=-1;
}
	// Consumer = malloc(sizeof(sem_t)*2);
	sem_init(&fillCount, 0, 1);
	sem_init(&emptyCount,0, 10);
	sem_init(&mutex,0,1);
pthread_create(&Producer, NULL, Producerr, NULL);

	for (i = 0; i < 2; ++i) 
	{
		
			pthread_create(&Consumer[i], NULL, Consumerr, (void *)(i));
	}
	
	

	for (i = 0; i < 2; ++i) 
	{
		pthread_join(Consumer[i], NULL);
	}

		pthread_join(Producer, NULL);
	return 0;
}
