// Multiplication (Recursive)
int multiplyNumbers(int m, int n) {
    // Write your code here
    if(m==0 || n==0){
        return 0;
    }
    return m + multiplyNumbers(m,n-1);

}


