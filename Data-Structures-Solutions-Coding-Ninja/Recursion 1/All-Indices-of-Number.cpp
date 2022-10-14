// All Indices of Number
int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    if(size==0){
        return 0;
    }
    int smallOutput=allIndexes(input,size-1,x,output);
    if(input[size-1]==x){
        output[smallOutput]=size-1;
        smallOutput++;
    }
    return smallOutput;
}
