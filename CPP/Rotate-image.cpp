//Rotating a 2D Matrix by 90 degrees
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }


int main(){
   vector<vector<int>> vect
    {
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}
    };
    int n=vect.size();
    int m=vect[0].size();
    rotate(vect);
    
    for(int i=0;i<vect.size();i++){
        for(int j=0;j<m;j++){
        cout<<vect[i][j];
    }
    }

  

}