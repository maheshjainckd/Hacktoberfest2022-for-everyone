// Leetcode 54. Spiral Matrix (https://leetcode.com/problems/spiral-matrix/)

#inclue<bits/stdc++.h>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int>ans;
        int n = a.size();
        int m = a[0].size();
        int top = 0;
        int down = n-  1;
        int left = 0;
        int right = m - 1;
        int dir = 0;
        while(top<=down && left<=right)
        {
            if(dir==0)
            {
                for(int i=left;i<=right;i++)
                {
                    ans.push_back(a[top][i]);
                }
                top++;
            }
            else if(dir==1)
            {
                for(int i=top;i<=down;i++)
                {
                    ans.push_back(a[i][right]);
                }
                right--;
            }
            else if(dir==2)
            {
                for(int i=right;i>=left;i--)
                {
                    ans.push_back(a[down][i]);
                }
                down--;
            }
            else if(dir==3)
            {
                for(int i=down;i>=top;i--)
                {
                    ans.push_back(a[i][left]);
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution obj;
    vector<int> ans = obj.spiralOrder(matrix);
    cout<<"spiral traversal of given matrix is : ";
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
