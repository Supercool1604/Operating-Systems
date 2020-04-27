/***************************    KABIR JUNEJA  -- 2017UCS0043    ******************************/


/*********************************  SYSTEM CALL TIME **********************************/


/********************************  ASSIGNMENT - 2 **************************************/






#include <sys/time.h> 
#include <unistd.h> 
#include <assert.h>
#include<stdio.h>



long nanosec(struct timeval t){ /* Calculate nanoseconds in a timeval structure */ 
	long output = (t.tv_sec*1000000+t.tv_usec)*1000;
  return output; 
}

int main(){ 
  int i,j,res; 
  long N_iterations=1000000; /* A million iterations */ 
  float avgTimeSysCall, avgTimeFuncCall;
   
  struct timeval start, end;

  /* Find average time for System call */ 
  res = gettimeofday(&start,NULL); 
  assert(res==0); 
  for (i=0;i<N_iterations; i++)
  { 
    j=getpid(); 
  } 
  res=gettimeofday(&end,NULL);   
//  assert(res==0); 
  avgTimeSysCall = (nanosec(end) - nanosec(start))/float(N_iterations);

  

  printf("Average time for System call getpid : %f\n",avgTimeSysCall); 
}
