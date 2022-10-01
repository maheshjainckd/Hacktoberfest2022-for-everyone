#include<iostream>
#include<algorithm>
using namespace std;

int main() {
   int n;
   cin >> n;
   int arr[n];  
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   
   sort(arr,arr + n);

   cout << "Sum max and min values from array: " << arr[0] + arr[n-1] << endl;
}
