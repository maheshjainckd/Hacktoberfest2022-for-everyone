// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the sum of internal
// angles of an n-sided polygon
int sumOfInternalAngles(int n)
{
	if (n < 3)
		return 0;
	return (n - 2) * 180;
}

// Driver code
int main()
{
	int n = 5;

	cout << sumOfInternalAngles(n);

	return 0;
}
