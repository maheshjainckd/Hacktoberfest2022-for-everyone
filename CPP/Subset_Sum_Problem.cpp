#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool subsetSum(int arr[], int n, int sum){
        bool t[n+1][sum+1];

        for(int i=0; i<sum+1; i++){
            t[0][i] = false;
        }

        for(int i=0; i<n+1;i++){
            t[i][0] = true;
        }

        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(arr[i-1] <= j){
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[n][sum];
    }
};

int main() {
    Solution obj;
    int n, sum;
    cout<<"Enter sum: ";
    cin>>sum;
    cout<<endl;

    cout<<"Enter size of array: ";
    cin>>n;
    cout<<endl;

    int arr[n];

    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    bool ans = obj.subsetSum(arr, n, sum);
    string ok = ans == true ? "Yes" : "No";
    cout<<"Answer is: "<<ok<<endl;

    return 0;
}
