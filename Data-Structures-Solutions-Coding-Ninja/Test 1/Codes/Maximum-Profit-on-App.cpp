// Maximum Profit on App
#include<bits/stdc++.h>
int maximumProfit(int budget[], int n) {
    // Write your code here
    sort(budget,budget+n);
    int maxProfit=0;
    for(int i=0;i<n;i++){
        if(budget[i]*(n-i)>maxProfit){
            maxProfit=budget[i]*(n-i);
        }
    }
    return maxProfit;
}
