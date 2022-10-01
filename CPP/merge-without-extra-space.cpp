class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int gap=ceil((n+m)/2);
	   // cout<<gap<<endl;
	    while(gap>0){
	        int i=0;
	        while(i+gap<n+m){
	            if(i>n-1){
	                if(arr2[i-n]>arr2[i-n+gap]){
	                    swap(arr2[i-n],arr2[i-n+gap]);
	                }
	            }
	            else{
	                if(i+gap<n){
	                    if(arr1[i]>arr1[i+gap]){
	                        swap(arr1[i],arr1[i+gap]);
	                    }
	                }
	                else{
	                    if(arr1[i]>arr2[i+gap-n]){
	                        swap(arr2[i+gap-n],arr1[i]);
	                    }
	                }
	            }
	            i++;
	        }
	       if(gap == 1){
	           break;
	       }
	        gap=gap/2+gap%2;
	    }
	}
};