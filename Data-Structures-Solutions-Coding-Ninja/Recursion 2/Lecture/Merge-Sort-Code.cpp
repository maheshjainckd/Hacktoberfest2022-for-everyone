// Merge Sort Code
void mergeSort(int input[], int size){
	// Write your code here
    if(size<=1){
        return;
    }
    int mid=size/2;
    int antiMid=size-mid;
    mergeSort(input,mid);
    mergeSort(input+mid,antiMid);
    int i1=0;
    int i2=mid;
    // int i=0;
    int newArr[size];
    int iN=0;
    while(iN<size && i1<mid && i2<size){
        if(input[i1]>input[i2]){
            newArr[iN]=input[i2];
            i2++;
            iN++;
        }
        else{
            newArr[iN]=input[i1];
            i1++;
            iN++;
        }
    }
    // cout<<"Printing specs"<<endl;
    // cout<<i1<<" "<<i2<<" "<<size<<" "<<iN<<endl;
    if(i1>=mid){
        for(int i=i2;i<size;i++){
            newArr[iN]=input[i];
            iN++;
        }
    }
    if(i2>=size){
        for(int i=i1;i<mid;i++){
            newArr[iN]=input[i];
            iN++;
        }
    }
    for(int i=0;i<size;i++){
        input[i]=newArr[i];
    }
}