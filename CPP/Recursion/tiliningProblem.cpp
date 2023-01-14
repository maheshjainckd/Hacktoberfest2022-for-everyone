//Find the number of ways for placeung a tile
#include<iostream>
using namespace std;
int tilingways(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return tilingways(n-1) +tilingways(n-2);

    }
int main()
{
    cout<<tilingways(4)<<endl;
    
    return 0;
}