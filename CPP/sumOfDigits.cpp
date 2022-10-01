#include<bits/stdc++.h>
using namespace std;
typedef long long int ln;
void fun()
{
	int sum=0;
   ln n;
   cin>>n;
  // ln temp=n;
   while(n>0)
   {
   	
   	sum += n%10;
   	n=n/10;
   }
   cout<<sum;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
		fun();
	return 0;
}