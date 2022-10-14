//Number of Digits
int count(int n){
    //write your code herif
    if(n==0){
        return 0;
    }
    return 1+count(n/10);
}