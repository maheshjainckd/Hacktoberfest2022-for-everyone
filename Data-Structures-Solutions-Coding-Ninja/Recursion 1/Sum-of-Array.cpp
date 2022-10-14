// Sum of Array
int sum(int input[], int n) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    if(n==0){
        return 0;
    }
    return input[0] + sum(input+1,n-1);

}