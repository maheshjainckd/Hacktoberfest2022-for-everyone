class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> x;
        unordered_map<char, int> m;
        for(auto &i : word) m[i]++;
        for(auto &i : m){
            x.push_back(i.second);
        }
        sort(x.begin(), x.end());
        if(x.size() == 1) return 1;
        
        else if(x.size() == 2){
            if(x[0] == 1 && x[1] == 1) return 1;
            else if(x[1] - x[0] == 1) return 1;
            return 0;
        }
        
        else{
            if(x[0] == 1 && count(x.begin(), x.end(), x[0]) == x.size()) return 1;
            else if(x[0] == 1 && count(x.begin(), x.end(), x[0]) != x.size()){
                if(x.size() == 3 && x[x.size() - 1] == 2) return 1;
            }
            
            int sum = 0;
            for(auto &i : x) sum += i;
            
            if(sum == (x[0] * x.size() + 1)) return 1;
            else return 0;
        }
        return 0;
    }
};
