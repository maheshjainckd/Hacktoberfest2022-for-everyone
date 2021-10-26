#include <bits/stdc++.h>
using namespace std;

int n;
int solve(vector<int> &A, vector<int> &B, int C) {
	if (n == 0 || C == 0)
		return 0;
	int dp[n + 1][C + 1];
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;

	for (int i = 1; i <= C; i++)
		dp[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= C; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (B[i - 1] <= j)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - B[i - 1]] + A[i - 1]);
		}
	}
	return dp[n][C];
}

int main() {
	// 0-1 Knapsack
  cin>>n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	vector<int> B(n);
	for (int i = 0; i < n; i++)
		cin >> B[i];
	int C;  cin >> C;
	cout << solve(A, B, C);
	return 0;
}
