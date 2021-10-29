n=int(input("what is the value of n"))
magic_square=[]
for i in range(n):
    l=[]
    for j in range(n):
        l.append(0)
    magic_square.append(l)

#magic_no={n(n*n+1)}/2
i=n//2
j=n-1
count=1
num=n*n
while(count<=num):
    
    if (i==-1 and j==n):
        i=0
        j=n-2
    else:
        if(j==n):
            j=0
        if(i==-1):
            i=n-1
    if(magic_square[i][j]!=0):
          i=i+1
          j=j-2
          continue
    else:
        magic_square[i][j]=count
    i=i-1
    j=j+1
    count=count+1
    
for i in range(n):
    for j in range (n):
        print(magic_square[i][j]," ",end='')
    print()







