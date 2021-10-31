#include <bits/stdc++.h>

using namespace std;

// Checking whether a map has all the values equal to 0 in its key-value mapping
bool isEmpty(map<char,int>m)
{
    for(auto y=m.begin();y!=m.end();y++)
    {
        if(y->second==0)
        continue;
        
        else
        return false;
    }
    
    return true;
}


void perm(map<char,int>freq,string r="")
{
    // Checking if all the letters have been exhausted and no further Permutations can be formed
    if(isEmpty(freq))
    {
        cout<<r;
        return;
    }
    
    // Traversing through all the letters of the string and then Recursively Generating the Permutations 
    for(auto p=freq.begin();p!=freq.end();p++)
    {
        // If the Present Letter has already been exhausted, then do not add it and skip this specific iteration of the loop
        if(p->second==0)
        continue;
        

        // Making a duplicate Map containing the frequency of all the letters as it is in the present map but the particular character,pointed in this specific Iteration of the Loop has Frequency less by 1 than found in the original map 
        map<char,int>temp;
        
        for(auto y=freq.begin();y!=freq.end();y++)
        temp[y->first]=y->second;
        
        temp[p->first]--;


        // Recursively calling the function with the newly formed map
        perm(temp,r+p->first);
    }
}

// Driver Code to test the Function
int main() {

    string s="abaaa";
    map<char,int>m;
    
    for(char g:s)
    m[g]++;
    
    perm(m);

    return 0;
}
