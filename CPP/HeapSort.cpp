#include<bits/stdc++.h>
using namespace std;


void heapifyI(int a[], int n, int i)
{
    int tmp;
    int l = i*2+1;
    int r = i*2+2;
    if(l<n and a[l]>a[i])
    {
        tmp = a[i];
        a[i] = a[l];
        a[l] = tmp;
        heapifyI(a,n,l);
    }
    if(r<n and a[r]>a[i])
    {
        tmp = a[i];
        a[i] = a[r];
        a[r] = tmp;
        heapifyI(a,n,r);
    }
    return;
}

// For arranging the array in the form of a max-heap
void heapify(int a[], int n)
{
    for(int i=n/2;i>=0;i--)
    {
        heapifyI(a,n,i);
    }
    return;
}

void makeHeap(int a[], int n, int i)
{
    int l,r;
    l = 2*i+1;
    r = 2*i+2;
    if(l<n and a[l]>a[i])
    {
        swap(a[l],a[i]);
        makeHeap(a,n,l);
    }
    if(r<n and a[r]>a[i])
    {
        swap(a[r],a[i]);
        makeHeap(a,n,r);
    }
    return;
}

//Function for heapSort
void heapSort(int a[], int n)
{
    heapify(a,n);
    while(n>0)
    {
        swap(a[0],a[n-1]);
        n--;
        makeHeap(a,n,0);
    }
}
int main()
{
    int n;
    cin>>n;  
    int a[n];
    
    for(int i=0;i<n;i++)
    cin>>a[i];   
    
    heapSort(a,n);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    } 
    return 0;
}
