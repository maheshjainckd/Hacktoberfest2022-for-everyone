// Sum of digits (recursive)
int sumOfDigits(int n) {
    // Write your code here
    if(n==0){
        return 0;
    }
    return n%10+sumOfDigits(n/10);
}


