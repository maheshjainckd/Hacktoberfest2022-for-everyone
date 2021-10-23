#include<stdio.h>

int search (int arr[],int n,int x){
int i;
for(i=0;i<n;i++){
    if(arr[i]==x)
    return i;
}
    return -1;

}
int main(void){

int arr[]={2, 3, 4, 5 ,78, 68, 45 ,99};
int x=45;
int n=sizeof(arr)/sizeof(arr[0]);
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}
printf("\n");
printf("Enter the element you want to search in arr[]: ");
scanf("%d",&x);


int result=search(arr,n,x);
(result==-1)?printf("Element is not present in array ")
            :printf("Element is present at index %d",result);

             return 0;
}
