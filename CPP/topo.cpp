#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > generateMatrix(int A) {
    
int dir=0;
int top=0;
int left=0;
int N=A;
int right=N-1;
int down=N-1;
int k=1;
vector<vector<int>> a;
while(top<=down && left<=right){
if(dir==0){
for(int i=left;i<=right;i++){
a[top][i]=k++;
top++;
}
}
else if(dir==1){
for(int i=top;i<=down;i++){
a[i][right]=k++;

}
right--;
}
 else if(dir==2){
for(int i=right;i>=left;i--){
a[down][i]=k++;

}
down--;
}
else if(dir==3){
for(int i=down;i>=top;i--){
a[i][left]=k++;

}
left++;
}
dir=(dir+1)%4;
}
return a;
}