def insertionSort(myarr):
    for i in range(1, len(myarr)):
        t = myarr[i]
        j = i-1
        while j >= 0 and t < myarr[j] :
                myarr[j + 1] = myarr[j]
                j -= 1
        myarr[j + 1] = t
testarr=list(map(int,input().split()))
insertionSort(testarr)
print(testarr)