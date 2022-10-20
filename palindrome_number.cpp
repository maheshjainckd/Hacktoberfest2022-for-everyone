class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){
    return false;}
    long long n=x;
    long long rev=0,remd ;
    while(x!=0)
        {
            rev= (rev*10)+x%10;
            x/=10;}
        
    
            if(rev==n){
                return true;
            }
            else{
                return false;
            }
        }
    

};
