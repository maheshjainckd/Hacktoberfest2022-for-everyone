#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

// // Zeros ONES ANd Twos

// void ZeroOneTwo(int a[],int n)
// {
//     int l=0,mid=0,h=n-1;
//     while(mid<=h)
//     {
//         if(a[mid]==0)
//         {
//             swap(a[l],a[mid]);
//             l++;
//             mid++;
//         }
//         else if(a[mid]==1)
//             mid++;
//         else
//         {
//             swap(a[mid],a[h]);
//             h--;
//         }
//     }
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     ZeroOneTwo(a,n);
//     for(int x:a)
//         cout<<x<<" ";
// }

// partition around pivot

// void pivotPartition(int a[],int n,int p)
// {
//     int l=0,mid=0,h=n-1;
//     while(mid<=h)
//     {
//         if(a[mid]<p)
//         {
//             swap(a[l],a[mid]);
//             l++;
//             mid++;
//         }
//         else if(a[mid]==p)
//             mid++;
//         else
//         {
//             swap(a[mid],a[h]);
//             h--;
//         }
//     }
// }
// int main()
// {
//     int n,p;
//     cin>>n>>p;
//     int a[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     pivotPartition(a,n,p);
//     for(int x:a)
//         cout<<x<<" ";
// }

// partition around a range

void pivotPartitionInRange(int a[],int n,int x,int y)
{
    int l=0,mid=0,h=n-1;
    while(mid<=h)
    {
        if(a[mid]<x)
        {
            swap(a[l],a[mid]);
            l++;
            mid++;
        }
        else if(a[mid]>=x && a[mid]<=y)
            mid++;
        else
        {
            swap(a[mid],a[h]);
            h--;
        }
    }
}
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    pivotPartitionInRange(a,n,x,y);
    for(int x:a)
        cout<<x<<" ";
}
