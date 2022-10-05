#include <bits/stdc++.h>
using namespace std;
// This code kind of uses sliding window technique. First
// checking if string[0] and string[0..n-1] is divisible if
// yes then return else run a loop from 1 to n-1 and check if
// taking this (0-i)index number and (i+1 to n-1)index number
// on our two declared variables if they are divisible by given two numbers respectively
// in any iteration return them simply
string stringPartition(string s, int a, int b)
{
	// code here
	int n = s.length();
// if length is 1 not possible
	if (n == 1) {
		return "-1";
	}
	else {
	// Checking if number formed bt S[0] and S[1->n-1] is divisible
		int a1 = s[0] - '0';
		int a2 = s[1] - '0';
		int multiplyer = 10;
		for (int i = 2; i < n; i++) {
			a2 = a2 * multiplyer + (s[i] - '0');
		}
		int i = 1;
		if (a1 % a == 0 && a2 % b == 0) {
			string k1 = string(1, s[0]);
			string k2 = "";
			for (int j = 1; j < n; j++)
				k2 += s[j];
			return k1 + " " + k2; // return the numbers formed as string
		}
	// from here by using sliding window technique we will iterate and check for every i
	// that if the two current numbers formed are divisible if yes return
	// else form the two new numbers for next iteration using sliding window technique
		int q1 = 10;
		int q2 = 1;
		for (int i = 1; i < n - 1; i++)
			q2 *= 10;
		while (i < n - 1) {
			char x = s[i];
			int ad = x - '0';
			a1 = a1 * q1 + ad;
			a2 = a2 - q2 * ad;
			if (a1 % a == 0 && a2 % b == 0) {
				string k1 = "";
				string k2 = "";
				for (int j = 0; j < i + 1; j++)
					k1 += s[j];
				for (int j = i + 1; j < n; j++)
					k2 += s[j];
				return k1 + " " + k2;
			}
			q2 /= 10;
			i++;
		}
	}
	return "-1";
}
// Driver code
int main()
{
	string str = "123";
	int a = 12, b = 3;
	string result = stringPartition(str, a, b);

	if (result == "-1") {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		cout << result << endl;
	}

	return 0;
}
// This code is contributed by Kartikey Singh
