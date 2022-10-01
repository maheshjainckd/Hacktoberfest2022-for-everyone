#include <iostream>
using namespace std;
int partition(int input[], int si, int ei)
{

    int x = input[si];
    int count = 0;
    for (int i = si + 1; i <= ei; i++)
    {
        if (input[i] <= x)
            count++;
    }
    int pi = si + count;
    int temp = input[si];
    input[si] = input[pi];
    input[pi] = temp;
    int i = si, j = ei;
    while (i < pi || j > pi)
    {
        if (input[i] <= x)
            i++;
        else if (input[j] > x)
            j--;
        else
        {
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }
    return pi;
}

void quickSort(int input[], int si, int ei)
{
    if (si >= ei)
        return;
    int pi = partition(input, si, ei);
    quickSort(input, si, pi - 1);
    quickSort(input, pi + 1, ei);
}

void quickSort(int input[], int size)
{

    quickSort(input, 0, size - 1);
}
