// Count Zeros
int countZeros(int n) {
    // Write your code here
    if(n==0){
        return 1;
    }
    if(n/10==0){
        return 0;
    }
    int smallOutput=countZeros(n/10);
    if(n%10==0){
        return ++smallOutput;
    }
    else{
        return smallOutput;
    }
}