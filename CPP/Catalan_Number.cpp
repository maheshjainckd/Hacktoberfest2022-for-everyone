/*
The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    // dynamic programming
    void catalan_1(unsigned int n){
        int t[n+1];
        t[0] = t[1] = 1;
        for(int i=2; i<n+1; i++){
            t[i] = 0;
            for(int j=0; j<i; j++){
                t[i] += t[j]*t[i-j-1];
            }
        }
        for(int i=0; i<n+1; i++){
            cout<<t[i]<<" ";
        }
        cout<<endl;
    }

    unsigned long int catalan_2(unsigned int n){
        if(n <= 1){
            return 1;
        }

        unsigned long int res = 0;
        for(int i=0; i<n; i++){
            res += catalan_2(i)*catalan_2(n-i-1);
        }

        return res;
    }
};

int main() {
    Solution obj;
    obj.catalan_1(6);
    //unsigned long int ans = obj.catalan_2(6);
    //cout<<"Answer is: "<<ans<<endl;
    return 0;
}
