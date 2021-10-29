#include<bits/stdc++.h>
using namespace std;


class Solution{
public:

    // Using DFS
    int dfs_helper(vector<vector<int>> &g, int row, int col, int n, int m, int sum){
        if(row < 0 || col < 0 || row >= n || col >= m){
            return sum;
        }
        sum += g[row][col];

        int a = dfs_helper(g, row, col+1, n, m, sum);
        int b = dfs_helper(g, row-1, col+1, n, m, sum);
        int c = dfs_helper(g, row+1, col+1, n, m, sum);

        if(a > b && a>c) {
            return a;
        }else if(b>c){
            return b;
        }else{
            return c;
        }
    }

    int goldMine(vector<vector<int>> &g, int n, int m){

        int max = INT_MIN;
        for(int i=0; i<n; i++){
            int sum = 0;
            int temp = dfs_helper(g, i, 0, n, m, sum);
            if(max < temp){
                max = temp;
            }
        }
        return max;
    }

    // Using Dynamic Programming
    int goldMine_DP(vector<vector<int>> &vec, int n, int m){
        auto t = vec;
        for(int col=m-2; col>=0; col--){
            for(int row=0; row<n; row++){
                int right_move = t[row][col+1];
                int rightUp_move = row == 0 ? 0 : t[row-1][col+1];
                int rightDown_move = row == n-1 ? 0 : t[row+1][col+1];
                t[row][col] += max(right_move, max(rightUp_move, rightDown_move));
            }
        }

        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            if(ans < t[i][0]){
                ans = t[i][0];
            }
        }

        return ans;

    }
};

int main() {
    int n, m;
    cout<<"Enter n(row) : ";
    cin>>n;
    cout<<endl;

    cout<<"Enter m(col) : ";
    cin>>m;
    cout<<endl;

    vector<vector<int>> vec(n,(vector<int>(m, -1)));

    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>vec[i][j];
        }
    }
    cout<<endl;

    Solution obj;

    int res = obj.goldMine(vec, n ,m);

    cout<<"Answer is (DFS): "<<res<<endl;

    int res_dp = obj.goldMine_DP(vec, n, m);
    cout<<"Answer is (DP): "<<res_dp<<endl;

    return 0;
}
