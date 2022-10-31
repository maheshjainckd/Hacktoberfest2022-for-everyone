//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     long long reversedBits(long long X) {
    if(X>=INT_MAX){
        return X;
    }
    int i=31;
	long long ans=0;
	while(X!=0){
		int bit=X&1;
		ans=bit*pow(2,i)+ans;
		X=X>>1;
		i--;
	}
     return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends
