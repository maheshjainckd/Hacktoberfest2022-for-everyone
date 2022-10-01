/*
Heap Sort arranges an array in a binary tree, Make it a Max Heap and then store larger values from end to make a sorted array.
*/

#include<bits/stdc++.h>
using namespace std;

// heapify function to swap values to make a max heap binary tree (Tree in which the root element will be larger than child nodes).
void heapify(int ar[],int n,int i){
    int largest=i;
    // Left and right child of tree when arranged as tree from array
    int left=2*i+1;
    int right=2*i+2;
    if(ar[left]>ar[largest] && left<n){
        largest=left;
    }
    if(ar[right]>ar[largest] && right<n){
        largest=right;
    }
    // Swap elements if root is smaller and call heapify to make max heap tree
    if(largest!=i){
        swap(ar[i],ar[largest]);
        heapify(ar,n,largest);
    }
}

// Heap Sort Logic
void heap_sort(int ar[],int n){
    // Arranging array in a max heap binary tree format
    for(int i=n/2;i>=0;--i){
        heapify(ar,n,i);
    }

    // Swap 0th element to last element as 0th will be largest value according to max heap tree and run heapify again except on swapped element, Hence array will be sorted. 
    for(int i=n-1;i>=0;--i){
        swap(ar[0],ar[i]);
        heapify(ar,i,0);
    }
}

//Sorting Algorithm Boiler code to take input of array, call the sorting function and print the array.
int main(){
    cout<<"Enter size of array : ";
    int size;
    cin>>size;
    int ar[size];
    for(int i=0;i<size;i++){
        cout<<"Enter element "<<(i+1)<<": ";
        cin>>ar[i];
    }    
    cout<<"Before Sort : "<<endl;
    for(int i=0;i<size;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    heap_sort(ar,size);
    cout<<"After sort : "<<endl;
    for(int i=0;i<size;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
return 0;
}

/*
## Run Code
https://ide.geeksforgeeks.org/82b72ddc-f473-422d-b041-155c6f1d8fd1

## Complexities
### Time complexity   : 
Best Case  : O(n)  
Worst Case : O(n logn) 
### Space complexity  : 
O(1)
*/