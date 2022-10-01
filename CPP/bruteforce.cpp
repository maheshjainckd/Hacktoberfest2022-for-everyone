#include "bits/stdc++.h"
using namespace std;
int32_t main() {
int n, m; cin >> n >> m;
int target; cin >> target;
int mat[n][m];
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
cin >> mat[i][j];
}
}
bool found = false;
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
if (mat[i][j] == target)
found = true;
}
}
if (found)
cout << "Found";
else
cout << "Not Found";
}