//Sparse matrix to Compact matrix
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int R, C;
    cin >> R >> C;
    int sparse[R][C];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> sparse[i][j];
        }
    }
    int compact[R*C][3];
    compact[0][0] = R;
    compact[0][1] = C;
    int k = 1;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(sparse[i][j]!=0){
                compact[k][0] = i+1;
                compact[k][1] = j+1;
                compact[k][2] = sparse[i][j];
                k++;
            }
        }
    }
    compact[0][2] = k - 1;
    cout << "\n\n";
    cout << "The compact Matrix ->" << endl;
    for(int i = 0; i < k; i++){
        for (int j = 0; j < 3; j++){
            cout << setw(6) << compact[i][j];
        }
        cout << endl;
    }
}
