#include<bits/stdc++.h> 
#include<set>
using namespace std; 
  

void pageFifoFaults(int processes, int proc_pages[], vector<pair<int,int>>& v, int capacity) 
{ 
    
    int  hitRatio[processes]={0};
    float hitCalls[processes]={0};
    int hitRatioOverAll= 0;
    std::vector<pair<int,int>> hmap;
    // set<pair<int,int>> hmap;
    // set<pair<int,int>>:: iterator itr;
     vector<pair<int,int>>:: iterator toBeRemoved;
    int pageFaults=0;
  
    queue<pair<int,int>> pageNum; 
  
    for(int i=0;i<v.size();i++)
    {
        pageNum.push(v[i]);
    }


    for(int i=0;i<capacity;i++)
    {
        hmap.push_back(pageNum.front());
        pageFaults++;
        hitCalls[pageNum.front().first]++;
        cout<<"Page Fault, Process : "<<pageNum.front().first<<", Page : "<<pageNum.front().second <<endl;

        pageNum.pop();

    }
     toBeRemoved = hmap.begin();
cout<<endl;/*
for( itr = hmap.begin();itr!=hmap.end();++itr)
    {
        cout<<(*itr).second<<endl;
    }
    
    cout<<"----------------------------------------"<<endl;
    cout<<"----------------------------------------"<<endl;*/
for(int itr = 0;itr<hmap.size();++itr)
    {
        cout<<hmap[itr].second<<endl;
    }
    
    cout<<"----------------------------------------"<<endl;
    cout<<"----------------------------------------"<<endl;

/*    for(itr = hmap.begin();itr!=hmap.end();itr++)
    {
        cout<<*itr;
    }
*/

    
    for(int i=capacity;i<v.size();i++)
    {
        hitCalls[pageNum.front().first]++;
        if(find(hmap.begin(),hmap.end(),pageNum.front())!=hmap.end())
        {
          hitRatioOverAll++;
          hitRatio[pageNum.front().first]++;
          cout<<"Page "<< pageNum.front().second<<" of process "<<pageNum.front().first<<" already exists"<<endl;
          pageNum.pop();
        }
        else
        {
            pageFaults++;
            cout<<"Page Fault, Process : "<<pageNum.front().first<<", Page : "<<pageNum.front().second <<endl;

            hmap.erase(toBeRemoved);
           // hmap.erase(hmap.begin());
            hmap.insert(hmap.begin(),pageNum.front());
             toBeRemoved ++;  
            pageNum.pop();

        }
        for(int itr = 0;itr<hmap.size();++itr)
    {
        cout<<hmap[itr].second<<endl;
    }
    
    cout<<"----------------------------------------"<<endl;
    cout<<"----------------------------------------"<<endl;
}
  cout<<"OverAll hit ratio : "<<hitRatioOverAll<<"/"<<v.size()<<" = "<< float(float(hitRatioOverAll)/v.size()) <<endl;
    for(int i=0;i<processes;i++)
    {

        cout<<"Hit ratio for process "<<i<<" : "<<hitRatio[i]/hitCalls[i]<<endl;
    }
/*    for(itr = hmap.begin();itr!=hmap.end();++itr)
    {
        cout<<(*itr).second<<endl;
    }
    
    cout<<"----------------------------------------"<<endl;
    cout<<"----------------------------------------"<<endl;
    
    }
*/

/*

    int page_faults = 0; 
    for (int i=0; i<n; i++) 
    { 
        if (s.size() < capacity) 
        { 
            if (s.find(pages[i])==s.end()) 
            { 
                s.insert(pages[i]); 
                page_faults++; 
                indexes.push(pages[i]); 
            } 
        } 
        else
        { 
            if (s.find(pages[i]) == s.end()) 
            { 
                int val = indexes.front(); 
  
                indexes.pop(); 
  
                s.erase(val); 
                s.insert(pages[i]); 
                indexes.push(pages[i]); 
                page_faults++; 
            } 
        } 
    } 
  
    return page_faults;
    */ 
  

} 
  
// Driver code 
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
    pageFifoFaults(processes, proc_pages, v, capacity); 
    return 0; 
} 