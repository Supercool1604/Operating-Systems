

/***************************    KABIR JUNEJA  -- 2017UCS0043    ******************************/


/*********************************  CONTEXT SWITCHING  **********************************/


/********************************  ASSIGNMENT - 2 **************************************/





#include <bits/stdc++.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
#include <string.h>
#include <linux/unistd.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include<sys/wait.h>
#include<bits/syscall.h>
#define ll  int
#define sys_pid __NR_getpid
using namespace std;
pid_t getpid( )
{
    return syscall( sys_pid );
}

int main()
{
// FIRST OF ALL , WE NEED TO SET A SINGLE CPU FOR CONTEXT SWITCHING 

    cpu_set_t set;
    struct sched_param prio_param;
    int prio_max;

    CPU_ZERO( &set );
    CPU_SET( 0, &set );                         // SETTING CPU

    memset(&prio_param, 0 , sizeof(struct sched_param));

    if (sched_setaffinity( getpid(), sizeof( cpu_set_t ), &set ))
    {
        cout<<( "sched_setaffinity" );
                exit(8);
    }

    if( (prio_max = sched_get_priority_max(SCHED_FIFO)) < 0 )
    {
                cout<<("sched_get_priority_max");
        }

    prio_param.sched_priority = prio_max;
    if( sched_setscheduler(getpid(),SCHED_FIFO,&prio_param) < 0 )
    {
                cout<<("sched_setscheduler");
                exit(8);
    }



    ll  out=-1;
    ll   firstpipe[2];
    ll    secondpipe[2];
    ll     timepipe[2];
    ll      temp;
    char    fromParent[] = "Checking 123 123\n";
    char    fromChild[] = "Checking again 123 123\n";
    char    read_temp[80];
    char    fromChild_temp[80];
    ll     i=0;
    struct  timeval start,end;

    // Create a first pipe
        if (pipe(firstpipe) == -1) 
    {
            fprintf(stderr, "ERROR\n");
            return 0;
    }

    // Create a time pipe which will share in order to show time spend between processes
        if (pipe(timepipe) == -1) 
    {
            fprintf(stderr, "ERROR\n");
            return 0;
    }

        // create a  Second pipe
        if (pipe(secondpipe) == -1) 
    {
            fprintf(stderr, "ERROR\n");
            return 0;
    }


    out = fork(); 
    // CREATING TWO PROCESSES!!!


    if(out==-1)
        cout<<("fork");

    else if(out==0)
    {
        ll n=-1;


        // IF YOU WANT TO PRINT PROCESS ID OF CHILD , UNCOMMENT BELOW LINE
        // cout<<("Child's Process ID \n")<<getpid()<<endl;

        for(n=0;n<15;n++)
        {
                    temp = read(firstpipe[0], read_temp , sizeof(read_temp ));
                    cout<<"Received fromParent: "<< read_temp <<endl;
                    write(secondpipe[1], fromChild, strlen(fromChild)+1);
        }
        gettimeofday(&end,0);
                n = sizeof(struct timeval);

        if( write(timepipe[1],&end,sizeof(struct timeval)) != n )
        {
                fprintf(stderr, "child: Failed to write in time pipe\n");
                exit(8);
        }
    }


    else
    {
        double contextSwitchTime;
        ll n=-1;

        // IF YOU WANT TO PRINT PROCESS ID OF PARENT , UNCOMMENT BELOW LINE
        // cout<<"Parent's Process ID "<<getpid()<<endl;

        gettimeofday(&start,0);
               

        for(n=0;n<15;n++)
        {
            write(firstpipe[1], fromParent, strlen(fromParent)+1);

            read(secondpipe[0], fromChild_temp , sizeof(fromChild_temp ));
                    cout<<"Received from Child: "<< fromChild_temp <<endl;
        }

        n = sizeof(struct timeval);
        if( read(timepipe[0],&end,sizeof(struct timeval)) != n )
        {
            fprintf(stderr, "Failed to read from time pipe\n");
            exit(8);
        }

        wait(NULL);
        contextSwitchTime = ((end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec))/1000.0;
        cout<< "Context switch time between two processes: "<< contextSwitchTime/(30);


    }   

    return 0;
}
