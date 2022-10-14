// Split Array
bool helper(int *input, int n,int sum1 , int sum2){
    if(n==0){
        return sum1==sum2;
    }
    if(input[0]%5==0){
        sum1=sum1+input[0];
        return helper(input+1,n-1,sum1,sum2);
    }
    else if(input[0]%3==0){
        sum2=sum2+input[0];
        return helper(input+1,n-1,sum1,sum2);
    }
    else{
        return helper(input+1,n-1,sum1+input[0],sum2) || helper(input+1,n-1,sum1,sum2+input[0]);
    }
}
bool splitArray(int *input, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    return helper(input,size,0,0);
}