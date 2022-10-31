#include<iostream>
using namespace std;
int max(int a,int b,int c)
{
	if(a>=b&&a>=c)
	return a;
	else if(b>=a&&b>=c)
	return b;
	else
	return c;
}
int cal(int a,int b,int c,int n,int dp[])
{
	int p,q,r;
	if(n<=0)
	{
		if(n==0)
		return 0;
		else
		return INT_MIN;
	}
	if(dp[n])
		return dp[n];
	p=1+cal(a,b,c,n-a,dp);	
	q=1+cal(a,b,c,n-b,dp);	
	r=1+cal(a,b,c,n-c,dp);	
	return dp[n]=max(p,q,r);
}
int main()
{
	int a,b,c,n;
	cin>>n>>a>>b>>c;
	int dp[4001];
	for(int i=0;i<=4000;i++)
	dp[i]=0;
	cout<<cal(a,b,c,n,dp);
}
