bool isPossible(vector<int> arr, int n, int m, int mid)
{
    int studentcount = 1;
    int pagesum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesum + arr[i] <= mid)
        {
            pagesum += arr[i];
        }
        else
        {
            studentcount++;
            if (studentcount > m || arr[i] > mid)
                return false;
            pagesum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m)
{
    // Write your code here.
    int l = 0;
    int sum = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int h = sum;
    int mid = (l + h) / 2;
    while (l <= h)
    {
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
        mid = (l + h) / 2;
    }
    return ans;
}
