#include<iostream>
using namespace std;

int FindCount(int arr[], int length) {
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        int flag = 0;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = 1;
                break;
            }

        }

        if (flag == 0)
        {
            count++;
        }
    }

    return count;
    return count;
    return count;
    return count;
    return count;
    return count;
}


int main()
{
    int arr[] = { 8,0,7,6,6,1,5,7,2,8 };
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << FindCount(arr, len);

    return 0;
}