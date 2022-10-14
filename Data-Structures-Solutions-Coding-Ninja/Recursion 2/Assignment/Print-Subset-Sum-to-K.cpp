// Print Subset Sum to K
void helper(int input[], int size, int k, int output[], int outputSize ){
    // cout<<"k is "<<k<<endl;
    
    
    if(k==0){
        // cout<<outputSize<<" reached"<<endl;
        for(int i=0;i<outputSize;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(size<=0){
        return;
    }
    helper(input+1,size-1,k,output,outputSize);
    if((k-input[0])>=0){
        int newOutput[outputSize+1];
        for(int i=0;i<outputSize;i++){
            newOutput[i]=output[i];
        }
        newOutput[outputSize]=input[0];
        helper(input+1,size-1,k-input[0],newOutput,outputSize+1);
    }
    return;
    
}
void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int output[0];
    helper(input,size,k,output,0);
}
