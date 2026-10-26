class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        d={}
        for c in s:
            if c in d.keys():
                d[c]+=1
            else:
                d[c]=1


        for c in t:
            if c not in d.keys():
                return False
            d[c]-=1
            if d[c]==0:
                d.pop(c)  
              
        return len(d)==0