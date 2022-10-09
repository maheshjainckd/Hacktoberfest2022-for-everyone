//Tower of Hanoi
#include<iostream>
using namespace std;
void towerofHanoi(int n,char src,char dest,char help){
    if(n==0){
        return ;    //Base case
    }

    towerofHanoi(n-1,src,help,dest);
    cout<<"Move from"<<src<<"to "<<dest<<endl;
    towerofHanoi(n-1,help,dest,src);

}
int main()
{
    towerofHanoi(3,'A','C','B');
    
    return 0;
}