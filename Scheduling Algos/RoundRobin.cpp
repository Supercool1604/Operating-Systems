/***************************    KABIR JUNEJA   2017UCS0043    ******************************/


/*********************************  ROUND ROBIN  IMPLEMENTATION  **********************************/







#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void roundRobin(vector<pair<ll,ll>> proc_arr ,ll proc_burs[] , ll proc_prio[], int n , ll turn_around_time[] , ll response_time[] , ll waiting_time[], ll quantum)
{
	queue<int> q;
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
 ll i=0;
 bool temp = false;
while(k<n)
{


 while(proc_arr[i].first <= t && i<n)
 {
  	q.push(proc_arr[i].second);
 	i++;
 	flag = true;
 	// temp = true;
 }



		if(temp == true)
	{
		q.push(proc_arr[idx].second);

	}



if(flag)
{
	idx = q.front();
	q.pop();

if(response_time[idx] == -2 )
{
    if( t - proc_arr[idx].first > 0)
    response_time[idx] = t - proc_arr[idx].first;
else response_time[idx ] = 0;
}


        // proc_executed[idx] = true;
        
        if(rem_time[idx]>quantum)
        {
        rem_time[idx]-=quantum;
  		t+=quantum;
  		temp = true;
  		}  
    else {

    	t+=rem_time[idx];
    	rem_time[idx] = 0 ;
    	temp = false ; 
    	proc_executed[idx] = true;
    	k++;
         // t+=proc_burs[idx];
    	}








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
    }

}
    else
    {
        
        t++;
    }









}



}










int main() 
{ 

		freopen("input.dat","r",stdin);

   int n;
    cin>>n;
    ll quantum = 0;

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
    roundRobin(proc_arr , proc_burs, proc_prio, n, turn_around_time ,response_time, waiting_time , quantum); 
    return 0; 
} 