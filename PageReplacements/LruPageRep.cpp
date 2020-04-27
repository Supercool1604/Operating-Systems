#include<bits/stdc++.h> 
#include<set>
using namespace std; 
  

int pageLruFaults(string pages, int n, int capacity) 
{ 
    

    set<char> pageSet;
    set<char>:: iterator itr;
    set<char>:: iterator toBeRemoved;
    unordered_map<char,int> hmap;
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


for (int i=0; i<n; i++) 
    { 
        
        if (pageSet.size() < capacity) 
        { 
            
            if (pageSet.find(pages[i])==pageSet.end()) 
            { 
                pageSet.insert(pages[i]); 
  
                pageFaults++; 
            } 

            hmap[pages[i]] = i; 
        } 
        else
        { 
            if (pageSet.find(pages[i]) == pageSet.end()) 
            { 
                int lru = INT_MAX, val; 
                for (auto it=pageSet.begin(); it!=pageSet.end(); it++) 
                { 
                    if (hmap[*it] < lru) 
                    { 
                        lru = hmap[*it]; 
                        val = *it; 
                    } 
                } 
                pageSet.erase(val); 
                pageSet.insert(pages[i]); 
  
                pageFaults++; 
            } 
            hmap[pages[i]] = i; 
        } 
for(itr = pageSet.begin();itr!=pageSet.end();++itr)
    {
        cout<<*itr<<endl;
    }
    
    cout<<"----------------------------------------"<<endl;
    cout<<"----------------------------------------"<<endl;



    } 

















} 
  

int main() 
{ 
    string pages ;
    // freopen("input.txt","r")
    cin>>pages;

    int n = pages.size(); 
    int capacity ;
    cin>>capacity; 
    pageLruFaults(pages, n, capacity); 
    return 0; 
} 