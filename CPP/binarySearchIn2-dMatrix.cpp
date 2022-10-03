//question link: https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool binarySearch(vector<vector<int>> matrix, int left, int right, int target, int n){
        int mid, i, j;
        if(right>=left){
            mid = left + (right-left)/2, i=mid/n, j=mid%n;
            if(matrix[i][j] == target){
                return true;
            }
            if(matrix[i][j]>target){
                return binarySearch(matrix, left, mid-1, target, n);
            }
            return binarySearch(matrix, mid+1, right, target, n);
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size(), i=0, j=m-1;
        return binarySearch(matrix, 0, (m*n -1), target, n);
    }
};
