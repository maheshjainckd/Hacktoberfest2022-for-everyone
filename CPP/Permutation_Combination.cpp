#include <bits/stdc++.h>
using namespace std;

// Function to calculate the factorial of a number :
int factorial(int val)
{
    int ans = 1;
    for (int i = 1; i <= val; i++)
    {
        ans = ans * i;
    }
    return ans;
}

// Main Function
int main()
{
    cout << "Choice 1: Permutation"
         << "\n";
    cout << "Choice 2: Combination"
         << "\n";
    cout << "Enter your choice : \n";

    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int n, r;
        cout << "Enter the values of n and r respectively : \n";
        cin >> n >> r;
        int numerator = factorial(n);
        int denominator = factorial(n - r);
        double result = numerator / denominator;
        cout << "The value of " << n << " P " << r << " is : " << result;
    }
    break;

    case 2:
    {
        int n2, r2;
        cout << "Enter the values of n and r respectively : \n";
        cin >> n2 >> r2;
        int numerator2 = factorial(n2);
        int denominator2 = factorial(n2 - r2) * factorial(r2);
        double result2 = numerator2 / denominator2;
        cout << "The value of " << n2 << " C " << r2 << " is : " << result2;
    }
    break;

    default:
        cout << "Please enter the correct choice! \n";
        break;
    }
    return 0;
}