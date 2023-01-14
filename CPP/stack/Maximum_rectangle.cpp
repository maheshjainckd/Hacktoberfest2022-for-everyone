// https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    int mx(vector<int>&h){
        stack<pair<int,int>>s;
        vector<int>v,a;
        for(int i=0; i<h.size(); i++){
            if(s.empty()){
                s.push({h[i],i});
                v.push_back(0);
            }
            else{
                while(!s.empty() && s.top().first>=h[i]) s.pop();
                if(s.empty()){
                    v.push_back(i);
                    s.push({h[i],i});
                }
                else{
                    int ans = i-s.top().second-1;
                    v.push_back(ans);
                    s.push({h[i],i});
                }
            }
        }
        // s.clear();
        while(!s.empty())s.pop();
        // int j=0;
        for(int i=h.size()-1; i>=0; i--){
            if(s.empty()){
                s.push({h[i],i});
                // j++;
                a.push_back(1);
            }
            else{
                while(!s.empty() && s.top().first>=h[i]) s.pop();
                if(s.empty()){
                    a.push_back(h.size()-i);
                    s.push({h[i],i});
                }
                else{
                    int ans = abs(i-s.top().second);
                    a.push_back(ans);
                    s.push({h[i],i});
                }
            }
        }
        int ans=0;
        reverse(a.begin(),a.end());
        for(int i=0; i<a.size(); i++){
            ans=max(ans,h[i]*(v[i]+a[i]));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>h(matrix[0].size(),0);
        int cnt=0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j]=='0') {h[j]=0;}
                else{
                    // matrix[i][j] = (1+(matrix[i-1][j]-'0')+'0');
                    // h.push_back(matrix[i][j]-'0');
                    h[j]++;
                }
            }
            cnt=max(cnt,mx(h));
        }
        return cnt;
    }
};