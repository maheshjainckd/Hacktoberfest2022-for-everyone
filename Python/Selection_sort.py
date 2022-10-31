def SelectionSort(A):
  for i in range(len(A)): 
    min_idx = i 
    for j in range(i+1, len(A)): 
        if A[min_idx] > A[j]: 
            min_idx = j 

    A[i], A[min_idx] = A[min_idx], A[i]
  return A

A = []
print("Enter total number of elements: ")
n = int(input('> '))
print("Enter Array elements: ")
for i in range(0,n):
    temp = int(input('> '))
    A.append(temp)

SelectionSort(A)

print("Sorted array :")
print(A)
