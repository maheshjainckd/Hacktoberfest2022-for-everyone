def ShellSort(Ar, n):
    gap = n//2
    while gap > 0:
        i = gap
        while i < n:
            j = i - gap
            while j >= 0:
                if Ar[j + gap] >= Ar[j]:
                    break
                else:
                    temp = Ar[j]
                    Ar[j] = Ar[j + gap]
                    Ar[j + gap] = temp
                j = j - gap
            i = i+1
        gap = gap//2


ar = []
n = int(input("\nPlease enter the number of terms.\nTerms: "))
for i in range(n):
    num = int(input("Element: "))
    ar.append(num)
print("\nUnsorted Array: ", Ar)
ShellSort(Ar, n)
print("\nSorted Array: ", Ar)