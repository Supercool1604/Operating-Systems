#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define	FIRST	0
#define SECOND 	1

#define	FALSE	0
#define TRUE 	1

#define	MILLISECONDS	1000

#define	NTURN	50

#define	RAND_MAX	0xFFFFFFFFu // Maximum 32-bit unsigned number

int	t1_wants2enter = FALSE;
int	t2_wants2enter = FALSE;
int	count=0;

pthread_t	t1, t2;
int favoredProcess = 1;

void	*thread1(void *args) {
	for(int i=0; i < NTURN; i++) {
		t1_wants2enter = TRUE;
		usleep((int)(MILLISECONDS * ((float)rand()/RAND_MAX)));
		while(t2_wants2enter == TRUE) {
			if(favoredProcess==2)
			{
			t1_wants2enter = FALSE;
			while(favoredProcess==2)
		 	usleep((int)(MILLISECONDS * ((float)rand()/RAND_MAX)));
			t1_wants2enter = TRUE;
			printf("Thread 1 waiting\n") ;
		}
	}
	favoredProcess=2;
		// In critical section
		printf("Thread 1 - Enter critical section\n");
		count = count + 1;
		printf("Thread 1 - EXIT critical section -- %d\n", count);
		t1_wants2enter = FALSE;
	}
}

void	*thread2(void *args) {
	for(int i=0; i < NTURN; i++) {
		t2_wants2enter = TRUE;
		usleep((int)(MILLISECONDS * ((float)rand()/RAND_MAX)));
		while(t1_wants2enter == TRUE) {
			if(favoredProcess==1)
			{
			t2_wants2enter = FALSE;
			while(favoredProcess==1)
		 	usleep((int)(MILLISECONDS * ((float)rand()/RAND_MAX)));
			t2_wants2enter = TRUE;
			printf("Thread 2 waiting\n") ;
		}
	}
		printf("Thread 2 - Enter critical section\n");
		// In critical section
		count = count + 1;
		favoredProcess=1;
		printf("Thread 2 - EXIT critical section -- %d\n", count);
		t2_wants2enter = FALSE;
	}
}

int	main(void) {
	srand(time(NULL));
	if( pthread_create(&t1, NULL, thread1, NULL) != 0) {
		printf("Thread one not created. Quitting.\n");
		exit(0);
	}
	if( pthread_create(&t2, NULL, thread2, NULL) != 0) {
		printf("Thread two not created. Quitting.\n");
		exit(0);
	}
	if(pthread_join(t1, NULL) != 0) {
		//perror("Thread 1 (exit) ");
		exit(0);
	}
	if(pthread_join(t2, NULL) != 0) {
		//perror("Thread 1 (exit) ");
		exit(0);
	}
	return 0;
}
