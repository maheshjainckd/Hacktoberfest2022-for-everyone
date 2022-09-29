"""
Time Complexity: O(n)
Algo's Objective: Maximum/Minimum Sum of K size subarray

1. windowsum: Store the sum of elements of current window
2. maximum: Store the maximum sum while iterating through windows
3. While running the for loop, we are removing the 1st element of the current window and adding the rightmost element (not included) of the window.

"""

def slidingwindow1(arr, k):
    windowsum = sum(arr[:k])
    maximum = windowsum
    n = len(arr)

    for i in range(n-k):
        windowsum = windowsum - arr[i] + arr[i+k]
        maximum = max(windowsum, maximum)
    return maximum

arr = [1, 4, 2, 10, 2, 3, 1, 0, 20]
k = 3
print(slidingwindow1(arr, k))

"""
Time Complexity: O(n²)
Algo's Objective: Smallest subarray with given Sum
"""

def slidingwindow2(arr, target):
    windowsum = 0              #Current window sum
    j = 0                      #Window Start
    jsize = max(arr)           #Current Window Size

    for i in range(len(arr)):
        windowsum = windowsum + arr[i]

        while windowsum >= target:
            jsize = min(jsize, i - j + 1)
            windowsum = windowsum - arr[j]
            j = j + 1
    return jsize


arr = [4, 2, 2, 7, 8, 1, 2, 8, 1, 0]
target = 8
print(slidingwindow2(arr, target))
