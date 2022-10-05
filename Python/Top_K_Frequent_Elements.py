class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d=dict((Counter(nums)))
        x=sorted(d.values(),reverse=True)
        m=max(d.values())
        ans=[]
        print(d)
        while(k!=0):
            temp=0
            for i in d:
                if d[i]==m:
                    ans.append(i)
                    temp=i
                    break
            del d[temp]
            if len(d)>0:
                m=max(d.values())       
            k-=1
        return ans
