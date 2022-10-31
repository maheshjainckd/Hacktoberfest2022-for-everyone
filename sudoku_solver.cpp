class Solution{
public:
    void solveSudoku(vector<vector<char>>& board){
        vector<pair<int,int>> sum;
        for (size_t r = 0; r < 9; ++r){
            for (size_t c = 0; c < 9; ++c){
                if (board[r][c] == '.'){
                    sum.push_back(make_pair(r, c));
                }
            }
        }
        ans(board, sum, 0);
    }
    bool ans(vector<vector<char>>& board, vector<pair<int,int>>& sum, size_t index){
        if (index == sum.size()){
            return true;
        }
        size_t r = sum[index].first;
        size_t c = sum[index].second;
        for (board[r][c] = '1'; board[r][c] <= '9'; board[r][c] += 1){
            bool valid = true;
            for (size_t i = 0; valid && i < 9; ++i){
                if (i != r && board[i][c] == board[r][c]
                    || i != c && board[r][i] == board[r][c]
                    || i != r % 3 * 3 + c % 3 && board[r / 3 * 3 + i / 3][c / 3 * 3 + i % 3] == board[r][c]){
                    valid = false;
                    break;
                }
            }
            if (valid && ans(board, sum, index + 1)){
                return true;
            }
        }
        return false;
    }
};
