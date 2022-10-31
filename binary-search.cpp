#include <iostream>

using namespace std;

int cautare(int v[],int s,int d,int k)
{
    int m;
    if(s<=d)
    {
        m=(s+d)/2;
        if(v[m]==k)
            return 1;
        else
            if(v[m]<k)
            return cautare(v,m+1,d,k);
        else
            return cautare(v,s,m-1,k);
    }
    else
        return 0;
}
int main()
{
    int n,i,v[25000],a[200000],k,m;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
    cin>>m;
    for(i=1;i<=m;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
        cout<<cautare(v,1,n,a[i])<<" ";
    return 0;
}
