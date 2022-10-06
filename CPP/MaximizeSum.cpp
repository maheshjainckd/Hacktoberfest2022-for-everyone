#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum that can be obtained from two given based on the following conditions
int MaximumSum(int a[], int b[], int n)
{
    int dp[n][2];

    dp[0][0] = a[0];
    dp[0][1] = b[0];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];

        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);

        if (i - 2 >= 0)
        {
            dp[i][1] = max(dp[i][1], max(dp[i - 2][0], dp[i - 2][1]) + b[i]);
        }
        else
        {
            dp[i][1] = max(dp[i][1], b[i]);
        }
    }

    return max(dp[n - 1][0], dp[n - 1][1]);
}

int main()
{
    int A[] = {10, 1, 10, 10};
    int B[] = {5, 50, 1, 5};
    int N = sizeof(A) / sizeof(A[0]);

    cout << MaximumSum(A, B, N);
    return 0;
}
