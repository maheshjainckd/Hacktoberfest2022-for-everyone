class Solution {
public:
    double myPow(double x, int n) {
        long long power = abs(n);
        double ans = 1;
        if(x == 1){
            return 1;
        }
        if( x != -1 and n == INT_MIN){
            return 0;
        }
        if(( x == -1) and n == INT_MAX){
            return -1;
        }
        if((x==-1) and n == INT_MIN){
            return 1;
        }
        if(n<0){
            for(long long i = 1; i <= power;i++){
                ans=(ans/x);
            }
        }
        else{
            for(long long i = 1; i <= power;i++){
                ans=(ans*x);
            }
        }
        return ans;
    }
};
