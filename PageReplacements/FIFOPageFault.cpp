#include<bits/stdc++.h> 
#include<set>
using namespace std; 
  

int pageFifoFaults(string pages, int n, int capacity) 
{ 
    

    set<char> hmap;
    set<char>:: iterator itr;
    set<char>:: iterator toBeRemoved;
    int pageFaults=0;
  
    queue<char> pageNum; 
  
    for(int i=0;i<n;i++)
    {
        pageNum.push(pages[i]);
    }


    for(int i=0;i<capacity;i++)
    {
        hmap.insert(pageNum.front());
        pageFaults++;
        pageNum.pop();

    }
    toBeRemoved = hmap.begin();
cout<<endl;
for(itr = hmap.begin();itr!=hmap.end();++itr)
    {
        cout<<*itr<<endl;
    }
    
    cout<<"----------------------------------------"<<endl;
    cout<<"----------------------------------------"<<endl;

/*    for(itr = hmap.begin();itr!=hmap.end();itr++)
    {
        cout<<*itr;
    }
*/
    for(int i=capacity;i<n;i++)
    {
        if(hmap.find(pageNum.front())!=hmap.end())
        {
          cout<<"Page "<< pageNum.front()<<" already exists"<<endl;
          pageNum.pop();

        }
        else
        {
            pageFaults++;
            hmap.erase(*toBeRemoved);
            hmap.insert(pageNum.front());
            toBeRemoved = hmap.begin();  
            pageNum.pop();

        }
    for(itr = hmap.begin();itr!=hmap.end();++itr)
    {
        cout<<*itr<<endl;
    }
    
    cout<<"----------------------------------------"<<endl;
    cout<<"----------------------------------------"<<endl;
    
    }


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
    string pages ;
    // freopen("input.txt","r")
    cin>>pages;

    int n = pages.size(); 
    int capacity ;
    cin>>capacity; 
    pageFifoFaults(pages, n, capacity); 
    return 0; 
} 