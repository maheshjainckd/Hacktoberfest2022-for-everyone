// Quick Sort Code
int partition(int input[],int s,int e){
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(input[i]<=input[s]){
            count++;
        }
    }
    int curr=input[count];
    input[count]=input[s];
    input[s]=curr;
    while(s<count && e>count){
        while(input[s]<=input[count] && s<count){

            s++;
        }
        while(input[e]>input[count] && e>count){
            e--;
        }
        if(s>=count || e<=count){
            break;
        }
        int curr1=input[e];
        input[e]=input[s];
        input[s]=curr1;
    }
    return count;
}
void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    if(size<=1){
        return;
    }
    int pi=partition(input,0,size-1);
    quickSort(input,pi);
    quickSort(input+pi+1,size-pi-1);
}
