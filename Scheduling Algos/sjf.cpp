/***************************    KABIR JUNEJA   2017UCS0043    ******************************/


/*********************************  SJF(SHORTEST JOB FIRST)  IMPLEMENTATION  **********************************/


#include<bits/stdc++.h> 
#define ll long long int
using namespace std; 


void SJF(vector<pair<ll,ll>> proc_arr ,ll proc_burs[] , int n , ll turn_around_time[] , ll response_time[]) 
{ 
ll t =0 ;
bool proc_executed[n] = {false};
   cout<< "Order in which processes gets executed \n"; 
 ll idx =-1;
 bool flag = false;
for( ll i=0;i<n;i++)
{   
    
    ll j=0;
    ll min = INT_MAX;
    while(proc_arr[j].first<=t && min>proc_burs[j] )
    {
        if(proc_executed[j]==false)
        {
        min  = proc_burs[j];
        idx  = j;
    
        flag = true;
    }
        j++;

}
    if(flag)
    {
        proc_executed[idx] = true;
         t+=proc_burs[idx];
        if(t-proc_arr[idx].first >0)
        turn_around_time[idx] = t - proc_arr[idx].first ;
        else turn_around_time[idx] = proc_burs[idx];

        if(turn_around_time[idx] - proc_burs[idx]>0)
        response_time[idx] = turn_around_time[idx] - proc_burs[idx];
        else response_time[idx] = 0;
        flag = false;
       
        cout<<idx<< " with Turn around time : "<<turn_around_time[idx]<<" and response time : "<<response_time[idx] <<endl;
    }
    else
    {
        i--;
        t++;
    }
}
    float avg_tn = 0;
float avg_res = 0;
for(ll i=0;i<n;i++)
{
    avg_res += response_time[i];
    avg_tn += turn_around_time[i];
}
        cout<<" average turn around time : " << avg_tn / (float)n <<" average response time : "<<avg_res / (float)n <<endl; 
    
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
    ll response_time[n+2];
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
    SJF(proc_arr , proc_burs, n, turn_around_time ,response_time); 
    return 0; 
} 