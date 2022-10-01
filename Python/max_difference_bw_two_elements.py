'''problem statement: Implementation of maximum difference bw two elements in an array such that larger element has higher index than smaller element'''


'''here we'll use the concept of maximum subarray'''

'''good approach'''

 def max_diff_sum(arr):
     diff_arr=[]
     for i in range(len(arr)-1):
         diff_arr.append(arr[i+1]-arr[i])
     current=diff_arr[0]
     for i in range(1,len(diff_arr)):
         if diff_arr[i-1]>0:
             diff_arr[i]+=diff_arr[i-1]
         current=max(current,diff_arr[i])

     return current

 arr=[3,1,4,7,5,100,10]
 print(max_diff_sum(arr))
