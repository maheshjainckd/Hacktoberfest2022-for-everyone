class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i,j;
        vector<char> rowC, colC, boxC;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                if(board[i][j] == '.');
                else if(find(rowC.begin(), rowC.end(), board[i][j]) != rowC.end()){
                    return false;
                }
                else{
                    rowC.push_back(board[i][j]);
                }
                if(board[j][i] == '.');
                else if(find(colC.begin(), colC.end(), board[j][i]) != colC.end()){
                    cout << board[j][i];
                    return false;
                }
                else{
                    colC.push_back(board[j][i]);
                }
                if(i%3==0&&j%3==0){
                    if(board[i][j] == '.');
                    else if(find(boxC.begin(), boxC.end(), board[i][j]) != boxC.end()){
                        
                    return false;
                    }
                    else{
                        boxC.push_back(board[i][j]);
                    }
                    if(board[i][j+1] == '.');
                    else if(find(boxC.begin(), boxC.end(), board[i][j+1]) != boxC.end()){
                        
                    return false;
                    }
                    else{
                    boxC.push_back(board[i][j+1]);
                    }
                    if(board[i][j+2] == '.');
                    else if(find(boxC.begin(), boxC.end(), board[i][j+2]) != boxC.end()){
                        
                        return false;
                    }
                    else{
                        boxC.push_back(board[i][j+2]);
                    }
                        if(board[i+1][j] == '.');
                    else if(find(boxC.begin(), boxC.end(), board[i+1][j]) != boxC.end()){
                        
                        return false;
                    }
                    else{
                        boxC.push_back(board[i+1][j]);
                    }
                        if(board[i+1][j+1] == '.');
                    else if(find(boxC.begin(), boxC.end(), board[i+1][j+1]) != boxC.end()){
                        cout<<board[i+1][j+1]<< " " << i << " " << j;
                        return false;
                    }
                    else{
                        boxC.push_back(board[i+1][j+1]);
                    }
                        if(board[i+1][j+2] == '.');
                    else if(find(boxC.begin(), boxC.end(), board[i+1][j+2]) != boxC.end()){
                        return false;
                    }
                    else{
                        boxC.push_back(board[i+1][j+2]);
                    }
                        if(board[i+2][j] == '.');
                    else if(find(boxC.begin(), boxC.end(), board[i+2][j]) != boxC.end()){
                        return false;
                    }
                    else{
                        boxC.push_back(board[i+2][j]);
                    }
                        if(board[i+2][j+1] == '.');
                    else if(find(boxC.begin(), boxC.end(), board[i+2][j+1]) != boxC.end()){
                        return false;
                    }
                    else{
                        boxC.push_back(board[i+2][j+1]);
                    }
                        if(board[i+2][j+2] == '.');
                    else if(find(boxC.begin(), boxC.end(), board[i+2][j+2]) != boxC.end()){
                        return false;
                    }
                    else{
                        boxC.push_back(board[i+2][j+2]);
                    }
                }
                boxC.clear();
            }
            rowC.clear();
            colC.clear();
            
        }
        return true;
    }
};