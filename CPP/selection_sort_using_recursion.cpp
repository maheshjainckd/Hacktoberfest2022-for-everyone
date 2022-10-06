#include <iostream>
using namespace std;

void selectionSort(int arr[], int index, int n)
{
    if (n == 1 || n == 0)
        return;

    int minIndex = index;
    int size = n + index;

    for (int i = index + 1; i < size; i++)
    {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }
    swap(arr[index], arr[minIndex]);

    selectionSort(arr, ++index, n - 1);
}

int main()
{
    cout << endl;

    int arr[9] = {29, 72, 98, 13, 87, 66, 52, 51, 36};
    selectionSort(arr, 0, 9);

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;

    return 0;
}
