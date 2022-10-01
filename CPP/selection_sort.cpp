//Selection sort in c++
//Author deenu-1001

#include <iostream>
using namespace std;
int ssort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = a[i], pos=i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                pos = j;
                min = a[j];
            }
        }
        if (pos != 1)
        {
            int temp = a[i];
            a[i] = a[pos];
            a[pos] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ssort(arr, n);
}
