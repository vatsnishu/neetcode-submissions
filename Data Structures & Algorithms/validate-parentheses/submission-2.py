class Solution:
    def isValid(self, s: str) -> bool:
        stack=[]
        dic={']':'[', '}':'{',')': '('}
        
        for char in s:
            if char=='{' or char=='(' or char=='[':
                stack.append(char)
            else:
                if len(stack)==0:
                    return False 
                else:
                    if dic[char]==stack[-1]:
                       stack.pop()
                    else:
                        return False 
        return True if len(stack)==0 else False 

