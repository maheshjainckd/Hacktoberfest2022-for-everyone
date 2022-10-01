#include<iostream>
using namespace std;
void bubblesort( int *arr , int n){
 //base case -already sorted
 if(n==0 || n==1){
    return;
 }
 // ek case solve krna hai , largest element ko end mai rakhna hai 
 for(int i=0; i<n-1;i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i] , arr[i+1]);
        }
 }
 //Recursive call
 bubblesort(arr , n-1);

}
int main(){
int arr[5]= {12,10,43,23,41};
bubblesort(arr, 5);

//printing the array
cout<<"The sorted array is :";
for(int i=0; i<5; i++){
    cout<<arr[i]<<" ";
}cout<<endl;

return 0 ; 
}