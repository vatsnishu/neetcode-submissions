class Solution:
    def isPalindrome(self, s: str) -> bool:
        s=s.lower()
        i=0
        j=len(s)-1
        print
        while(i<=j):
            if not s[i].isalnum():
                i=i+1
                continue
            if not s[j].isalnum():
                j=j-1
                continue
            
            if s[i]==s[j]:
                i=i+1
                j=j-1
            else:
                return False 
        return True
        