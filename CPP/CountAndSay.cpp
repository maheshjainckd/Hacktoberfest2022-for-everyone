string countAndSay(int n) {
        string res = "1", ans;
        n--;
        
        while(n--) {
            ans = "";
            
			
            for (int i = 0; i < res.size(); i++) {
                int count = 1;
                
                while(i + 1 < res.size() && res[i] == res[i+1]) {
                    count++; i++;
                }
                
                ans += to_string(count) + res[i];
            }
            
            res = ans;
        }
        
        return res;
    }
