#include<bits/stdc++.h> 
#include<set>
using namespace std; 
  


void pageLruFaults(int processes, int proc_pages[], vector<pair<int,int>>& v, int capacity) 
{ 
    
    int  hitRatio[processes]={0};
    float hitCalls[processes]={0};
    int hitRatioOverAll= 0;
    vector<pair<int,int>>  pageSet;
    vector<pair<int,int>> :: iterator itr;
    vector<pair<int,int>> :: iterator toBeRemoved;
    map<pair<int,int>,int> hmap;
    int pageFaults=0;
  
 /*   queue<char> pageNum; 
  
    for(int i=0;i<n;i++)
    {
        pageNum.push(pages[i]);
    }


    for(int i=0;i<capacity;i++)
    {
        pageSet.insert(pageNum.front());
        pageFaults++;
        pageNum.pop();

    }
    toBeRemoved = pageSet.begin();
cout<<endl;
for(itr = pageSet.begin();itr!=pageSet.end();++itr)
    {
        cout<<*itr<<endl;
    }
    
    cout<<"----------------------------------------"<<endl;
    cout<<"----------------------------------------"<<endl;

/*    for(itr = pageSet.begin();itr!=pageSet.end();itr++)
    {
        cout<<*itr;
    }
*/
    /*
    for(int i=capacity;i<n;i++)
    {
        if(pageSet.find(pageNum.front())!=pageSet.end())
        {
          cout<<"Page "<< pageNum.front()<<" already exists"<<endl;
          pageNum.pop();

        }
        else
        {
            pageFaults++;
            pageSet.erase(*toBeRemoved);
            pageSet.insert(pageNum.front());
            toBeRemoved = pageSet.begin();  
            pageNum.pop();

        }
    for(itr = pageSet.begin();itr!=pageSet.end();++itr)
    {
        cout<<*itr<<endl;
    }
    
    cout<<"----------------------------------------"<<endl;
    cout<<"----------------------------------------"<<endl;
    
    }




*/





cout<<endl;


for (int i=0; i<v.size(); i++) 
    { 
        
        if (pageSet.size() < capacity) 
        { 
            
            if (find(pageSet.begin(),pageSet.end(),v[i])==pageSet.end()) 
            { 
                pageSet.push_back(v[i]); 
                pageFaults++; 
                cout<<"Page Fault, Process : "<<v[i].first<<", Page : "<<v[i].second <<endl;

            } 

            hmap[v[i]] = i; 
        } 
        else
        { 
            int temp;
            if (find(pageSet.begin(),pageSet.end(),v[i]) == pageSet.end()) 
            { 
                int lru = INT_MAX, val; 
                for (int it=0; it<pageSet.size(); it++) 
                {
                    if (hmap[pageSet[it]] < lru) 
                    { 
                        lru = hmap[pageSet[it]]; 
                        // val = pageSet[it];
                        temp = it; 
                    } 

                   /* ******************************** */
                } 
                pageSet.erase(pageSet.begin() + temp); 
                pageSet.insert(pageSet.begin() + temp,v[i]); 
                cout<<"Page Fault, Process : "<<v[i].first<<", Page : "<<v[i].second <<endl;

                pageFaults++; 
            } 
            else
            cout<<"Page "<< v[i].second<<" of process "<<v[i].first<<" already exists"<<endl;
          
            hmap[v[i]] = i; 
        } 
for(int itr = 0;itr<pageSet.size();++itr)
    {
        cout<<pageSet[itr].second<<endl;
    }
    
    cout<<"----------------------------------------"<<endl;
    cout<<"----------------------------------------"<<endl;



    } 

















} 

int main() 
{ 
    int capacity;
    // freopen("input.txt","r")
    cin>>capacity;
    int processes;
    cin>>processes;
    int proc_pages[processes];
    for(int i=0;i<processes;i++)
    {
        cin>>proc_pages[i];
    }
        
    vector< pair<int,int> > v;
    for(;;)
    {
        int a,b;
        cin>>a>>b;

        if(a==-1&&b==-1)
            break;
        else
        {
            v.push_back(make_pair(a,b));
        }
    }
    pageLruFaults(processes, proc_pages, v, capacity); 
    return 0; 
} 














