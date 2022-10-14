// Check Array Rotation
int arrayRotateCheck(int *input, int size)
{
    //Write your code here
    if(size<=0){
        return 0;
    }
    int i=0;
    for(i;i<size;i++){
        if(input[i]>input[i+1]){
            break;
        }
    }
    if(i==size-1){
        return 0;
    }
    else{
        return i+1;
    }
}