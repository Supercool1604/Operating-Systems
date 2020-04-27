#include <stdio.h> 
#include <unistd.h>
#include <string.h> 
#include <stdlib.h>

#include <pthread.h>
  

 #define n 5 
/* Array to record which processes are taking a ticket */
bool choosing[n];
/* Value of the ticket for each process initialized to 0 */
int tickets[n];
#define NTURN 100
int	count=0;

void	*thread1(void *args) {
	int x = (long) args;
int max_ticket;
 for (int i = 0; i < n; ++i) { 
  
        int ticket = tickets[i]; 
        max_ticket = ticket > max_ticket ? ticket : max_ticket; 
    } 


	for(int i=0; i < NTURN; i++) {
		{

/* Take a ticket */
choosing[x] = true; /* begin ticket selection process */
tickets[x] = max_ticket+1;
choosing[x] = false; /* end ticket selection process */
/* Wait until turn of current ticket comes */
for(int j=0; j < n; j++) {
if(j == x)
continue;
/* Busy wait while Ti is choosing a ticket */
while(choosing[j] != false)
;
/* Busy wait while current ticket value is lowest */
while(tickets[j] != 0 && tickets[j] < tickets[x])
;
}
/* In case of tie, favor smaller process number */
if(tickets[i] == tickets[x] && i < x) {
/* Busy wait until Ti exits critical section*/
while(tickets[i] != 0);
}
tickets[x] = 0;
/* exitMutualExclusion() */
}
	
/* Critical section code */
		// In critica l section
		printf("Thread %d - Enter critical section\n",x);
		count = count + 1;
		printf("Thread %d - EXIT critical section -- %d\n",x, count);

	}
}




int	main(void) {
	srand(time(NULL));
	pthread_t t1[n];
	for(int i=0;i<n;i++)
	{
	if( pthread_create(&t1[i], NULL, thread1, (void*) (long)i) != 0) {
		printf("Thread %d not created. Quitting.\n",i+1);
		exit(0);
	}
}
for(int i=0;i<n;i++)
{
	if(pthread_join(t1[i], NULL) != 0) {
		printf("Thread %d (exit) ",i+1);
		exit(0);
	}
}
	return 0;
}
