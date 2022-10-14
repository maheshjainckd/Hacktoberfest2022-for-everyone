// Geometric Sum
#include<cmath>
double geometricSum(int k) {
    // Write your code here
    if(k==0){
        return 1.0;
    }
    
    double denom=pow(2,k);
    double value=1/denom;
    double ans=value + geometricSum(k-1);
    return ans;
    
}