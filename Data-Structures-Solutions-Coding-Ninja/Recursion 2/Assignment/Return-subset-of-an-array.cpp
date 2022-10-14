// Return subset of an array
int subset(int input[], int n, int output[][20]) {
    // Write your code here
    if(n<=0){
        // int *newArr=new int[1];
        // newArr[0]=0;
        output[0][0]=0;
        return 1;
    }
    int smallOutput=subset(input+1,n-1,output);
    int count=smallOutput;
    for(int i=0;i<smallOutput;i++){
        int leng=output[i][0]+1;
        // int *newArr=new int[output[i][0]+2];
        // newArr[0]=output[i][0]+1;
        // newArr[1]=input[0];
        // int subCount=2;
        output[count][0]=leng;
        output[count][1]=input[0];
        for(int j=2;j<=leng;j++){
            output[count][j]=output[i][j-1];
        }
        count++;
    }
    return count;
    
}