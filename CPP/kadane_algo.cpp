// C++ program to print largest contiguous array sum
// Time Complexity: O(n) 

#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int a[], int size)
{
	int maxi=arr[0];
	int sum=0;

	for (int i = 0; i < size; i++)
	{
		sum=sum+arr[i];
		maxi=max(maxi,sum);
		if(sum<0)
		{
			sum=0;
		}
			
	}
	return maxi;
}

/*Driver program to test maxSubArraySum*/
int main()
{
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}

// Output:
// Maximum contiguous sum is 7
