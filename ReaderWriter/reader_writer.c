#include <pthread.h>
#include <assert.h>
#include <sched.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

sem_t Read,Write,rmutex,wmutex,qlock;
int readCount = 0, writeCount = 0;
int r,w;
int readers[10000], writers[10000];

/*************Reader's Preference ************/
void *Reader1(void *i) {
	 for(int k=0;k<3;k++)
 {
	int n = (int) i;		
	sem_wait(&rmutex);
	  readCount ++;
	  if (readCount == 1) {
		sem_wait(&Write);
		for(int l =0;l<w;l++)
		{
			if(writers[l]==1)
				printf("Writer %d is waiting\n", l+1);
		}
		for (int i = 0; i < r; ++i)
		{
			readers[i]=0;
		}
	  }
	sem_post(&rmutex);
	printf("Reader %d is reading.\n",n+1);
	sem_wait(&rmutex);
	  readCount --;
	  if (readCount == 0) {
	      sem_post(&Write);
	  }
	sem_post(&rmutex);

}
 }
void *Writer1(void *i) {
	for(int k=0;k<3;k++)
{
	int n = (int) i;
	sem_wait(&Write);
	writers[n+1]=0;
	for (int i = 0; i < r; ++i)
	{
		if(readers[i]==1)
		{
			printf("Reader %d is waiting\n", i+1 );
		}
	}
	for (int i = 0; i < w; ++i)
	{
		if(writers[i]==1)
		{
			printf("Writer %d is waiting\n", i+1 );
		}
	}
	printf("Writer %d writing.\n",n+1);
	sem_post(&Write);
}
}


/************ Writer's preference ***********/


void *Reader2(void *i) {
		for(int k=0;k<3;k++)
{
	int n = (int) i;		
	sem_wait(&Read);
	sem_wait(&rmutex); 
	  readCount ++;
	  if (readCount == 1) {
		sem_wait(&Write);
		for (int i = 0; i < w; ++i)
		{
			if (writers[i]==1)
			{
				printf("Writer %d is waiting\n", i+1);
			}
		}
	  }
	sem_post(&rmutex);
	sem_post(&Read);
	readers[n]=0;
	printf("Reader %d is reading.\n", n + 1);
	//sleep(1);

	sem_wait(&rmutex);
	  readCount --;
	  if (readCount == 0) {
		sem_post(&Write);
	  }
	sem_post(&rmutex);
}
}
void *Writer2(void *i) {
		 for(int k=0;k<3;k++)

{
	int n = (int) i;

	sem_wait(&wmutex);
	  writeCount ++;
	  if (writeCount == 1){
		sem_wait(&Read);
		for (int i = 0; i < r; ++i)
		{
			if(readers[i]==1	)
			printf("Reader %d is waiting\n", i+1);
		}
	  }
	sem_post(&wmutex);

	sem_wait(&Write); 
	  writers[n]=0;
	  for (int i = 0; i < w; ++i)
	  {
	  	if (writers[i]==1)
	  	{
	  	printf("Writer %d is waiting\n", i+1);
	  	}
	  }
	  printf("Writer %d writing .\n", n + 1);
	sem_post(&Write);

	sem_wait(&wmutex);
	  writeCount --;
	  if (writeCount == 0) {
		sem_post(&Read);
	  }
	sem_post(&wmutex);
}
}

/********Fair ********/

void *Reader3(void *i) {
	 for(int k=0;k<3;k++)
	{
	int n = (int) i;		
	sem_wait(&qlock);
	sem_wait(&rmutex);
	  if (readCount == 0){
		sem_wait(&Write);
		for (int i = 0; i < w; ++i)
		{
			if (writers[i]==1)
			{
				printf("Writer %d is waiting\n",i+1 );
			}
		}
	  }
	  readCount++;
	sem_post(&qlock);
	sem_post(&rmutex);
	readers[n]=0;
	printf("Reader %d is reading.\n", n + 1);

	sem_wait(&rmutex);
	  readCount --;
	  if (readCount == 0) {
		sem_post(&Write);
	  }
	sem_post(&rmutex); 
}
}

void *Writer3(void *i) {
		for(int k=0;k<3;k++)
{
	int n = (int) i;

	sem_wait(&qlock);
	sem_wait(&Write);
	writers[n]=0;
	sem_post(&qlock);
	for (int i = 0; i < r; ++i)
	{
		if (readers[i]==1)
		{
			printf("Reader %d is waiting\n", i+1);
		}
	}
	printf("Writer %d writing.\n", n+ 1);

	sem_post(&Write);
}
} 




int main(int argc, char **argv) {

	int k = atoi(argv[1]);
	r = atoi(argv[2]);
    w = atoi(argv[3]);

	// Initializing semaphore variables 
	sem_init(&Write, 0, 1);
    sem_init(&Read, 0, 1);
    sem_init(&qlock, 0, 1);
    sem_init(&wmutex, 0, 1);
	sem_init(&rmutex, 0, 1);
	for (int i = 0; i < r; ++i)
	{
		readers[i]=1;
	}
	for (int i = 0; i < w; ++i)
	{
		writers[i]=1;
	}
	// Threads for readers and writers
	pthread_t reader[r], writer[w];
	switch(k){

	case 1 :
	{
		for (int i = 0; i < r; i ++) {
			pthread_create(&reader[i], NULL, Reader1, (void *)i);
		}

		for (int i = 0; i < w; i ++) {
			pthread_create(&writer[i], NULL, Writer1, (void *)i);
		}

		for (int i = 0; i < r; i ++) {
			pthread_join(reader[i], NULL);	
		}

		for (int i = 0; i < w; i ++) {
			pthread_join(writer[i], NULL);
		}
		break;
	}


	case 2 :{


                for (int i = 0; i < w; i ++) {
			pthread_create(&writer[i], NULL, Writer2, (void *)i);
		}

		for (int i = 0; i < r; i ++) {
			pthread_create(&reader[i], NULL, Reader2, (void *)i);
		}



		for (int i = 0; i < w; i ++) {
			pthread_join(writer[i], NULL);	
		}


		for (int i = 0; i < r; i ++) {
			pthread_join(reader[i], NULL);
		}
		break;
	}


	case 3:{
		for (int i = 0; i < w; i ++) {
			pthread_create(&writer[i], NULL, Writer3, (void *)i);
		}

		for (int i = 0; i < r; i ++) {
			pthread_create(&reader[i], NULL, Reader3, (void *)i);
		}

		for (int i = 0; i < w; i ++) {
			pthread_join(writer[i], NULL);	
		}

		for (int i = 0; i < r; i ++) {
			pthread_join(reader[i], NULL);
		}
		break;
	}
}
	return 0;
}
