#include <bits/stdc++.h> 
using namespace std; 
bool search(int key, vector<int>& pagesInMem) 
{ 
    for (int i = 0; i < pagesInMem.size(); i++) 
        if (pagesInMem[i] == key) 
            return true; 
    return false; 
} 
  
int predict(int pages[], vector<int>& pagesInMem, int n, int index) 
{ 
    int res = -1, farthest = index; 
    for (int i = 0; i < pagesInMem.size(); i++) { 
        int j; 
        for (j = index; j < n; j++) { 
            if (pagesInMem[i] == pages[j]) { 
                if (j > farthest) { 
                    farthest = j; 
                    res = i; 
                } 
                break; 
            } 
        } 
        if (j == n) 
            return i; 
    } 
    return (res == -1) ? 0 : res; 
} 
  
void optimalPage(string pages, int n, int capacity) 
{ 
    vector<int> pagesInMem; 
  
    int hit = 0; 
    for (int i = 0; i < n; i++) { 
        if (search(pages[i], pagesInMem)) { 
            hit++; 
            continue; 
        } 
        if (pagesInMem.size() < capacity) 
            pagesInMem.push_back(pages[i]); 
        else { 
            int j = predict(pages, pagesInMem, n, i + 1); 
            pagesInMem[j] = pages[i]; 
        } 

        for(int j=0;j<pagesInMem.size();++i)
    {
        cout<<pagesInMem[i]<<endl;
    }
    
    cout<<"----------------------------------------"<<endl;
    cout<<"----------------------------------------"<<endl;

    } 


    // cout << "No. of hits = " << hit << endl; 
    // cout << "No. of misses = " << n - hit << endl; 
} 
int main() 
{ 
    string pages;
    cin>>pages;
    int n = pages.size(); 
    int capacity;
    cin>>capacity; 
    optimalPage(pages, n, capacity); 
    return 0; 
} 