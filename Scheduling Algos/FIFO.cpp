/***************************    KABIR JUNEJA   2017UCS0043    ******************************/




/*********************************  FIFO IMPLEMENTATION  **********************************/


#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{

	// freopen("input.dat","r",stdin);

	ll n;
	cin>>n;
	ll arr[n][3];
	
	// SINCE IT IS FIFO, NO PRIORITY IS REQUIRED, STILL INPUTTING PRIORITY BUT IS OF NO USE
	// ONLY THE ARRIVAL TIME AND CPU BURST TIME OF THE PROCESSES
	
	for ( ll i=0;i<n;i++)
	{
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}
	  ll quantum = 0;
 cout<<"Enter Quantum value : " ;

    cin>>quantum;
    ll temp;
    cout<<"Enter no. of priority levels : ";

    cin>>temp;
	ll sum=0;
	ll turn_around_time[n];
	// ARRAY FOR STORING INDIVIDUAL TURN AROUND TIME OF PROCESSES
	
	ll response_time[n];
	// ARRAY FOR STORING INDIVIDUAL RESPONSE TIME OF PROCESSES
	// IN FIFO WAITING TIME AND RESPONSE TIME REMAIN SAME, THEREFORE NO NEED TO ALLOT SPACE FOR WAITING TIME.

	response_time[0]=0;
	for(ll i=0;i<n;i++)
	{
		sum+=arr[i][1];
		if(arr[i][0]>sum)
		{
			turn_around_time[i]=arr[i][1];
			response_time[i]=0;
		}
		else 
		{
			turn_around_time[i] = sum - arr[i][0];
			response_time[i] = sum - arr[i][0]-arr[i][1];
		}
	}

	//Indivisual process response and turn around time -->
	for(ll i=0;i<n;i++)
	{
		cout<<"Turn Around time and Response time of process "<<i+1<<" are "<<turn_around_time[i]<<" and "<<response_time[i]<<endl;
	}



	float avg_tn = 0;
	float avg_res = 0;
	for(ll i=0;i<n;i++)
	{
		avg_tn += turn_around_time[i];
		avg_res += response_time[i];
	}



	avg_tn= (float)avg_tn/n;
	avg_res= (float)avg_res/n;
	


	cout<<"Average Turn Around time is : "<<avg_tn<<endl;
	
	cout<<"Average Response time is : "<<avg_res<<endl;
	
}


/********************************                                             *****************************/
