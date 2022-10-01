def find(arr,s,e,k):
    mid = int((s+e)/2)
    if(s>e):
        return -1
    if(arr[mid]==k):
        return mid
    elif (arr[mid]>k):
        e = mid-1
    elif (arr[mid]<k):
        s = mid+1
    return find(arr,s,e,k)

def first_occ(arr,k):
    occ = find(arr,0,len(arr)-1,k)
    while occ >= 0:
        if(arr[occ-1]==k):
            occ -= 1
        else:
            break
    return occ

def last_occ(arr,k):
    occ = find(arr,0,len(arr)-1,k)
    while occ <= len(arr)-1:
        if(arr[occ+1]==k):
            occ += 1
        else:
            return occ

#testing
arr = [1,2,4,10,10,10,10,10,11,12]
print("first occurance : " , end="")
print(first_occ(arr,10))

print("last occurance : " , end="")
print(last_occ(arr,10))
