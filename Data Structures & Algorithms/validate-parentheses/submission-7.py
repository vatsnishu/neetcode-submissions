class Solution:
    def isValid(self, s: str) -> bool:
        dic1= {')':'(', ']':'[', '}':'{'}
        stack=[]
        for c in s:
            if c not in dic1.keys():
                stack.append(c)
            else:
                if len(stack)==0:
                    return False
                if stack[-1]==dic1[c]:
                    stack.pop(-1)
                else:
                    return False
        
        return True if len(stack)==0 else False 
        
    