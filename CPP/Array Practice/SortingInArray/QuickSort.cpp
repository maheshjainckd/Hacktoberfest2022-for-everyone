#include<bits/stdc++.h>
using namespace std;

int pivot(vector<int> &v,int low,int high){
    int mid = low + (high-low)/2;
    
    int i = low, j = high;
    while (true)
    {
        while(v[i] < mid){
            i++;
        }
        while (v[j] > mid)
        {
            j--;
        }

        if(i >= j){
            return j;
        }
        swap(v[i],v[j]);
    }
    
}


void quicksort(vector<int> &v,int low,int high){
   if(low > high){
       return;
   }
   int p = pivot(v,low,high);
   quicksort(v,low,p-1);
   quicksort(v,p+1,high);
}



int main(){
    vector<int> v = {1,8,4,6,3,9};
    quicksort(v,0,v.size()-1);
    for(int i : v){
        cout<<i<<" ";
    }
}