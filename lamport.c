#include <stdio.h> 
#include <unistd.h>
#include <string.h> 
#include <pthread.h>
  

 #define numberOfThreads 15 
#define temp __sync_synchronize() 
 int tickets[numberOfThreads]; 

 int choosing[numberOfThreads]; 
  

int resource; 
  
void lock(int thread) 
{ 
 // for(int t=0;t<5;t++)
{

    choosing[thread] = 1; 
  
    temp; 
  
    int max_ticket = 0; 
  
    for (int i = 0; i < numberOfThreads; ++i) { 
  
        int ticket = tickets[i]; 
        max_ticket = ticket > max_ticket ? ticket : max_ticket; 
    } 
  
    tickets[thread] = max_ticket + 1; 
  
    temp; 
    choosing[thread] = 0; 
    temp; 
  
    for (int other = 0; other < numberOfThreads; ++other) { 
  
        while (choosing[other]) { 
        } 
  
        temp; 
  
        while (tickets[other] != 0 && (tickets[other] < tickets[thread]|| (tickets[other] == tickets[thread] && other < thread))) { 
        } 
    } 
}
} 
  
void unlock(int thread) 
{ 
  
    temp; 
    tickets[thread] = 0; 
} 
  
void use_resource(int thread) 
{ 


    if (resource != 0) { 
        printf("Resource was acquired by %d, but is still in-use by %d!\n", 
               thread, resource); 
    } 
  
    resource = thread; 
    printf("%d using thread \n", thread); 
for(int o =0;o<5;o++)
    printf("%d tickets with thread %d \n",tickets[o],o);
    temp; 
    sleep(2); 
    resource = 0; 
} 
 
void* thread_body(void* arg) 
{ 
  
  for(int p = 0 ; p < 5;p++){
    long thread = (long)arg; 
    lock(thread); 
    use_resource(thread); 
    unlock(thread); 
}
    return NULL; 
} 
  
int main(int argc, char** argv) 
{ 
    memset((void*)tickets, 0, sizeof(tickets)); 
    memset((void*)choosing, 0, sizeof(choosing)); 
    resource = 0; 
  
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;
    pthread_t thread5;
       
  // creating 5 threads..
        pthread_create(&thread1, NULL, &thread_body, (void*)(1)); 
        pthread_create(&thread2, NULL, &thread_body, (void*)(2)); 
        pthread_create(&thread3, NULL, &thread_body, (void*)(3)); 
        pthread_create(&thread4, NULL, &thread_body, (void*)(4)); 
        pthread_create(&thread5, NULL, &thread_body, (void*)(5)); 

  
        pthread_join(thread1, NULL); 
        pthread_join(thread2, NULL); 
        pthread_join(thread3, NULL); 
        pthread_join(thread4, NULL); 
        pthread_join(thread5, NULL); 

    
  
    return 0; 
} 
