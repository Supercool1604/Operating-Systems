#include<bits/stdc++.h> 
#include<set>
using namespace std; 
  int capacity,processes;
vector< pair<int,int> > v;
int num_page_refrence = 0;
int value1[50][500]={0};
bool is_Present1[500][50]={false};
vector< pair<int,int> > memory;
pair<int,int> Memory[500];
int pageFault[50]={0};
int hit[50]={0};
int num_refrence[50]={0};
int Page_allocated[50] = {0};
int start_idx[50];
int end_idx[50];



void MFU_Local(pair<int,int> p, int i)
{
    num_refrence[p.first]++;
    if(!is_Present1[p.second][p.first])
    {
             cout<<"Page fault occurs for page "<<p.second<<" of Process "<<p.first <<endl;
    
        cout<<endl;
        int f=0;
        for(int i = start_idx[p.first];i<=end_idx[p.first];i++){
            if(Memory[i].first == -1 && Memory[i].second == -1){
                Memory[i].first = p.first;
                Memory[i].second = p.second;
                is_Present1[p.second][p.first] = true;
                f=1;
                break;
            }   
        }
        if(!f){
            int mfu = 0,val=0; 
            for (int l=start_idx[p.first];l<=end_idx[p.first];l++) 
            { 
                if (value1[Memory[l].first][Memory[l].second] < mfu) 
                { 
                    mfu = value1[Memory[l].first][Memory[l].second]; 
                    val = l; 
                } 
            }
            is_Present1[Memory[val].second][Memory[val].first]=false;
            Memory[val] = p;
            is_Present1[Memory[val].second][Memory[val].first] = true;
            
        }   
        
        pageFault[p.first]++;

        cout<<"Page table after page fault : "<<endl;
        for(int i=0;i<capacity;i++){
            if(Memory[i].first!=-1 && Memory[i].second!=-1)
                cout<<"Process: "<<Memory[i].first<<", Page: "<<Memory[i].second<<endl;
       }
    }
    else{
        hit[p.first]++;
         cout<<"Requested page: "<<p.second<<" of process "<<p.first<<endl;
        cout<<"Already present in memory "<<endl;
     }
    value1[p.first][p.second] = i;
  cout<<"----------------------------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------------------------"<<endl;
  
}


int main() 
{ 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    // int capacity;
    // freopen("input.txt","r")
    cin>>capacity;
    // int processes;
    cin>>processes;
    int proc_pages[processes]={0};
  /*  for(int i=0;i<processes;i++)
    {
        cin>>proc_pages[i];
    }
*/
//proc_pages = numberOfPages
    // capacity  = P
    // processes = N
    // v = page_refrence 

    // cin>>capacity>>processes;
    // int proc_pages[processes+2]={0}; 
    for(int i=0;i<processes;i++){
        cin>>proc_pages[i];
        Page_allocated[i] = 1;
    }
    for(;;)
    {
        int a,b;
        cin>>a>>b;

        if(a==-1&&b==-1)
            break;
        else
        {
            v.push_back(make_pair(a,b));
            num_page_refrence++;
        }
    }



int h=0;
    int pg = capacity-processes;
    while(pg>0){
        Page_allocated[h%processes]++;
        h++;
        pg--;
    }
    for(int i=0;i<processes;i++){
        if(i==0)
            start_idx[i] = 0;
        else
            start_idx[i] = end_idx[i-1]+1;
        end_idx[i] = start_idx[i] + Page_allocated[i] -1;
    }
    for(int i=0;i<capacity;i++){
        Memory[i].first = -1;
        Memory[i].second = -1;
    }
    cout<<endl;
    cout<<"For local page replacement MFU: "<<endl<<endl;
    for(int i=0;i<num_page_refrence;i++)
    {
        pair<int,int> p;
        p = v[i];
        MFU_Local(p,i);
    }
    int total_hit=0;
    int total_ref=0;
    cout<<endl;
    for(int i=0;i<processes;i++){
        cout<<"hit ratio of process "<<(i)<<" is: "<<float(float(hit[i])/num_refrence[i])<<endl;
        total_hit+=hit[i];
        total_ref+=num_refrence[i];
    }
    cout<<endl;
    cout<<"overall hit ratio is: "<<float(float(total_hit)/total_ref)<<endl;
    cout<<"----------------------------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------------------------"<<endl;
    return 0;











} 














