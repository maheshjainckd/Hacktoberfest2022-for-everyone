// Print Subsets of Array
#include<cmath>
void helper(int input[],int size,int output[],int outputSize){
    if(size<=0){
        for(int i=0;i<outputSize;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    helper(input+1,size-1,output,outputSize);
    int newOutput[outputSize+1];
    for(int i=0;i<outputSize;i++){
        newOutput[i]=output[i];
    }
    newOutput[outputSize]=input[0];
    helper(input+1,size-1,newOutput,outputSize+1);
}
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int outputMaxSize=pow(2,size);
    int output[0];
    helper(input,size,output,0);
}
