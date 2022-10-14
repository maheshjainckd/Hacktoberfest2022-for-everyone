// Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Write your code here
    if(n<=0){
        return;
    }
    if(n==1){
        cout<<source<<" "<<destination<<endl;
        return;
    }
    towerOfHanoi(n-1,source,destination,auxiliary);
    towerOfHanoi(1,source,auxiliary,destination);
    towerOfHanoi(n-1,auxiliary,source,destination);
    
}
