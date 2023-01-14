/* Using recursion 

#include <bits/stdc++.h>
using namespace std;

int knapsnap(int wt[],int val[],int n, int W){
    if(n==0 || W<=0){
        return 0;
    }
    if(wt[n-1]>W){
        return 0+ knapsnap(wt,val,n-1,W);
    }

        return max(val[n-1]+knapsnap(wt,val,n-1,W-wt[n-1]),knapsnap(wt,val,n-1,W));
     
}

int main(){
    int wt[4]={2,4,6,8};
    int val[4]={10,15,20,45};
    int W=10;
    cout<<knapsnap(wt,val,4,W);
}
*/



//using memoization 

#include <bits/stdc++.h>
using namespace std;
int dp[100][1000];

knapsnap(int wt[],int val[],int n,int W){
    if(n==0 || W<=0){
        return 0;
    }

    if (dp[n][W]!=-1){
        return dp[n][W];
    }

    if(wt[n-1]<=W){
        return dp[n][W]=max(knapsnap(wt,val,n-1,W),knapsnap(wt,val,n-1,W-wt[n-1])+val[n-1]);
    }
    else
    return dp[n][W]=knapsnap(wt,val,n-1,W);

}
int main()
{
    memset(dp,-1,sizeof(dp));
    int wt[4]={2,4,6,8};
    int val[4]={10,15,20,45};
    int W=20;
    cout<<knapsnap(wt,val,4,W);

}



/*

#include <bits/stdc++.h>
using namespace std;

int knapsnap(int wt[], int val[],int n,int W){
int dp[n+1][W+1];

for(int i=0;i<n+1;i++){
    for(int j=0;j<W+1;j++){
        if(i==0 || j<=0){
            dp[i][j]=0;
        }
       else if(wt[i-1]<=j){
            dp[i][j] = max(val[i-1]+ dp[i-1][j-wt[i]],0+dp[i-1][j]);
        }
        else
        dp[i][j]=0+dp[i-1][j];

    }
}

return dp[n][W];
}

int main (){
    
int wt[4]={2,4,6,8};
    int val[4]={10,15,20,45};
    int W=20;
    cout<<knapsnap(wt,val,4,W);

}

*/