/***************************    KABIR JUNEJA   2017UCS0043    ******************************/


/********************************* PREEMPTIVE PRIORITY  IMPLEMENTATION  **********************************/


#include<bits/stdc++.h> 
#define ll long long int
using namespace std; 



void premPri(vector<pair<ll,ll>> proc_arr ,ll proc_burs[] , ll proc_prio[], int n , ll turn_around_time[] , ll response_time[] , ll waiting_time[]) 
{ 
    ll rem_time[n];
    for(ll i =0;i<n;i++)
    {
        rem_time[i] = proc_burs[i];
    }

ll t =0 ;
bool proc_executed[n] = {false};
   cout<< "Order in which processes gets executed \n"; 
 ll idx =-1;
 bool flag = false;
 ll k=0;
while(k<n)
    {
    ll j=0;
    ll min = INT_MAX;
    while(proc_arr[j].first<=t && min>proc_prio[j] )
    {
        if(proc_executed[j]==false)
        {
        min  = proc_prio[j];
        idx  = j;
    
        flag = true;
    }
        j++;

}

    if(flag)
    {


        if(response_time[idx] == -2 )
{
    if( t - proc_arr[idx].first > 0)
    response_time[idx] = t - proc_arr[idx].first;
else response_time[idx ] = 0;
}


        // proc_executed[idx] = true;
        t++;
        rem_time[idx]--;
         // t+=proc_burs[idx];








        if(rem_time[idx]==0)
        { 
            proc_executed[idx] = true;
        k++;
        if(t-proc_arr[idx].first >0)
        turn_around_time[idx] = t - proc_arr[idx].first ;
        else turn_around_time[idx] = proc_burs[idx];

        if(turn_around_time[idx] - proc_burs[idx]>0)
        waiting_time[idx] = turn_around_time[idx] - proc_burs[idx];
        else waiting_time[idx] = 0;
        flag = false;
       
        cout<<idx<< " with Turn around time : "<<turn_around_time[idx]<<" and response time : "<<response_time[idx] << " and waiting time  :  "<<waiting_time[idx]<< endl;
    }}
    else
    {
        
        t++;
    }
}
      float avg_tn = 0;
float avg_res = 0;
float avg_wt = 0;
for(ll i=0;i<n;i++)
{
    avg_res += response_time[i];
    avg_tn += turn_around_time[i];
    avg_wt += waiting_time[i];
}
        cout<<" average turn around time : " << avg_tn / (float)n <<" average response time : "<<avg_res / (float)n << " average waiting time : "<<avg_wt / (float)n<<endl; 
    
    }   
 
 

  
int main() 
{ 

        freopen("input.dat","r",stdin);

   int n;
    cin>>n;

    ll proc_burst[n+2], proc_pri[n+3];
    vector<pair<ll,ll>> proc_arr;
    for(ll i=0;i<n;i++)
    {
        int a;
        cin >> a >> proc_burst[i] >> proc_pri[i];
        proc_arr.push_back(make_pair(a,i));
    }

    ll turn_around_time[n+2];
    ll response_time[n+2]  ;
    for( ll i=0;i<n;i++)
    {
        response_time[i]=-2;
    }
    ll waiting_time[n+2];
    sort(proc_arr.begin(),proc_arr.end());


    ll proc_burs[n], proc_prio[n];
    for ( ll i=0; i<n;i++)
    {
        proc_burs[i] = proc_burst[proc_arr[i].second];
        proc_prio[i] = proc_pri[proc_arr[i].second];
           
    }
     ll quantum = 0;
 cout<<"Enter Quantum value : " ;

    cin>>quantum;
    ll temp;
    cout<<"Enter no. of priority levels : ";

    cin>>temp;
    // Process proc[]; 
    // int n = sizeof proc / sizeof proc[0]; 
    // for( ll i=0;i<n;i++)
    // {
    //     cout<<proc_burs[i]<<" "<<proc_prio[i]<<endl;
    // }
    premPri(proc_arr , proc_burs, proc_prio, n, turn_around_time ,response_time, waiting_time); 
    return 0; 
} 