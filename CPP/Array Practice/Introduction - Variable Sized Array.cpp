#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q,k,i,j;
    cin >> n >> q;
    vector<vector<int> >arr(n);
    for (i=0; i<n; ++i){
        cin >> k;
        arr[i].resize(k);
        for(j=0 ; j<k; ++j){
            cin >> arr[i][j];
        }       
    }

    for(i=0; i<q; ++i){
        cin >> n >> k;
        cout << arr[n][k]<<endl;
    }  
        
    return 0;
}
