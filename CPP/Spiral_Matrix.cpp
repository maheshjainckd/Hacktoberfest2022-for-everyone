 vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
    int count=0;
    vector <int> ans;
    int startingrow=0,startingcol=0,endingrow=matrix.size(),endingcol=matrix[0].size();
    int total=endingrow*endingcol;
    endingrow=matrix.size()-1;
    endingcol=endingcol-1;
        
        while(count<total){
    
        for(int i=startingcol;i<=endingcol&&count<total;i++){
            ans.push_back(matrix[startingrow][i]);
            count++;
        }
        startingrow++;
     
        for(int i=startingrow;i<=endingrow&&count<total;i++){
            ans.push_back(matrix[i][endingcol]);
            count++;
        }
        endingcol--;
    
        for(int i=endingcol;i>=startingcol&&count<total;i--){
            ans.push_back(matrix[endingrow][i]);
            count++;
        }
        endingrow--;
    
        for(int i=endingrow;i>=startingrow&&count<total;i--){
            ans.push_back(matrix[i][startingcol]);
            count++;
        }
        startingcol++;
      }
        return ans;
    }
