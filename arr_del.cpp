#include <iostream>

using namespace std;

int main ()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int m;
    cin >> m;
    int pos[m];
    for (int i = 0; i < m; i++){
      cin >> pos[i];
    }
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = 1;

    }

    for (int i = 0; i < m; i++)
    {
        temp[pos[i] - 1] = 0;

    }

    int k = 0;
    int brr[n - m];

    for (int i = 0; i < n; i++)
    {
        if (temp[i] == 1)
	{
	    brr[k] = arr[i];
	    k++;

	}

    }


    for (int i = 0; i < n - m; i++)
    {
      cout << brr[i] << " ";
    }

    return 0;
}


