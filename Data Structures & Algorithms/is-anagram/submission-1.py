class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count = {}

        for c in s:
            if c in count:
                count[c]+=1
            else:
                count[c]=1
    
        for c in t:
            if c not in count :
                return False
            
            count[c]-=1
            if count[c]==0:
                count.pop(c)
            
        return not count 