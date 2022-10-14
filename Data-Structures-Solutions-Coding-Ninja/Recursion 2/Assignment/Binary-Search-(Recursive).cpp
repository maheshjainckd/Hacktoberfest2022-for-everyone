// Binary Search (Recursive)
int binarySearch2(int input[],int s,int e,int element){
    if(s>=e){
        return -1;
    }
    int mid=(s+e)/2;
    if(input[mid]==element){
        return mid;
    }
    else if(input[mid]<element){
        return binarySearch2(input,mid+1,e,element);
    }
    else{
        return binarySearch2(input,s,mid-1,element);
    }
}
int binarySearch(int input[], int size, int element) {
    // Write your code here
    return binarySearch2(input,0,size-1,element);
}