#include <bits/stdc++.h>
using namespace std;
//Dev Wadhwa
int main()
{
    cout<<"Maximum Area Histogram"<<endl;
    cout<<"Enter number of elements: ";
    int n;
    cin>>n;
    cout<<"Enter elements:"<<endl;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    stack<pair<int,int>> stk1;
    stack<pair<int,int>> stk2;
    pair<int,int> p;
    vector<int> left;
    vector<int> right;
    for(int i=0;i<n;i++)
    {
        if(stk1.empty())
        {
            left.push_back(-1);
        }
        else
        {
            while(stk1.empty()==false && stk1.top().first>=arr[i])
            {
                stk1.pop();
            }
            if(stk1.empty()) left.push_back(-1);
            else left.push_back(stk1.top().second);
        }
        p.first=arr[i];
        p.second=i;
        stk1.push(p);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(stk2.empty())
        {
            right.push_back(n);
        }
        else
        {
            while(stk2.empty()==false && stk2.top().first>=arr[i])
            {
                stk2.pop();
            }
            if(stk2.empty()) right.push_back(n);
            else right.push_back(stk2.top().second);
        }
        p.first=arr[i];
        p.second=i;
        stk2.push(p);
    }
    reverse(right.begin(),right.end());
    vector<int> width;
    for(int i=0;i<n;i++)
    {
        width.push_back(right[i]-left[i]-1);
    }
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]*width[i]>max) max=arr[i]*width[i];
    }
    cout<<"\nElements in array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nNearest Smallest to Left array (Indices): ";
    for(int i=0;i<n;i++)
    {
        cout<<left[i]<<" ";
    }
    cout<<"\nNearest Smallest to Right array (Indices): ";
    for(int i=0;i<n;i++)
    {
        cout<<right[i]<<" ";
    }
    cout<<"\nMax area of histogram: "<<max;
    return 0;
}
