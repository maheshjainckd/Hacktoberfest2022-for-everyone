#include<bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef long long int lli;

pair<int,VI> Sieve(int n)
{
    vector<bool> visited(n);
    VI primes;
    int count=0;
    for(lli i=2;i<=n;i++)
    {
        if(!visited[i])
        {
            count++;
            primes.push_back(i);
            for(lli j=i*i;j<=n;j+=i)
            {
                visited[j]=true;
            }
        }
        
    }
    return make_pair(count,primes);
}

int main()
{
    int n;
    cin>>n;
    pair<int,VI> primes=Sieve(n);
    cout<<"Total = "<<primes.first<<endl;
    for(auto i: primes.second)
        cout<<i<<" ";
}
