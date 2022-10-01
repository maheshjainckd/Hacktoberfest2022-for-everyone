#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(int ls, int rs, vector<int> arr, int i, int j) {
  if (i > j) {
    if (ls == rs) {
      for (auto i : arr) {
        cout << i << " ";
      }
      cout << endl;
    }
  return;
}

  arr[i] = 0;
  arr[j] = 0;
  solve(ls, rs, arr, i + 1, j - 1);

  arr[i] = 0;
  arr[j] = 1;
  solve(ls, rs + 1, arr, i + 1, j - 1);

  arr[i] = 1;
  arr[j] = 0;
  solve(ls + 1, rs, arr, i + 1, j - 1);

  arr[i] = 1;
  arr[j] = 1;
  solve(ls + 1, rs + 1, arr, i + 1, j - 1);
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(2 * n);
  solve(0, 0, arr, 0, 2 * n - 1);
}