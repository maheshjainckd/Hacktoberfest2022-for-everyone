#include<iostream>
using namespace std;
int n;

int main(){
char arr[100]="apple";
cin>>arr;

//en 100 element ko access kese kare ham,esake liye loop lagana padega
int i=0;

while (arr[i] !='\0')
{
   cout<<arr[i]<<endl;
   i++;
}




return 0;
}